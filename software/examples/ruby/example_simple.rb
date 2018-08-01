#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_industrial_dual_analog_in_v2'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XYZ' # Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

ipcon = IPConnection.new # Create IP connection
idai = BrickletIndustrialDualAnalogInV2.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Get current voltage from channel 0
voltage = idai.get_voltage 0
puts "Voltage (Channel 0): #{voltage/1000.0} V"

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
