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

uint8_t channel_based_handle_channel = 0;
CallbackValue channel_based_cbv[CHANNEL_BASED_COUNT];

BootloaderHandleMessageResponse handle_message(const void *message, void *response) {
	switch(tfp_get_fid_from_message(message)) {
		case FID_GET_VOLTAGE: {
			uint8_t channel = ((OnChannelGetCallbackValue *)message)->channel;
			return channel_based_get_callback_value(message, response, &channel_based_cbv[channel]);
		}
		case FID_SET_VOLTAGE_CALLBACK_CONFIGURATION: {
			uint8_t channel = ((OnChannelSetCallbackValueCallbackConfiguration *)message)->channel;
			return channel_based_set_callback_value_callback_configuration(message, &channel_based_cbv[channel]);
		}
		case FID_GET_VOLTAGE_CALLBACK_CONFIGURATION: {
			uint8_t channel = ((OnChannelGetCallbackValueCallbackConfiguration *)message)->channel;
			return channel_based_get_callback_value_callback_configuration(message, response, &channel_based_cbv[channel]);
		}
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

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_sample_rate(const GetSampleRate *data, GetSampleRate_Response *response) {
	response->header.length = sizeof(GetSampleRate_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_calibration(const SetCalibration *data) {

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_calibration(const GetCalibration *data, GetCalibration_Response *response) {
	response->header.length = sizeof(GetCalibration_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_adc_values(const GetADCValues *data, GetADCValues_Response *response) {
	response->header.length = sizeof(GetADCValues_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_channel_led_config(const SetChannelLEDConfig *data) {

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_channel_led_config(const GetChannelLEDConfig *data, GetChannelLEDConfig_Response *response) {
	response->header.length = sizeof(GetChannelLEDConfig_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_channel_led_status_config(const SetChannelLEDStatusConfig *data) {

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_channel_led_status_config(const GetChannelLEDStatusConfig *data, GetChannelLEDStatusConfig_Response *response) {
	response->header.length = sizeof(GetChannelLEDStatusConfig_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

bool handle_voltage_callback(void) {
	bool ret = channel_based_handle_callback_value_callback(&channel_based_cbv[channel_based_handle_channel],
	                                                        FID_CALLBACK_VOLTAGE,
	                                                        channel_based_handle_channel);

	if(!(++channel_based_handle_channel < CHANNEL_BASED_COUNT)) {
		channel_based_handle_channel = 0;
	}

	return ret;
}

void communication_tick(void) {
	communication_callback_tick();
}

void communication_init(void) {
	for(uint8_t i = 0; i < CHANNEL_BASED_COUNT; i++) {
		channel_based_callback_value_init(&channel_based_cbv[i], mcp3911_get_voltage);
	}

	communication_callback_init();
}
