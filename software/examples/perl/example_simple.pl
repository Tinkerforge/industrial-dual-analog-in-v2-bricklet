#!/usr/bin/perl

use strict;
use Tinkerforge::IPConnection;
use Tinkerforge::BrickletIndustrialDualAnalogInV2;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $idai = Tinkerforge::BrickletIndustrialDualAnalogInV2->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get current voltage from channel 0
my $voltage = $idai->get_voltage(0);
print "Voltage (Channel 0): " . $voltage/1000.0 . " V\n";

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
