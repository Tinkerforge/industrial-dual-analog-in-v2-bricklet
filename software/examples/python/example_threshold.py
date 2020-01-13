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

    # Configure threshold for voltage (channel 0) "greater than 10 V"
    # with a debounce period of 10s (10000ms)
    idai.set_voltage_callback_configuration(0, 10000, False, ">", 10*1000, 0)

    input("Press key to exit\n") # Use raw_input() in Python 2
    ipcon.disconnect()
