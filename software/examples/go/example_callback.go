package main

import (
	"fmt"
	"tinkerforge/industrial_dual_analog_in_v2_bricklet"
	"tinkerforge/ipconnection"
)

const ADDR string = "localhost:4223"
const UID string = "XYZ" // Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0.

func main() {
	ipcon := ipconnection.New()
	defer ipcon.Close()
	idai, _ := industrial_dual_analog_in_v2_bricklet.New(UID, &ipcon) // Create device object.

	ipcon.Connect(ADDR) // Connect to brickd.
	defer ipcon.Disconnect()
	// Don't use device before ipcon is connected.

	idai.RegisterVoltageCallback(func(channel uint8, voltage int32) {
		fmt.Printf("Channel: %d\n", channel)
		fmt.Printf("Voltage: %d V\n", float64(voltage)/1000.0)
		fmt.Println()
	})

	// Set period for voltage (channel 0) callback to 1s (1000ms) without a threshold.
	idai.SetVoltageCallbackConfiguration(0, 1000, false, 'x', 0, 0)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()

}
