#!/usr/bin/env python
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "XYZ" # Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_industrial_dual_analog_in_v2 import BrickletIndustrialDualAnalogInV2

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    idai = BrickletIndustrialDualAnalogInV2(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Get current voltage from channel 0
    voltage = idai.get_voltage(0)
    print("Voltage (Channel 0): " + str(voltage/1000.0) + " V")

    input("Press key to exit\n") # Use raw_input() in Python 2
    ipcon.disconnect()
