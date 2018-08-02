/* industrial-dual-analog-in-v2-bricklet
 * Copyright (C) 2018 Ishraq Ibne Ashraf <ishraq@tinkerforge.com>
 *
 * mcp3911.c: MCP3911 driver
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "mcp3911.h"

#include "configs/config_mcp3911.h"

#include "bricklib2/logging/logging.h"
#include "bricklib2/hal/ccu4_pwm/ccu4_pwm.h"
#include "bricklib2/hal/system_timer/system_timer.h"

#include "communication.h"

MCP3911_t mcp3911;

const XMC_GPIO_CONFIG_t channel_led_gpio_config = {
	.mode         = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
	.output_level = XMC_GPIO_OUTPUT_LEVEL_HIGH,
};

const XMC_GPIO_CONFIG_t channel_led_pwm_config	= {
	.mode             = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT2,
	.input_hysteresis = XMC_GPIO_INPUT_HYSTERESIS_STANDARD,
	.output_level     = XMC_GPIO_OUTPUT_LEVEL_LOW,
};

static void mcp3911_register_rw(uint8_t control_byte, uint8_t *data, uint8_t data_length) {
	mcp3911.spi_fifo_buf[0] = control_byte;

	for (uint8_t i = 0; i < data_length; i++) {
		mcp3911.spi_fifo_buf[i + 1] = data[i];
	}

	XMC_USIC_CH_RXFIFO_Flush(mcp3911.spi_fifo.channel);
	spi_fifo_transceive(&mcp3911.spi_fifo, data_length + 1, &mcp3911.spi_fifo_buf[0]);
}

static void mcp3911_calibration_eeprom_read(void) {
	uint32_t page[EEPROM_PAGE_SIZE/sizeof(uint32_t)];

	bootloader_read_eeprom_page(MCP3911_CALIBRATION_PAGE, page);

	/*
	 * The magic number is not where it is supposed to be.
	 *
	 * This is either our first startup or something went wrong.
	 * We initialize the calibration data with sane default values.
	 */
	if(page[0] != MCP3911_CALIBRATION_MAGIC) {
		for (uint8_t i = 0; i < CALLBACK_VALUE_CHANNEL_NUM; i++) {
			mcp3911.channels[i].cal_gain = 0;
			mcp3911.channels[i].cal_offset = 0;
		}

		mcp3911_calibration_eeprom_write();

		return;
	}

	for (uint8_t i = 0; i < CALLBACK_VALUE_CHANNEL_NUM; i++) {
		mcp3911.channels[i].cal_gain = page[MCP3911_CALIBRATION_GAIN_POS + i];
		mcp3911.channels[i].cal_offset = page[MCP3911_CALIBRATION_OFFSET_POS + i];
	}
}

