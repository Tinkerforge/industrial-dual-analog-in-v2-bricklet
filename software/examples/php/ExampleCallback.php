<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletIndustrialDualAnalogInV2.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletIndustrialDualAnalogInV2;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

// Callback function for voltage callback
function cb_voltage($channel, $voltage)
{
    echo "Channel: $channel\n";
    echo "Voltage: " . $voltage/1000.0 . " V\n";
    echo "\n";
}

$ipcon = new IPConnection(); // Create IP connection
$idai = new BrickletIndustrialDualAnalogInV2(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Register voltage callback to function cb_voltage
$idai->registerCallback(BrickletIndustrialDualAnalogInV2::CALLBACK_VOLTAGE, 'cb_voltage');

// Set period for voltage (channel 0) callback to 1s (1000ms) without a threshold
$idai->setVoltageCallbackConfiguration(0, 1000, FALSE, 'x', 0, 0);

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
