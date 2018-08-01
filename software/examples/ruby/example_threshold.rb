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

# Register voltage callback
idai.register_callback(BrickletIndustrialDualAnalogInV2::CALLBACK_VOLTAGE) do |channel,
                                                                               voltage|
  puts "Channel: #{channel}"
  puts "Voltage: #{voltage/1000.0} V"
  puts ''
end

# Configure threshold for voltage (channel 0) "greater than 10 V"
# with a debounce period of 10s (10000ms)
idai.set_voltage_callback_configuration 0, 10000, false, '>', 10*1000, 0

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