void mcp3911_init(void) {
	logd("[+] mcp3911_init()\n\r");

	uint8_t data[4];
	uint16_t val_status = 0;
	uint16_t val_config = 0;

	mcp3911.spi_fifo.channel = MCP3911_USIC_SPI;
	mcp3911.spi_fifo.baudrate = MCP3911_SPI_BAUDRATE;

	mcp3911.spi_fifo.rx_fifo_size = MCP3911_RX_FIFO_SIZE;
	mcp3911.spi_fifo.rx_fifo_pointer = MCP3911_RX_FIFO_POINTER;
	mcp3911.spi_fifo.tx_fifo_size = MCP3911_TX_FIFO_SIZE;
	mcp3911.spi_fifo.tx_fifo_pointer = MCP3911_TX_FIFO_POINTER;

	mcp3911.spi_fifo.slave = MCP3911_SLAVE;
	mcp3911.spi_fifo.clock_output = MCP3911_CLOCK_OUTPUT;
	mcp3911.spi_fifo.clock_passive_level = MCP3911_CLOCK_PASSIVE_LEVEL;

	mcp3911.spi_fifo.sclk_pin = MCP3911_SCLK_PIN;
	mcp3911.spi_fifo.sclk_port = MCP3911_SCLK_PORT;
	mcp3911.spi_fifo.sclk_pin_mode = MCP3911_SCLK_PIN_MODE;

	mcp3911.spi_fifo.select_pin = MCP3911_SELECT_PIN;
	mcp3911.spi_fifo.select_port = MCP3911_SELECT_PORT;
	mcp3911.spi_fifo.select_pin_mode = MCP3911_SELECT_PIN_MODE;

	mcp3911.spi_fifo.mosi_pin = MCP3911_MOSI_PIN;
	mcp3911.spi_fifo.mosi_port = MCP3911_MOSI_PORT;
	mcp3911.spi_fifo.mosi_pin_mode = MCP3911_MOSI_PIN_MODE;

	mcp3911.spi_fifo.miso_pin = MCP3911_MISO_PIN;
	mcp3911.spi_fifo.miso_port = MCP3911_MISO_PORT;
	mcp3911.spi_fifo.miso_input = MCP3911_MISO_INPUT;
	mcp3911.spi_fifo.miso_source = MCP3911_MISO_SOURCE;

	spi_fifo_init(&mcp3911.spi_fifo);

	for (uint8_t i = 0; i < CALLBACK_VALUE_CHANNEL_NUM; i++) {
		// Init channel values
		mcp3911.channels[i].adc_voltage = 0;
		mcp3911.channels[i].adc_raw_value = 0;
		mcp3911.channels[i].sum_adc_raw_value = 0;

		// Init channel LEDs
		mcp3911.channel_leds[i].pin = i;
		mcp3911.channel_leds[i].port = (XMC_GPIO_PORT_t *)PORT1_BASE;

		mcp3911.channel_leds[i].channel_led_flicker_state.config = LED_FLICKER_CONFIG_OFF;
		mcp3911.channel_leds[i].config = INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_SHOW_CHANNEL_STATUS;
		mcp3911.channel_leds[i].config_old = INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_SHOW_CHANNEL_STATUS;

		mcp3911.channel_leds[i].min = 9000;
		mcp3911.channel_leds[i].max = 18000;
		mcp3911.channel_leds[i].config_ch_status = INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_STATUS_CONFIG_INTENSITY;

		XMC_GPIO_Init(mcp3911.channel_leds[i].port, mcp3911.channel_leds[i].pin, &channel_led_pwm_config);

		// PWM frequency = Core clock / 100
		ccu4_pwm_init(mcp3911.channel_leds[i].port, mcp3911.channel_leds[i].pin, i, 100);
		ccu4_pwm_set_duty_cycle(i, 0);
	}

	mcp3911.config = 0;
	mcp3911.count = 122;
	mcp3911.counter = 0;
	mcp3911.multiplier = 2;
	mcp3911.rate = SAMPLE_RATE_2_SPS;
	mcp3911.rate_old = SAMPLE_RATE_2_SPS;

	// Set initial status/config
	val_status = (uint16_t)(MSK_STATUSCOM_MODOUT_CH0_OFF_CH1_OFF |
	                        MSK_STATUSCOM_DR_HIZ_HIGH_IMPEDENCE |
	                        MSK_STATUSCOM_DRMODE_CH0_CH1 |
	                        MSK_STATUSCOM_DRSTATUS_CH0_NRDY_CH1_NRDY |
	                        MSK_STATUSCOM_READ_LOOP_REGISTER_TYPE |
	                        MSK_STATUSCOM_WRITE_LOOP_ENTIRE_REGISTER_SET |
	                        MSK_STATUSCOM_WIDTH_CH0_24_CH1_24 |
	                        MSK_STATUSCOM_EN_OFFCAL_ENA |
	                        MSK_STATUSCOM_EN_GAINCAL_ENA);

	val_config = (uint16_t)(MSK_CONFIG_AMCLK_MCLK_DIV_1 |
	                        MSK_CONFIG_OSR_4096 |
	                        MSK_CONFIG_DITHER_MAX |
	                        MSK_CONFIG_AZ_FREQ_LOW |
	                        MSK_CONFIG_RESET_NONE |
	                        MSK_CONFIG_SHUTDOWN_NONE |
	                        MSK_CONFIG_VREFEXT_ENA |
	                        MSK_CONFIG_CLKEXT_XTA);

	data[0] = (uint8_t)(val_status >> 8);
	data[1] = (uint8_t)(val_status);
	data[2] = (uint8_t)(val_config >> 8);
	data[3] = (uint8_t)(val_config);

	mcp3911_register_rw((uint8_t)GET_CTRL_BYTE_W(0x00, REG_ADDR_STATUSCOM), data, 4);

	mcp3911_calibration_eeprom_read();

	mcp3911.sm = S_SET_CAL;
}

