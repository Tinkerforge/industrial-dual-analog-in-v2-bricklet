#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

# Handle incoming voltage callbacks
tinkerforge dispatch industrial-dual-analog-in-v2-bricklet $uid voltage &

# Set period for voltage (channel 0) callback to 1s (1000ms) without a threshold
tinkerforge call industrial-dual-analog-in-v2-bricklet $uid set-voltage-callback-configuration 0 1000 false threshold-option-off 0 0

echo "Press key to exit"; read dummy

kill -- -$$ # Stop callback dispatch in background
