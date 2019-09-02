/* industrial-dual-analog-in-v2-bricklet
 * Copyright (C) 2018 Ishraq Ibne Ashraf <ishraq@tinkerforge.com>
 *
 * config_mcp3911.h: Config for MCP3911
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

#ifndef CONFIG_MCP3911_H
#define CONFIG_MCP3911_H

#include "xmc_gpio.h"
#include "xmc_spi.h"

#define MCP3911_SPI_BAUDRATE           200000
#define MCP3911_USIC_CHANNEL           USIC0_CH0
#define MCP3911_USIC_SPI               XMC_SPI0_CH0

#define MCP3911_RX_FIFO_SIZE           XMC_USIC_CH_FIFO_SIZE_16WORDS
#define MCP3911_RX_FIFO_POINTER        32
#define MCP3911_TX_FIFO_SIZE           XMC_USIC_CH_FIFO_SIZE_16WORDS
#define MCP3911_TX_FIFO_POINTER        48

#define MCP3911_CLOCK_PASSIVE_LEVEL    XMC_SPI_CH_BRG_SHIFT_CLOCK_PASSIVE_LEVEL_0_DELAY_ENABLED
#define MCP3911_CLOCK_OUTPUT           XMC_SPI_CH_BRG_SHIFT_CLOCK_OUTPUT_SCLK
#define MCP3911_SLAVE                  XMC_SPI_CH_SLAVE_SELECT_4

#define MCP3911_SCLK_PORT              XMC_GPIO_PORT0
#define MCP3911_SCLK_PIN               14
#define MCP3911_SCLK_PIN_MODE          (XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT7 | P0_14_AF_U0C0_SCLKOUT)

#define MCP3911_SELECT_PORT            XMC_GPIO_PORT0
#define MCP3911_SELECT_PIN             13
#define MCP3911_SELECT_PIN_MODE        (XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT6 | P0_13_AF_U0C0_SELO4)

#define MCP3911_MOSI_PORT              XMC_GPIO_PORT2
#define MCP3911_MOSI_PIN               0
#define MCP3911_MOSI_PIN_MODE          (XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT6 | P2_0_AF_U0C0_DOUT0)

#define MCP3911_MISO_PORT              XMC_GPIO_PORT0
#define MCP3911_MISO_PIN               15
#define MCP3911_MISO_INPUT             XMC_USIC_CH_INPUT_DX0
#define MCP3911_MISO_SOURCE            0b001 // DX0B

#define MCP3911_CALIBRATION_PAGE       1
#define MCP3911_CALIBRATION_MAGIC_POS  0
#define MCP3911_CALIBRATION_OFFSET_POS 1
#define MCP3911_CALIBRATION_GAIN_POS   3
#define MCP3911_CALIBRATION_MAGIC      0x12345678

#define MCP3911_VERSION_PORT           XMC_GPIO_PORT2
#define MCP3911_VERSION_PIN            2

#endif