void mcp3911_tick(void) {
	uint8_t data[6];
	uint16_t status = 0;

	SPIFifoState fifo_state = spi_fifo_next_state(&mcp3911.spi_fifo);

	if(fifo_state & SPI_FIFO_STATE_ERROR) {
		mcp3911_init();

		return;
	}

	if(fifo_state == SPI_FIFO_STATE_TRANSCEIVE_READY) {
		switch(mcp3911.sm) {
			case S_SET_CAL:
				mcp3911_set_calibration();

				mcp3911.sm = S_GET_STATUS;

				break;

			case S_GET_STATUS:
				spi_fifo_read_fifo(&mcp3911.spi_fifo, &mcp3911.spi_fifo_buf[0], 3);
				status = (uint16_t)((mcp3911.spi_fifo_buf[1] << 8) | mcp3911.spi_fifo_buf[2]);

				if(!(status & (1 << 8)) && !(status & (1 << 9))) {
					mcp3911_register_rw((uint8_t)GET_CTRL_BYTE_R(0x00, REG_ADDR_CHANNEL_0), data, 6);

					mcp3911.sm = S_GET_ADC;
				}
				else {
					mcp3911_register_rw((uint8_t)GET_CTRL_BYTE_R(0x00, REG_ADDR_STATUSCOM), data, 2);

					mcp3911.sm = S_GET_STATUS;
				}

				break;

			case S_GET_ADC:
				mcp3911.counter++;

				if(mcp3911.counter >= mcp3911.count) {
					mcp3911.counter = 0;
				}

				spi_fifo_read_fifo(&mcp3911.spi_fifo, &mcp3911.spi_fifo_buf[0], 7);

				for (uint8_t i = 0; i < CALLBACK_VALUE_CHANNEL_NUM; i++) {
					// Get ADC raw value
					if (i == 0) {
						mcp3911.channels[i].adc_raw_value = \
							(mcp3911.spi_fifo_buf[4] << 16) | (mcp3911.spi_fifo_buf[5] << 8) | mcp3911.spi_fifo_buf[6];
					}
					else {
						mcp3911.channels[i].adc_raw_value = \
							(int32_t)(mcp3911.spi_fifo_buf[1] << 16) | (mcp3911.spi_fifo_buf[2] << 8) | mcp3911.spi_fifo_buf[3];
					}

					if(mcp3911.channels[i].adc_raw_value & 0x800000) {
						mcp3911.channels[i].adc_raw_value |= 0xFF000000;
					}

					// Calculate voltage from ADC raw value
					mcp3911.channels[i].sum_adc_raw_value += mcp3911.channels[i].adc_raw_value;

					if (mcp3911.counter == 0) {
						mcp3911.channels[i].adc_voltage = \
							(mcp3911.channels[i].sum_adc_raw_value * mcp3911.multiplier) / 44983;
						mcp3911.channels[i].sum_adc_raw_value = 0;
					}
				}

				if (mcp3911.rate != mcp3911.rate_old) {
					mcp3911_register_rw((uint8_t)GET_CTRL_BYTE_R(0x00, REG_ADDR_CONFIG), data, 2);

					mcp3911.sm = S_SET_RATE_R;
				}
				else {
					mcp3911_register_rw((uint8_t)GET_CTRL_BYTE_R(0x00, REG_ADDR_STATUSCOM), data, 2);

					mcp3911.sm = S_GET_STATUS;
				}

				break;

			case S_SET_RATE_R:
				spi_fifo_read_fifo(&mcp3911.spi_fifo, &mcp3911.spi_fifo_buf[0], 3);

				mcp3911.config = (uint16_t)(mcp3911.spi_fifo_buf[1] << 8) | mcp3911.spi_fifo_buf[2];

				switch(mcp3911.rate) {
					case SAMPLE_RATE_976_SPS:
						mcp3911.config |= MSK_CONFIG_OSR_1024;

						break;

					case SAMPLE_RATE_488_SPS:
						mcp3911.config |= MSK_CONFIG_OSR_2048;

						break;

					case SAMPLE_RATE_244_SPS:
					default:
						mcp3911.config |= MSK_CONFIG_OSR_4096;

						break;
				}

				mcp3911.sm = S_SET_RATE_W;

				break;

			case S_SET_RATE_W:
				data[0] = (uint8_t)(mcp3911.config >> 8);
				data[1] = (uint8_t)(mcp3911.config);

				mcp3911_register_rw((uint8_t)GET_CTRL_BYTE_W(0x00, REG_ADDR_CONFIG), data, 2);

				mcp3911.sm = S_SET_RATE_W_DONE;

				break;

			case S_SET_RATE_W_DONE:
				switch(mcp3911.rate) {
					case SAMPLE_RATE_122_SPS:
						mcp3911.count = 2;
						mcp3911.multiplier = 122;

						break;

					case SAMPLE_RATE_61_SPS:
						mcp3911.count = 4;
						mcp3911.multiplier = 61;

						break;

					case SAMPLE_RATE_4_SPS:
						mcp3911.count = 61;
						mcp3911.multiplier = 4;

						break;

					case SAMPLE_RATE_2_SPS:
						mcp3911.multiplier = 2;
						mcp3911.count = 122;

						break;

					case SAMPLE_RATE_1_SPS:
						mcp3911.multiplier = 1;
						mcp3911.count = 244;

						break;

					default:
						mcp3911.multiplier = 244;
						mcp3911.count = 1;

						break;
				}

				mcp3911.rate_old = mcp3911.rate;

				mcp3911_register_rw((uint8_t)GET_CTRL_BYTE_R(0x00, REG_ADDR_STATUSCOM), data, 2);

				mcp3911.sm = S_GET_STATUS;

			default:
				break;
		}
	}

	// Manage channel LEDs
	for(uint8_t i = 0; i < CALLBACK_VALUE_CHANNEL_NUM; i++) {
		if (mcp3911.channel_leds[i].config_old != mcp3911.channel_leds[i].config) {
			// Other -> Show Channel Status
			if (mcp3911.channel_leds[i].config == INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_SHOW_CHANNEL_STATUS) {
				XMC_GPIO_Init(mcp3911.channel_leds[i].port, mcp3911.channel_leds[i].pin, &channel_led_pwm_config);
				ccu4_pwm_init(mcp3911.channel_leds[i].port, mcp3911.channel_leds[i].pin, i, 100);
			}
			// Show Channel Status -> Other
			else if (mcp3911.channel_leds[i].config_old == INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_SHOW_CHANNEL_STATUS) {
				XMC_GPIO_Init(mcp3911.channel_leds[i].port, mcp3911.channel_leds[i].pin, &channel_led_gpio_config);
			}

			mcp3911.channel_leds[i].config_old = mcp3911.channel_leds[i].config;
		}

		switch (mcp3911.channel_leds[i].config) {
			case INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_OFF:
				mcp3911.channel_leds[i].channel_led_flicker_state.config = LED_FLICKER_CONFIG_OFF;
				XMC_GPIO_SetOutputHigh(mcp3911.channel_leds[i].port, mcp3911.channel_leds[i].pin);

				break;

			case INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_ON:
				mcp3911.channel_leds[i].channel_led_flicker_state.config = LED_FLICKER_CONFIG_ON;
				XMC_GPIO_SetOutputLow(mcp3911.channel_leds[i].port, mcp3911.channel_leds[i].pin);

				break;

			case INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_SHOW_HEARTBEAT:
				mcp3911.channel_leds[i].channel_led_flicker_state.config = LED_FLICKER_CONFIG_HEARTBEAT;

				led_flicker_tick(&mcp3911.channel_leds[i].channel_led_flicker_state,
								 system_timer_get_ms(),
								 mcp3911.channel_leds[i].port,
								 mcp3911.channel_leds[i].pin);

				break;

			case INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_SHOW_CHANNEL_STATUS:
				mcp3911.channel_leds[i].channel_led_flicker_state.config = LED_FLICKER_CONFIG_OFF;

				if (mcp3911.channel_leds[i].config_ch_status == INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_STATUS_CONFIG_THRESHOLD) {
					if ((mcp3911.channel_leds[i].min == 0) && (mcp3911.channel_leds[i].max != 0)) {
						if (mcp3911.channels[i].adc_voltage < mcp3911.channel_leds[i].max) {
							ccu4_pwm_set_duty_cycle(i, 100);
						}
						else {
							ccu4_pwm_set_duty_cycle(i, 0);
						}
					}
					else {
						if (mcp3911.channels[i].adc_voltage > mcp3911.channel_leds[i].min) {
							ccu4_pwm_set_duty_cycle(i, 100);
						}
						else {
							ccu4_pwm_set_duty_cycle(i, 0);
						}
					}
				}
				else if (mcp3911.channel_leds[i].config_ch_status == INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_STATUS_CONFIG_INTENSITY) {
					if (mcp3911.channel_leds[i].min > mcp3911.channel_leds[i].max) {
						if (mcp3911.channels[i].adc_voltage > mcp3911.channel_leds[i].min) {
							ccu4_pwm_set_duty_cycle(i, 0);
						}
						else if (mcp3911.channels[i].adc_voltage < mcp3911.channel_leds[i].max) {
							ccu4_pwm_set_duty_cycle(i, 100);
						}
						else {
							int32_t range = mcp3911.channel_leds[i].min - mcp3911.channel_leds[i].max;
							int32_t scaled_channel_voltage = mcp3911.channels[i].adc_voltage - mcp3911.channel_leds[i].max;
							int32_t pwm_dc = (scaled_channel_voltage * 100) / range;
							ccu4_pwm_set_duty_cycle(i, (uint16_t)(100 - pwm_dc));
						}
					}
					else {
						if (mcp3911.channels[i].adc_voltage > mcp3911.channel_leds[i].max) {
							ccu4_pwm_set_duty_cycle(i, 100);
						}
						else if (mcp3911.channels[i].adc_voltage < mcp3911.channel_leds[i].min) {
							ccu4_pwm_set_duty_cycle(i, 0);
						}
						else {
							int32_t range = mcp3911.channel_leds[i].max - mcp3911.channel_leds[i].min;
							int32_t scaled_channel_voltage = mcp3911.channels[i].adc_voltage  - mcp3911.channel_leds[i].min;
							int32_t pwm_dc = (scaled_channel_voltage * 100) / range;
							ccu4_pwm_set_duty_cycle(i, (uint16_t)pwm_dc);
						}
					}
				}

				break;

			default:
				break;
		}
	}
}

