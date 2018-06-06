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
#include "bricklib2/hal/system_timer/system_timer.h"
#include "bricklib2/logging/logging.h"

#include "communication.h"

uint32_t ticker = 0;
MCP3911_t mcp3911;

void mcp3911_init(void) {
	logd("[+] mcp3911_init()\n\r");
	mcp3911.spi_fifo.baudrate = MCP3911_SPI_BAUDRATE;
	mcp3911.spi_fifo.channel = MCP3911_USIC_SPI;

	mcp3911.spi_fifo.rx_fifo_size = MCP3911_RX_FIFO_SIZE;
	mcp3911.spi_fifo.rx_fifo_pointer = MCP3911_RX_FIFO_POINTER;
	mcp3911.spi_fifo.tx_fifo_size = MCP3911_TX_FIFO_SIZE;
	mcp3911.spi_fifo.tx_fifo_pointer = MCP3911_TX_FIFO_POINTER;

	mcp3911.spi_fifo.clock_passive_level = MCP3911_CLOCK_PASSIVE_LEVEL;
	mcp3911.spi_fifo.clock_output = MCP3911_CLOCK_OUTPUT;
	mcp3911.spi_fifo.slave = MCP3911_SLAVE;

	mcp3911.spi_fifo.sclk_port = MCP3911_SCLK_PORT;
	mcp3911.spi_fifo.sclk_pin = MCP3911_SCLK_PIN;
	mcp3911.spi_fifo.sclk_pin_mode = MCP3911_SCLK_PIN_MODE;

	mcp3911.spi_fifo.select_port = MCP3911_SELECT_PORT;
	mcp3911.spi_fifo.select_pin = MCP3911_SELECT_PIN;
	mcp3911.spi_fifo.select_pin_mode = MCP3911_SELECT_PIN_MODE;

	mcp3911.spi_fifo.mosi_port = MCP3911_MOSI_PORT;
	mcp3911.spi_fifo.mosi_pin = MCP3911_MOSI_PIN;
	mcp3911.spi_fifo.mosi_pin_mode = MCP3911_MOSI_PIN_MODE;

	mcp3911.spi_fifo.miso_port = MCP3911_MISO_PORT;
	mcp3911.spi_fifo.miso_pin = MCP3911_MISO_PIN;
	mcp3911.spi_fifo.miso_input = MCP3911_MISO_INPUT;
	mcp3911.spi_fifo.miso_source = MCP3911_MISO_SOURCE;

	spi_fifo_init(&mcp3911.spi_fifo);
	system_timer_sleep_ms(8);

	// SELECT pin configuration
	const XMC_GPIO_CONFIG_t pincfg_l = {
		.mode             = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
		.output_level     = XMC_GPIO_OUTPUT_LEVEL_LOW
	};
	const XMC_GPIO_CONFIG_t pincfg_h = {
		.mode             = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
		.output_level     = XMC_GPIO_OUTPUT_LEVEL_HIGH
	};
	XMC_GPIO_Init(XMC_GPIO_PORT1, 0, &pincfg_l);
	XMC_GPIO_Init(XMC_GPIO_PORT1, 1, &pincfg_l);
}

void mcp3911_tick(void) {
	SPIFifoState fs;
	fs = spi_fifo_next_state(&mcp3911.spi_fifo);

	ticker++;

	if((ticker % 8192) == 0) {
		if(fs & SPI_FIFO_STATE_ERROR) {
			mcp3911_init();
			return;
		}

		if((fs == SPI_FIFO_STATE_IDLE)) {
			uint16_t c = CONFIG_CONFIG_AMCLK_1 |
			             CONFIG_CONFIG_OSR_4096 |
			             CONFIG_CONFIG_DITHER_MAX |
			             CONFIG_CONFIG_AZ_FREQ_LOW |
			             CONFIG_CONFIG_RESET_NONE |
			             CONFIG_CONFIG_SHUTDOWN_NONE |
			             CONFIG_CONFIG_VREFINT_EN |
			             CONFIG_CONFIG_CLKEXT_CRYSTAL;

			mcp3911.spi_fifo_buf[0] = (uint8_t)GET_CTRL_BYTE_W(0x00, MCP3911_REG_ADDR_CONFIG);
			mcp3911.spi_fifo_buf[1] = 0xFF;//(uint8_t)(c >> 8);
			mcp3911.spi_fifo_buf[2] = 0xFF;//(uint8_t)c;

			XMC_USIC_CH_RXFIFO_Flush(mcp3911.spi_fifo.channel);
			spi_fifo_transceive(&mcp3911.spi_fifo, 3, &mcp3911.spi_fifo_buf[0]);
			system_timer_sleep_ms(4);

			fs = spi_fifo_next_state(&mcp3911.spi_fifo);

			if(fs != SPI_FIFO_STATE_TRANSCEIVE_READY) {
				logd("WRITE TRANS FAILED: fs = %d, spi_status = %d\n\r", fs, (uint32_t)mcp3911.spi_fifo.spi_status);
				mcp3911_init();
				return;
			}

			mcp3911.spi_fifo_buf[0] = (uint8_t)GET_CTRL_BYTE_R(0x00, MCP3911_REG_ADDR_CONFIG);
			mcp3911.spi_fifo_buf[1] = 0x00;
			mcp3911.spi_fifo_buf[2] = 0x00;

			XMC_USIC_CH_RXFIFO_Flush(mcp3911.spi_fifo.channel);
			spi_fifo_transceive(&mcp3911.spi_fifo, 3, &mcp3911.spi_fifo_buf[0]);
			system_timer_sleep_ms(4);

			fs = spi_fifo_next_state(&mcp3911.spi_fifo);

			if(fs != SPI_FIFO_STATE_TRANSCEIVE_READY) {
				logd("READ TRANS FAILED: fs = %d\n\r", fs);
				mcp3911_init();
				return;
			}

			logd("RX %d BYTES FROM FIFO\n\r", spi_fifo_read_fifo(&mcp3911.spi_fifo, &mcp3911.spi_fifo_buf[0], 3));
			logd("[0] = %d\n\r", mcp3911.spi_fifo_buf[0]);
			logd("[1] = %d\n\r", mcp3911.spi_fifo_buf[1]);
			logd("[2] = %d\n\r\n\r", mcp3911.spi_fifo_buf[2]);

			mcp3911.spi_fifo.state = SPI_FIFO_STATE_IDLE;
			XMC_USIC_CH_RXFIFO_Flush(mcp3911.spi_fifo.channel);
		}
	}
}

int32_t mcp3911_get_voltage(uint8_t channel) {
    return 0;
}
