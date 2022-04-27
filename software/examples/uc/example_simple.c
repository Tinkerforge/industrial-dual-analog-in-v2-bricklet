// This example is not self-contained.
// It requires usage of the example driver specific to your platform.
// See the HAL documentation.

#include "src/bindings/hal_common.h"
#include "src/bindings/bricklet_industrial_dual_analog_in_v2.h"

void check(int rc, const char *msg);
void example_setup(TF_HAL *hal);
void example_loop(TF_HAL *hal);

static TF_IndustrialDualAnalogInV2 idai;

void example_setup(TF_HAL *hal) {
	// Create device object
	check(tf_industrial_dual_analog_in_v2_create(&idai, NULL, hal), "create device object");

	// Get current voltage from channel 0
	int32_t voltage;
	check(tf_industrial_dual_analog_in_v2_get_voltage(&idai, 0,
	                                                  &voltage), "get voltage from channel 0");

	tf_hal_printf("Voltage (Channel 0): %d 1/%d V\n", voltage, 1000);
}

void example_loop(TF_HAL *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
