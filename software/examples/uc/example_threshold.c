#include "bindings/hal_common.h"
#include "bindings/bricklet_industrial_dual_analog_in_v2.h"

#define UID "XYZ" // Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

void check(int rc, const char* msg);

// Callback function for voltage callback
void voltage_handler(TF_IndustrialDualAnalogInV2 *device, uint8_t channel,
                     int32_t voltage, void *user_data) {
	(void)device; (void)user_data; // avoid unused parameter warning

	tf_hal_printf("Channel: %u\n", channel);
	tf_hal_printf("Voltage: %d 1/%d V\n", voltage, 1000.0);
	tf_hal_printf("\n");
}

TF_IndustrialDualAnalogInV2 idai;

void example_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_industrial_dual_analog_in_v2_create(&idai, UID, hal), "create device object");


	// Register voltage callback to function voltage_handler
	tf_industrial_dual_analog_in_v2_register_voltage_callback(&idai,
	                                                         voltage_handler,
	                                                         NULL);

	// Configure threshold for voltage (channel 0) "greater than 10 V"
	// with a debounce period of 10s (10000ms)
	tf_industrial_dual_analog_in_v2_set_voltage_callback_configuration(&idai, 0, 10000, false, '>', 10*1000, 0);

}

void example_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