void mcp3911_set_calibration(void) {
	uint8_t cal_data[12];
	int32_t cal_offset_tmp = 0;

	for (uint8_t i = 0; i < CALLBACK_VALUE_CHANNEL_NUM; i++) {
		cal_offset_tmp = mcp3911.channels[1-i].cal_offset;

		if(cal_offset_tmp & 0x80000000) {
			cal_offset_tmp |= 0x800000;
		}

		cal_data[0 + (i * 6)] = (cal_offset_tmp >> 16) & 0xFF;
		cal_data[1 + (i * 6)] = (cal_offset_tmp >> 8) & 0xFF;
		cal_data[2 + (i * 6)] = (cal_offset_tmp >> 0) & 0xFF;
		cal_data[3 + (i * 6)] = (mcp3911.channels[1-i].cal_gain >> 16) & 0xFF;
		cal_data[4 + (i * 6)] = (mcp3911.channels[1-i].cal_gain >> 8) & 0xFF;
		cal_data[5 + (i * 6)] = (mcp3911.channels[1-i].cal_gain >> 0) & 0xFF;
	}

	// Write offset and gain for both channels
	mcp3911_register_rw((uint8_t)GET_CTRL_BYTE_W(0x00, REG_ADDR_OFFCAL_CH0), cal_data, 12);
}

void mcp3911_calibration_eeprom_write(void) {
	uint32_t page[EEPROM_PAGE_SIZE/sizeof(uint32_t)];

	page[MCP3911_CALIBRATION_MAGIC_POS] = MCP3911_CALIBRATION_MAGIC;

	for (uint8_t i = 0; i < CALLBACK_VALUE_CHANNEL_NUM; i++) {
		page[MCP3911_CALIBRATION_GAIN_POS + i] = mcp3911.channels[i].cal_gain;
		page[MCP3911_CALIBRATION_OFFSET_POS + i] = mcp3911.channels[i].cal_offset;
	}

	bootloader_write_eeprom_page(MCP3911_CALIBRATION_PAGE, page);
}

int32_t mcp3911_get_voltage(uint8_t channel) {
	return mcp3911.channels[channel].adc_voltage;
}
