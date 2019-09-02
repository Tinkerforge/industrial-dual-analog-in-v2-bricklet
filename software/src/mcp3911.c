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

#include "bricklib2/utility/util_definitions.h"
#include "bricklib2/logging/logging.h"
#include "bricklib2/hal/ccu4_pwm/ccu4_pwm.h"
#include "bricklib2/hal/system_timer/system_timer.h"
#include "bricklib2/os/coop_task.h"

#include "communication.h"

#define MCP3911_DEFAULT_VALUE_STATUS \
	(MSK_STATUSCOM_MODOUT_CH0_OFF_CH1_OFF | \
	MSK_STATUSCOM_DR_HIZ_HIGH_IMPEDENCE | \
	MSK_STATUSCOM_DRMODE_CH0_CH1 | \
	MSK_STATUSCOM_DRSTATUS_CH0_NRDY_CH1_NRDY | \
	MSK_STATUSCOM_READ_LOOP_REGISTER_TYPE | \
	MSK_STATUSCOM_WRITE_LOOP_ENTIRE_REGISTER_SET | \
	MSK_STATUSCOM_WIDTH_CH0_24_CH1_24 | \
	MSK_STATUSCOM_EN_OFFCAL_ENA | \
	MSK_STATUSCOM_EN_GAINCAL_ENA)

#define MCP3911_DEFAULT_VALUE_CONFIG \
	(MSK_CONFIG_DITHER_MAX | \
	MSK_CONFIG_AZ_FREQ_LOW | \
	MSK_CONFIG_RESET_NONE | \
	MSK_CONFIG_SHUTDOWN_NONE | \
	MSK_CONFIG_VREFEXT_ENA | \
	MSK_CONFIG_CLKEXT_XTA)

CoopTask mcp3911_task;
MCP3911_t mcp3911;

const uint8_t counts[] = {1, 1, 1, 2, 4, 61, 122, 244};
const uint8_t multipliers[] = {244, 244, 244, 122, 61, 4, 2, 1};

const XMC_GPIO_CONFIG_t channel_led_gpio_config = {
	.mode         = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
	.output_level = XMC_GPIO_OUTPUT_LEVEL_HIGH,
};

const XMC_GPIO_CONFIG_t channel_led_pwm_config	= {
	.mode             = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT2,
	.input_hysteresis = XMC_GPIO_INPUT_HYSTERESIS_STANDARD,
	.output_level     = XMC_GPIO_OUTPUT_LEVEL_LOW,
};


static void mcp3911_init_spi(void) {
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
}

static void mcp3911_register_read(const uint8_t reg, uint8_t *data, uint8_t data_length) {
	uint8_t tmp[16] = {0};
	tmp[0] = GET_CTRL_BYTE_R(0x00, reg);
	if(!spi_fifo_coop_transceive(&mcp3911.spi_fifo, data_length + 1, tmp, tmp)) {
		mcp3911_init_spi();
	}
	memcpy(data, &tmp[1], data_length);
}

