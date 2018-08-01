#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

# Get current voltage from channel 0
tinkerforge call industrial-dual-analog-in-v2-bricklet $uid get-voltage 0
