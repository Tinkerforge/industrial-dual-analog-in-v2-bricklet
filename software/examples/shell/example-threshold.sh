#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

# Handle incoming voltage callbacks
tinkerforge dispatch industrial-dual-analog-in-v2-bricklet $uid voltage &

# Configure threshold for voltage (channel 0) "greater than 10 V"
# with a debounce period of 10s (10000ms)
tinkerforge call industrial-dual-analog-in-v2-bricklet $uid set-voltage-callback-configuration 0 10000 false threshold-option-greater 10000 0

echo "Press key to exit"; read dummy

kill -- -$$ # Stop callback dispatch in background