static void mcp3911_register_write(const uint8_t reg, const uint8_t *data, uint8_t data_length) {
	uint8_t tmp[16] = {0};
	tmp[0] = GET_CTRL_BYTE_W(0x00, reg);
	memcpy(&tmp[1], data, data_length);
	if(!spi_fifo_coop_transceive(&mcp3911.spi_fifo, data_length + 1, tmp, tmp)) {
		mcp3911_init_spi();
	}
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

void mcp3911_task_reset(void) {
	uint8_t config[2] = {
		(uint8_t)((MCP3911_DEFAULT_VALUE_CONFIG | MSK_CONFIG_RESET_BOTH) >> 8),
		(uint8_t)(MCP3911_DEFAULT_VALUE_CONFIG | MSK_CONFIG_RESET_BOTH)
	};
	mcp3911_register_write(REG_ADDR_CONFIG, config, 2);	
}

void mcp3911_task_new_data_rate(void) {
	uint16_t config = MCP3911_DEFAULT_VALUE_CONFIG;

	const uint32_t mclk_div = mcp3911.is_version_2_1 ? MSK_CONFIG_AMCLK_MCLK_DIV_1 : MSK_CONFIG_AMCLK_MCLK_DIV_2;

	switch(mcp3911.rate) {
		case SAMPLE_RATE_976_SPS:
			config |= MSK_CONFIG_OSR_1024;
			config |= mclk_div;

			break;

		case SAMPLE_RATE_488_SPS:
			config |= MSK_CONFIG_OSR_2048;
			config |= mclk_div;

			break;

		case SAMPLE_RATE_244_SPS:
		default:
			config |= MSK_CONFIG_OSR_4096;
			config |= mclk_div;

			break;
	}

	mcp3911.rate       = MIN(SAMPLE_RATE_1_SPS, mcp3911.rate);
	mcp3911.count      = counts[mcp3911.rate];
	mcp3911.multiplier = counts[mcp3911.rate];

	mcp3911.channels[0].sum_adc_raw_value = 0;
	mcp3911.channels[1].sum_adc_raw_value = 0;
	mcp3911.counter = 0;

	mcp3911_task_reset();
	coop_task_sleep_ms(10);

	uint8_t data[2] = {(uint8_t)(config >> 8), (uint8_t)(config)};
	mcp3911_register_write(REG_ADDR_CONFIG, data, 2);


	uint8_t status[2] = {
		(uint8_t)(MCP3911_DEFAULT_VALUE_STATUS >> 8),
		(uint8_t)(MCP3911_DEFAULT_VALUE_STATUS)
	};
	mcp3911_register_write(REG_ADDR_STATUSCOM, status, 2);

	coop_task_sleep_ms(100);
}

void mcp3911_task_read_adc(void) {
	uint8_t data[6] = {0};
	mcp3911_register_read(REG_ADDR_STATUSCOM, data, 2);
	uint16_t status = (data[0] << 8) | data[1];
	if(!(status & (1 << 8)) && !(status & (1 << 9))) {
		mcp3911_register_read(REG_ADDR_CHANNEL_0, data, 6);
		
		// In case of invalid data we re-configure the ADC 
		// (done through setting new sampling rate)
		if((data[0] == 0x80) && (data[1] == 0x00) && (data[2] == 0x00) && (data[3] == 0x80) && (data[4] == 0x00) && (data[5] == 0x00)) {
			mcp3911.rate_new = true;
			return;
		}

		mcp3911.counter++;
		if(mcp3911.counter >= mcp3911.count) {
			mcp3911.counter = 0;
		}

		// Get ADC raw value
		mcp3911.channels[0].adc_raw_value = (data[3] << 16) | (data[4] << 8) | data[5];
		mcp3911.channels[1].adc_raw_value = (data[0] << 16) | (data[1] << 8) | data[2];

		for (uint8_t i = 0; i < CALLBACK_VALUE_CHANNEL_NUM; i++) {
			if(mcp3911.channels[i].adc_raw_value & 0x800000) {
				mcp3911.channels[i].adc_raw_value |= 0xFF000000;
			}

			// Calculate voltage from ADC raw value
			mcp3911.channels[i].sum_adc_raw_value += mcp3911.channels[i].adc_raw_value;

			if(mcp3911.counter == 0) {
				mcp3911.channels[i].adc_voltage = (mcp3911.channels[i].sum_adc_raw_value * mcp3911.multiplier) / 44983;
				mcp3911.channels[i].sum_adc_raw_value = 0;
			}
		}
	}
}

void mcp3911_task_tick(void) {
	const XMC_GPIO_CONFIG_t version_config = {
		.mode         = XMC_GPIO_MODE_INPUT_PULL_UP,
		.output_level = XMC_GPIO_OUTPUT_LEVEL_HIGH,
	};

	XMC_GPIO_Init(MCP3911_VERSION_PORT, MCP3911_VERSION_PIN, &version_config);

	coop_task_sleep_ms(10);
	mcp3911_task_reset();
	coop_task_sleep_ms(10);
	mcp3911_set_calibration();
	coop_task_sleep_ms(10);

	mcp3911.is_version_2_1 = !XMC_GPIO_GetInput(MCP3911_VERSION_PORT, MCP3911_VERSION_PIN);

	uint8_t config[2] = {
		(uint8_t)((MCP3911_DEFAULT_VALUE_CONFIG | MSK_CONFIG_AMCLK_MCLK_DIV_2 | MSK_CONFIG_OSR_4096) >> 8),
		(uint8_t)(MCP3911_DEFAULT_VALUE_CONFIG | MSK_CONFIG_AMCLK_MCLK_DIV_2 | MSK_CONFIG_OSR_4096)
	};
	mcp3911_register_write(REG_ADDR_CONFIG, config, 2);

	uint8_t status[2] = {
		(uint8_t)(MCP3911_DEFAULT_VALUE_STATUS >> 8),
		(uint8_t)(MCP3911_DEFAULT_VALUE_STATUS)
	};
	mcp3911_register_write(REG_ADDR_STATUSCOM, status, 2);


	while(true) {
		if(mcp3911.rate_new) {
			mcp3911_task_new_data_rate();
			mcp3911.rate_new = false;
		}

		if(mcp3911.calibration_new) {
			mcp3911_set_calibration();
			mcp3911_calibration_eeprom_write();
			mcp3911.calibration_new = false;
		}

		mcp3911_task_read_adc();

		coop_task_yield();
	}
}

void mcp3911_init(void) {
	mcp3911_init_spi();

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

	mcp3911.count = 122;
	mcp3911.counter = 0;
	mcp3911.multiplier = 2;
	mcp3911.rate = SAMPLE_RATE_2_SPS;
	mcp3911.rate_new = true;

	mcp3911_calibration_eeprom_read();

	coop_task_init(&mcp3911_task, mcp3911_task_tick);
}

void mcp3911_handle_leds(void) {
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

void mcp3911_tick(void) {
	coop_task_tick(&mcp3911_task);
	mcp3911_handle_leds();
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
	mcp3911_register_write(REG_ADDR_OFFCAL_CH0, cal_data, 12);
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
