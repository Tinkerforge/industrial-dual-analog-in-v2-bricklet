/* industrial-dual-analog-in-v2-bricklet
 * Copyright (C) 2018 Ishraq Ibne Ashraf <ishraq@tinkerforge.com>
 *
 * communication.c: TFP protocol message handling
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

#include "communication.h"

#include "bricklib2/utility/communication_callback.h"
#include "bricklib2/protocols/tfp/tfp.h"
#include "bricklib2/utility/callback_value.h"

#include "mcp3911.h"

uint8_t voltage_callback_channel = 0;
CallbackValue_int32_t callback_values_voltage[CALLBACK_VALUE_CHANNEL_NUM];

BootloaderHandleMessageResponse handle_message(const void *message, void *response) {
	switch(tfp_get_fid_from_message(message)) {
		case FID_GET_VOLTAGE: return get_callback_value_int32_t(message, response, callback_values_voltage);
		case FID_SET_VOLTAGE_CALLBACK_CONFIGURATION: return set_callback_value_callback_configuration_int32_t(message, callback_values_voltage);
		case FID_GET_VOLTAGE_CALLBACK_CONFIGURATION: return get_callback_value_callback_configuration_int32_t(message, response, callback_values_voltage);
		case FID_SET_SAMPLE_RATE: return set_sample_rate(message);
		case FID_GET_SAMPLE_RATE: return get_sample_rate(message, response);
		case FID_SET_CALIBRATION: return set_calibration(message);
		case FID_GET_CALIBRATION: return get_calibration(message, response);
		case FID_GET_ADC_VALUES: return get_adc_values(message, response);
		case FID_SET_CHANNEL_LED_CONFIG: return set_channel_led_config(message);
		case FID_GET_CHANNEL_LED_CONFIG: return get_channel_led_config(message, response);
		case FID_SET_CHANNEL_LED_STATUS_CONFIG: return set_channel_led_status_config(message);
		case FID_GET_CHANNEL_LED_STATUS_CONFIG: return get_channel_led_status_config(message, response);
		default: return HANDLE_MESSAGE_RESPONSE_NOT_SUPPORTED;
	}
}

BootloaderHandleMessageResponse set_sample_rate(const SetSampleRate *data) {
	if (data->rate > SAMPLE_RATE_1_SPS) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	mcp3911.rate = data->rate;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_sample_rate(const GetSampleRate *data, GetSampleRate_Response *response) {
	response->header.length = sizeof(GetSampleRate_Response);
	response->rate = mcp3911.rate;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_calibration(const SetCalibration *data) {
	for (uint8_t i = 0; i < CALLBACK_VALUE_CHANNEL_NUM; i++) {
		mcp3911.channels[i].cal_gain = data->gain[i];
		mcp3911.channels[i].cal_offset = data->offset[i];
	}

	mcp3911_set_calibration();
	mcp3911_calibration_eeprom_write();

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_calibration(const GetCalibration *data, GetCalibration_Response *response) {
	response->header.length = sizeof(GetCalibration_Response);

	for (uint8_t i = 0; i < CALLBACK_VALUE_CHANNEL_NUM; i++) {
		response->gain[i] = mcp3911.channels[i].cal_gain;
		response->offset[i] = mcp3911.channels[i].cal_offset;
	}

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_adc_values(const GetADCValues *data, GetADCValues_Response *response) {
	response->header.length = sizeof(GetADCValues_Response);

	for (uint8_t i = 0; i < CALLBACK_VALUE_CHANNEL_NUM; i++) {
		response->value[i] = mcp3911.channels[i].adc_raw_value;
	}

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_channel_led_config(const SetChannelLEDConfig *data) {
	if(data->channel > CALLBACK_VALUE_CHANNEL_NUM - 1) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	mcp3911.channel_leds[data->channel].config = data->config;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_channel_led_config(const GetChannelLEDConfig *data, GetChannelLEDConfig_Response *response) {
	response->header.length = sizeof(GetChannelLEDConfig_Response);

	if(data->channel > CALLBACK_VALUE_CHANNEL_NUM - 1) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	response->config = mcp3911.channel_leds[data->channel].config;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_channel_led_status_config(const SetChannelLEDStatusConfig *data) {
	if(data->channel > CALLBACK_VALUE_CHANNEL_NUM - 1) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	mcp3911.channel_leds[data->channel].min = data->min;
	mcp3911.channel_leds[data->channel].max = data->max;
	mcp3911.channel_leds[data->channel].config_ch_status = data->config;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_channel_led_status_config(const GetChannelLEDStatusConfig *data, GetChannelLEDStatusConfig_Response *response) {
	response->header.length = sizeof(GetChannelLEDStatusConfig_Response);

	if(data->channel > CALLBACK_VALUE_CHANNEL_NUM - 1) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	response->min = mcp3911.channel_leds[data->channel].min;
	response->max = mcp3911.channel_leds[data->channel].max;
	response->config = mcp3911.channel_leds[data->channel].config_ch_status;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

bool handle_voltage_callback(void) {
	bool ret = handle_callback_value_callback_int32_t(callback_values_voltage, voltage_callback_channel, FID_CALLBACK_VOLTAGE);

	if(++voltage_callback_channel >= CALLBACK_VALUE_CHANNEL_NUM) {
		voltage_callback_channel = 0;
	}

	return ret;
}

void communication_tick(void) {
	communication_callback_tick();
}

void communication_init(void) {
	callback_value_init_int32_t(callback_values_voltage, mcp3911_get_voltage);

	communication_callback_init();
}
