/* industrial-dual-analog-in-v2-bricklet
 * Copyright (C) 2018 Ishraq Ibne Ashraf <ishraq@tinkerforge.com>
 *
 * mcp3911.h: MCP3911 driver
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

#ifndef MCP3911_H
#define MCP3911_H

#include <stdint.h>

#include "configs/config.h"
#include "bricklib2/utility/led_flicker.h"
#include "bricklib2/hal/spi_fifo/spi_fifo.h"

// Register addresses
#define REG_ADDR_CHANNEL_0   0x00
#define REG_ADDR_CHANNEL_1   0x03
#define REG_ADDR_MOD         0x06
#define REG_ADDR_PHASE       0x07
#define REG_ADDR_GAIN        0x09
#define REG_ADDR_STATUSCOM   0x0A
#define REG_ADDR_CONFIG      0x0C
#define REG_ADDR_OFFCAL_CH0  0x0E
#define REG_ADDR_OFFCAL_CH1  0x14
#define REG_ADDR_GAINCAL_CH0 0x11
#define REG_ADDR_GAINCAL_CH1 0x17
#define REG_ADDR_VREFCAL     0x1A

// Configuration masks: STATUSCOM register
#define MSK_STATUSCOM_MODOUT_CH0_ON_CH1_ON            0b1100000000000000
#define MSK_STATUSCOM_MODOUT_CH0_OFF_CH1_ON           0b1000000000000000
#define MSK_STATUSCOM_MODOUT_CH0_ON_CH1_OFF           0b0100000000000000
#define MSK_STATUSCOM_MODOUT_CH0_OFF_CH1_OFF          0b0000000000000000 // Default
#define MSK_STATUSCOM_DR_HIZ_LOGIC_HIGH               0b0001000000000000
#define MSK_STATUSCOM_DR_HIZ_HIGH_IMPEDENCE           0b0000000000000000 // Default
#define MSK_STATUSCOM_DRMODE_CH0_CH1                  0b0000110000000000 // Default
#define MSK_STATUSCOM_DRMODE_CH1                      0b0000100000000000
#define MSK_STATUSCOM_DRMODE_CH0                      0b0000010000000000
#define MSK_STATUSCOM_DRMODE_LAGGING_ADC              0b0000000000000000
#define MSK_STATUSCOM_DRSTATUS_CH0_NRDY_CH1_NRDY      0b0000001100000000 // Default
#define MSK_STATUSCOM_DRSTATUS_CH0_RDY_CH1_NRDY       0b0000001000000000
#define MSK_STATUSCOM_DRSTATUS_CH0_NRDY_CH1_RDY       0b0000000100000000
#define MSK_STATUSCOM_DRSTATUS_CH0_RDY_CH1_RDY        0b0000000000000000
#define MSK_STATUSCOM_READ_LOOP_ENTIRE_REGISTER_SET   0b0000000011000000
#define MSK_STATUSCOM_READ_LOOP_REGISTER_TYPE         0b0000000010000000 // Default
#define MSK_STATUSCOM_READ_LOOP_REGISTER_GROUP        0b0000000001000000
#define MSK_STATUSCOM_READ_LOOP_NONE                  0b0000000000000000
#define MSK_STATUSCOM_WRITE_LOOP_ENTIRE_REGISTER_SET  0b0000000000100000 // Default
#define MSK_STATUSCOM_WRITE_LOOP_NONE                 0b0000000000000000
#define MSK_STATUSCOM_WIDTH_CH0_24_CH1_24             0b0000000000011000 // Default
#define MSK_STATUSCOM_WIDTH_CH0_16_CH1_24             0b0000000000010000
#define MSK_STATUSCOM_WIDTH_CH0_24_CH1_16             0b0000000000001000
#define MSK_STATUSCOM_WIDTH_CH0_16_CH1_16             0b0000000000000000
#define MSK_STATUSCOM_EN_OFFCAL_ENA                   0b0000000000000100 // Default
#define MSK_STATUSCOM_EN_OFFCAL_DIS                   0b0000000000000000
#define MSK_STATUSCOM_EN_GAINCAL_ENA                  0b0000000000000010 // Default
#define MSK_STATUSCOM_EN_GAINCAL_DIS                  0b0000000000000000

// Configuration masks: CONFIG register
#define MSK_CONFIG_AMCLK_MCLK_DIV_8 0b1100000000000000
#define MSK_CONFIG_AMCLK_MCLK_DIV_4 0b1000000000000000
#define MSK_CONFIG_AMCLK_MCLK_DIV_2 0b0100000000000000
#define MSK_CONFIG_AMCLK_MCLK_DIV_1 0b0000000000000000 // Default
#define MSK_CONFIG_OSR_4096         0b0011100000000000 // Default
#define MSK_CONFIG_OSR_2048         0b0011000000000000
#define MSK_CONFIG_OSR_1024         0b0010100000000000
#define MSK_CONFIG_OSR_512          0b0010000000000000
#define MSK_CONFIG_OSR_256          0b0001100000000000
#define MSK_CONFIG_OSR_128          0b0001000000000000
#define MSK_CONFIG_OSR_64           0b0000100000000000
#define MSK_CONFIG_OSR_32           0b0000000000000000
#define MSK_CONFIG_DITHER_MAX       0b0000011000000000 // Default
#define MSK_CONFIG_DITHER_MED       0b0000010000000000
#define MSK_CONFIG_DITHER_MIN       0b0000001000000000
#define MSK_CONFIG_DITHER_OFF       0b0000000000000000
#define MSK_CONFIG_AZ_FREQ_HIGH     0b0000000100000000
#define MSK_CONFIG_AZ_FREQ_LOW      0b0000000000000000 // Default
#define MSK_CONFIG_RESET_BOTH       0b0000000011000000
#define MSK_CONFIG_RESET_CH1        0b0000000010000000
#define MSK_CONFIG_RESET_CH0        0b0000000001000000
#define MSK_CONFIG_RESET_NONE       0b0000000000000000 // Default
#define MSK_CONFIG_SHUTDOWN_BOTH    0b0000000000110000
#define MSK_CONFIG_SHUTDOWN_CH1     0b0000000000100000
#define MSK_CONFIG_SHUTDOWN_CH0     0b0000000000010000
#define MSK_CONFIG_SHUTDOWN_NONE    0b0000000000000000 // Default
#define MSK_CONFIG_VREFEXT_DIS      0b0000000000000100
#define MSK_CONFIG_VREFEXT_ENA      0b0000000000000000 // Default
#define MSK_CONFIG_CLKEXT_MCU       0b0000000000000010
#define MSK_CONFIG_CLKEXT_XTA       0b0000000000000000 // Default

// Sampling rates
#define SAMPLE_RATE_976_SPS 0
#define SAMPLE_RATE_488_SPS 1
#define SAMPLE_RATE_244_SPS 2
#define SAMPLE_RATE_122_SPS 3
#define SAMPLE_RATE_61_SPS  4
#define SAMPLE_RATE_4_SPS   5
#define SAMPLE_RATE_2_SPS   6
#define SAMPLE_RATE_1_SPS   7

// Generate control bytes
#define GET_CTRL_BYTE_R(dev_addr, reg_addr) (((dev_addr) << 6) | ((reg_addr) << 1) | 1)
#define GET_CTRL_BYTE_W(dev_addr, reg_addr) (((dev_addr) << 6) | ((reg_addr) << 1) | 0)

typedef struct {
	int32_t cal_gain;
	int32_t cal_offset;
	int32_t adc_voltage;
	int32_t adc_raw_value;
	int32_t sum_adc_raw_value;
} MCP3911_CHANNEL_t;

typedef struct {
	int32_t min;
	int32_t max;
	uint8_t pin;
	uint8_t config;
	uint8_t config_old;
	uint8_t config_ch_status;
	LEDFlickerState channel_led_flicker_state;
	XMC_GPIO_PORT_t *port;
} CHANNEL_LED_CONFIG_t;

typedef struct {
	uint8_t rate;
	bool rate_new;
	bool calibration_new;
	bool all_voltages_callback_value_has_to_change;

	uint8_t count;
	uint8_t multiplier;
	bool is_version_2_1;

	uint32_t counter;
	SPIFifo spi_fifo;
	MCP3911_CHANNEL_t channels[CALLBACK_VALUE_CHANNEL_NUM];
	CHANNEL_LED_CONFIG_t channel_leds[CALLBACK_VALUE_CHANNEL_NUM];
} MCP3911_t;

extern MCP3911_t mcp3911;

void mcp3911_init(void);
void mcp3911_tick(void);
void mcp3911_set_calibration(void);
void mcp3911_calibration_eeprom_write(void);
int32_t mcp3911_get_voltage(uint8_t channel);

#endif
