#!/usr/bin/env python
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "XYZ" # Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_industrial_dual_analog_in_v2 import BrickletIndustrialDualAnalogInV2

# Callback function for voltage callback
def cb_voltage(channel, voltage):
    print("Channel: " + str(channel))
    print("Voltage: " + str(voltage/1000.0) + " V")
    print("")

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    idai = BrickletIndustrialDualAnalogInV2(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Register voltage callback to function cb_voltage
    idai.register_callback(idai.CALLBACK_VOLTAGE, cb_voltage)

    # Set period for voltage (channel 0) callback to 1s (1000ms) without a threshold
    idai.set_voltage_callback_configuration(0, 1000, False, "x", 0, 0)

    raw_input("Press key to exit\n") # Use input() in Python 3
    ipcon.disconnect()
