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

static uint32_t all_voltages_callback_period = 0;
static bool all_voltages_callback_value_has_to_change = false;

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
		case FID_GET_ALL_VOLTAGES: return get_all_voltages(message, response);
		case FID_SET_ALL_VOLTAGES_CALLBACK_CONFIGURATION: return set_all_voltages_callback_configuration(message);
		case FID_GET_ALL_VOLTAGES_CALLBACK_CONFIGURATION: return get_all_voltages_callback_configuration(message, response);
		default: return HANDLE_MESSAGE_RESPONSE_NOT_SUPPORTED;
	}
}

BootloaderHandleMessageResponse set_sample_rate(const SetSampleRate *data) {
	if (data->rate > SAMPLE_RATE_1_SPS) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	mcp3911.rate     = data->rate;
	mcp3911.rate_new = true;

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

	mcp3911.calibration_new = true;

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

BootloaderHandleMessageResponse get_all_voltages(const GetAllVoltages *data, GetAllVoltages_Response *response) {
	response->header.length = sizeof(GetAllVoltages_Response);

	response->voltages[0] = mcp3911_get_voltage(0);
	response->voltages[1] = mcp3911_get_voltage(1);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_all_voltages_callback_configuration(const SetAllVoltagesCallbackConfiguration *data) {
	all_voltages_callback_period = data->period;
	all_voltages_callback_value_has_to_change = data->value_has_to_change;
	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_all_voltages_callback_configuration(const GetAllVoltagesCallbackConfiguration *data, GetAllVoltagesCallbackConfiguration_Response *response) {
	response->header.length = sizeof(GetAllVoltagesCallbackConfiguration_Response);

	response->period = all_voltages_callback_period;
	response->value_has_to_change = all_voltages_callback_value_has_to_change;
	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

bool handle_voltage_callback_0(void) {
	return handle_callback_value_callback_int32_t(callback_values_voltage, 0, FID_CALLBACK_VOLTAGE);
}

bool handle_voltage_callback_1(void) {
	return handle_callback_value_callback_int32_t(callback_values_voltage, 1, FID_CALLBACK_VOLTAGE);
}

bool handle_all_voltages_callback(void) {
	static bool is_buffered = false;
	static AllVoltages_Callback cb;
	static uint32_t last_time;
	static uint32_t last_voltages[2] = {0, 0};

	if(!is_buffered) {
		if((all_voltages_callback_period == 0) ||
		   (!system_timer_is_time_elapsed_ms(last_time, all_voltages_callback_period))) {
			return false;
		}

		tfp_make_default_header(&cb.header, bootloader_get_uid(), sizeof(AllVoltages_Callback), FID_CALLBACK_ALL_VOLTAGES);

		cb.voltages[0] = mcp3911_get_voltage(0);
		cb.voltages[1] = mcp3911_get_voltage(1);

		if (mcp3911.all_voltages_callback_value_has_to_change && cb.voltages[0] == last_voltages[0] && cb.voltages[1] == last_voltages[1]) {
			return false;
		}

		last_voltages[0] = cb.voltages[0];
		last_voltages[1] = cb.voltages[1];
		last_time = system_timer_get_ms();
	}

	if(bootloader_spitfp_is_send_possible(&bootloader_status.st)) {
		bootloader_spitfp_send_ack_and_message(&bootloader_status, (uint8_t*)&cb, sizeof(AllVoltages_Callback));
		is_buffered = false;
		return true;
	} else {
		is_buffered = true;
	}

	return false;
}

void communication_tick(void) {
	communication_callback_tick();
}

void communication_init(void) {
	callback_value_init_int32_t(callback_values_voltage, mcp3911_get_voltage);

	communication_callback_init();
}
