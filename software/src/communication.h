/* industrial-dual-analog-in-v2-bricklet
 * Copyright (C) 2018 Ishraq Ibne Ashraf <ishraq@tinkerforge.com>
 *
 * communication.h: TFP protocol message handling
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

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdint.h>
#include <stdbool.h>

#include "bricklib2/protocols/tfp/tfp.h"
#include "bricklib2/bootloader/bootloader.h"

// Default functions
BootloaderHandleMessageResponse handle_message(const void *data, void *response);
void communication_tick(void);
void communication_init(void);

// Constants
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_THRESHOLD_OPTION_OFF 'x'
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_THRESHOLD_OPTION_OUTSIDE 'o'
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_THRESHOLD_OPTION_INSIDE 'i'
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_THRESHOLD_OPTION_SMALLER '<'
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_THRESHOLD_OPTION_GREATER '>'

#define INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_976_SPS 0
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_488_SPS 1
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_244_SPS 2
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_122_SPS 3
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_61_SPS 4
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_4_SPS 5
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_2_SPS 6
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_SAMPLE_RATE_1_SPS 7

#define INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_OFF 0
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_ON 1
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_SHOW_HEARTBEAT 2
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_CONFIG_SHOW_CHANNEL_STATUS 3

#define INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_STATUS_CONFIG_THRESHOLD 0
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_CHANNEL_LED_STATUS_CONFIG_INTENSITY 1

#define INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_MODE_BOOTLOADER 0
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_MODE_FIRMWARE 1
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

#define INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_STATUS_OK 0
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_STATUS_INVALID_MODE 1
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_STATUS_NO_CHANGE 2
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

#define INDUSTRIAL_DUAL_ANALOG_IN_V2_STATUS_LED_CONFIG_OFF 0
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_STATUS_LED_CONFIG_ON 1
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2
#define INDUSTRIAL_DUAL_ANALOG_IN_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

// Function and callback IDs and structs
#define FID_GET_VOLTAGE 1
#define FID_SET_VOLTAGE_CALLBACK_CONFIGURATION 2
#define FID_GET_VOLTAGE_CALLBACK_CONFIGURATION 3
#define FID_SET_SAMPLE_RATE 5
#define FID_GET_SAMPLE_RATE 6
#define FID_SET_CALIBRATION 7
#define FID_GET_CALIBRATION 8
#define FID_GET_ADC_VALUES 9
#define FID_SET_CHANNEL_LED_CONFIG 10
#define FID_GET_CHANNEL_LED_CONFIG 11
#define FID_SET_CHANNEL_LED_STATUS_CONFIG 12
#define FID_GET_CHANNEL_LED_STATUS_CONFIG 13
#define FID_GET_ALL_VOLTAGES 14
#define FID_SET_ALL_VOLTAGES_CALLBACK_CONFIGURATION 15
#define FID_GET_ALL_VOLTAGES_CALLBACK_CONFIGURATION 16

#define FID_CALLBACK_VOLTAGE 4
#define FID_CALLBACK_ALL_VOLTAGES 17

typedef struct {
	TFPMessageHeader header;
	uint8_t rate;
} __attribute__((__packed__)) SetSampleRate;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetSampleRate;

typedef struct {
	TFPMessageHeader header;
	uint8_t rate;
} __attribute__((__packed__)) GetSampleRate_Response;

typedef struct {
	TFPMessageHeader header;
	int32_t offset[2];
	int32_t gain[2];
} __attribute__((__packed__)) SetCalibration;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetCalibration;

typedef struct {
	TFPMessageHeader header;
	int32_t offset[2];
	int32_t gain[2];
} __attribute__((__packed__)) GetCalibration_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetADCValues;

typedef struct {
	TFPMessageHeader header;
	int32_t value[2];
} __attribute__((__packed__)) GetADCValues_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t channel;
	uint8_t config;
} __attribute__((__packed__)) SetChannelLEDConfig;

typedef struct {
	TFPMessageHeader header;
	uint8_t channel;
} __attribute__((__packed__)) GetChannelLEDConfig;

typedef struct {
	TFPMessageHeader header;
	uint8_t config;
} __attribute__((__packed__)) GetChannelLEDConfig_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t channel;
	int32_t min;
	int32_t max;
	uint8_t config;
} __attribute__((__packed__)) SetChannelLEDStatusConfig;

typedef struct {
	TFPMessageHeader header;
	uint8_t channel;
} __attribute__((__packed__)) GetChannelLEDStatusConfig;

typedef struct {
	TFPMessageHeader header;
	int32_t min;
	int32_t max;
	uint8_t config;
} __attribute__((__packed__)) GetChannelLEDStatusConfig_Response;


typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetAllVoltages;

typedef struct {
	TFPMessageHeader header;
	int32_t voltages[2];
} __attribute__((__packed__)) GetAllVoltages_Response;

typedef struct {
	TFPMessageHeader header;
	uint32_t period;
	bool value_has_to_change;
} __attribute__((__packed__)) SetAllVoltagesCallbackConfiguration;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetAllVoltagesCallbackConfiguration;

typedef struct {
	TFPMessageHeader header;
	uint32_t period;
	bool value_has_to_change;
} __attribute__((__packed__)) GetAllVoltagesCallbackConfiguration_Response;

typedef struct {
	TFPMessageHeader header;
	int32_t voltages[2];
} __attribute__((__packed__)) AllVoltages_Callback;

// Function prototypes
BootloaderHandleMessageResponse set_sample_rate(const SetSampleRate *data);
BootloaderHandleMessageResponse get_sample_rate(const GetSampleRate *data, GetSampleRate_Response *response);
BootloaderHandleMessageResponse set_calibration(const SetCalibration *data);
BootloaderHandleMessageResponse get_calibration(const GetCalibration *data, GetCalibration_Response *response);
BootloaderHandleMessageResponse get_adc_values(const GetADCValues *data, GetADCValues_Response *response);
BootloaderHandleMessageResponse set_channel_led_config(const SetChannelLEDConfig *data);
BootloaderHandleMessageResponse get_channel_led_config(const GetChannelLEDConfig *data, GetChannelLEDConfig_Response *response);
BootloaderHandleMessageResponse set_channel_led_status_config(const SetChannelLEDStatusConfig *data);
BootloaderHandleMessageResponse get_channel_led_status_config(const GetChannelLEDStatusConfig *data, GetChannelLEDStatusConfig_Response *response);
BootloaderHandleMessageResponse get_all_voltages(const GetAllVoltages *data, GetAllVoltages_Response *response);
BootloaderHandleMessageResponse set_all_voltages_callback_configuration(const SetAllVoltagesCallbackConfiguration *data);
BootloaderHandleMessageResponse get_all_voltages_callback_configuration(const GetAllVoltagesCallbackConfiguration *data, GetAllVoltagesCallbackConfiguration_Response *response);

// Callbacks
bool handle_voltage_callback_0(void);
bool handle_voltage_callback_1(void);
bool handle_all_voltages_callback(void);

#define COMMUNICATION_CALLBACK_TICK_WAIT_MS 1
#define COMMUNICATION_CALLBACK_HANDLER_NUM 3
#define COMMUNICATION_CALLBACK_LIST_INIT \
	handle_voltage_callback_0, \
	handle_voltage_callback_1, \
	handle_all_voltages_callback, \

#endif
