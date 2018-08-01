#!/usr/bin/perl

use strict;
use Tinkerforge::IPConnection;
use Tinkerforge::BrickletIndustrialDualAnalogInV2;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

# Callback subroutine for voltage callback
sub cb_voltage
{
    my ($channel, $voltage) = @_;

    print "Channel: $channel\n";
    print "Voltage: " . $voltage/1000.0 . " V\n";
    print "\n";
}

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $idai = Tinkerforge::BrickletIndustrialDualAnalogInV2->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Register voltage callback to subroutine cb_voltage
$idai->register_callback($idai->CALLBACK_VOLTAGE, 'cb_voltage');

# Set period for voltage (channel 0) callback to 1s (1000ms) without a threshold
$idai->set_voltage_callback_configuration(0, 1000, 0, 'x', 0, 0);

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
