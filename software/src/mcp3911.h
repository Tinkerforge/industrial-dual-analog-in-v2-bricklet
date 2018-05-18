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

#include "bricklib2/hal/spi_fifo/spi_fifo.h"

#define MCP3911_REG_ADDR_CHANNEL_CH0 0x00
#define MCP3911_REG_ADDR_CHANNEL_CH1 0x03
#define MCP3911_REG_ADDR_MOD 0x06
#define MCP3911_REG_ADDR_PHASE 0x07
#define MCP3911_REG_ADDR_GAIN 0x09
#define MCP3911_REG_ADDR_STATUSCOM 0x0A
#define MCP3911_REG_ADDR_CONFIG 0x0C
#define MCP3911_REG_ADDR_OFFCAL_CH0 0x0E
#define MCP3911_REG_ADDR_OFFCAL_CH1 0x14
#define MCP3911_REG_ADDR_GAINCAL_CH0 0x11
#define MCP3911_REG_ADDR_GAINCAL_CH2 0x17
#define MCP3911_REG_ADDR_VREFCAL 0x1A

#define GET_CTRL_BYTE_R(dev_a, reg_a) (((dev_a) << 6) | ((reg_a) << 1) | 1)
#define GET_CTRL_BYTE_W(dev_a, reg_a) (((dev_a) << 6) | ((reg_a) << 1) | 0)

#define CONFIG_CONFIG_AMCLK_MASK      0b1100000000000000
#define CONFIG_CONFIG_AMCLK_8         0b1100000000000000
#define CONFIG_CONFIG_AMCLK_4         0b1000000000000000
#define CONFIG_CONFIG_AMCLK_2         0b0100000000000000
#define CONFIG_CONFIG_AMCLK_1         0b0000000000000000 // default
#define CONFIG_CONFIG_OSR_MASK        0b0011100000000000
#define CONFIG_CONFIG_OSR_4096        0b0011100000000000
#define CONFIG_CONFIG_OSR_2048        0b0011000000000000
#define CONFIG_CONFIG_OSR_1024        0b0010100000000000
#define CONFIG_CONFIG_OSR_512         0b0010000000000000
#define CONFIG_CONFIG_OSR_256         0b0001100000000000 // default
#define CONFIG_CONFIG_OSR_128         0b0001000000000000
#define CONFIG_CONFIG_OSR_64          0b0000100000000000
#define CONFIG_CONFIG_OSR_32          0b0000000000000000
#define CONFIG_CONFIG_DITHER_MASK     0b0000011000000000
#define CONFIG_CONFIG_DITHER_MAX      0b0000011000000000 // default
#define CONFIG_CONFIG_DITHER_MED      0b0000010000000000
#define CONFIG_CONFIG_DITHER_MIN      0b0000001000000000
#define CONFIG_CONFIG_DITHER_OFF      0b0000000000000000
#define CONFIG_CONFIG_AZ_FREQ_MASK    0b0000000100000000
#define CONFIG_CONFIG_AZ_FREQ_HIGH    0b0000000100000000
#define CONFIG_CONFIG_AZ_FREQ_LOW     0b0000000000000000 // default
#define CONFIG_CONFIG_RESET_MASK      0b0000000011000000
#define CONFIG_CONFIG_RESET_BOTH      0b0000000011000000
#define CONFIG_CONFIG_RESET_CH1       0b0000000010000000
#define CONFIG_CONFIG_RESET_CH0       0b0000000001000000
#define CONFIG_CONFIG_RESET_NONE      0b0000000000000000 // default
#define CONFIG_CONFIG_SHUTDOWN_MASK   0b0000000000110000
#define CONFIG_CONFIG_SHUTDOWN_BOTH   0b0000000000110000
#define CONFIG_CONFIG_SHUTDOWN_CH1    0b0000000000100000
#define CONFIG_CONFIG_SHUTDOWN_CH0    0b0000000000010000
#define CONFIG_CONFIG_SHUTDOWN_NONE   0b0000000000000000 // default
#define CONFIG_CONFIG_VREFINT_MASK    0b0000000000000100
#define CONFIG_CONFIG_VREFINT_DIS     0b0000000000000100 // default
#define CONFIG_CONFIG_VREFINT_EN      0b0000000000000000
#define CONFIG_CONFIG_CLKEXT_MASK     0b0000000000000010
#define CONFIG_CONFIG_CLKEXT_MCU      0b0000000000000010 // default
#define CONFIG_CONFIG_CLKEXT_CRYSTAL  0b0000000000000000

typedef struct {
	SPIFifo spi_fifo;
	uint8_t spi_fifo_buf[16];
} MCP3911_t;

extern MCP3911_t mcp3911;

void mcp3911_init(void);
void mcp3911_tick(void);
int32_t mcp3911_get_voltage(uint8_t channel);

#endif
