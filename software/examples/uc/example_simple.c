

#include "bindings/hal_common.h"
#include "bindings/bricklet_industrial_dual_analog_in_v2.h"

#define UID "XYZ" // Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

void check(int rc, const char* msg);




TF_IndustrialDualAnalogInV2 idai;

void example_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_industrial_dual_analog_in_v2_create(&idai, UID, hal), "create device object");


	// Get current voltage from channel 0
	int32_t voltage;
	check(tf_industrial_dual_analog_in_v2_get_voltage(&idai, 0,
	                                                  &voltage), "get voltage from channel 0");

	tf_hal_printf("Voltage (Channel 0): %d 1/%d V\n", voltage, 1000.0);

}

void example_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
