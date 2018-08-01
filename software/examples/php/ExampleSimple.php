<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletIndustrialDualAnalogInV2.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletIndustrialDualAnalogInV2;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

$ipcon = new IPConnection(); // Create IP connection
$idai = new BrickletIndustrialDualAnalogInV2(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get current voltage from channel 0
$voltage = $idai->getVoltage(0);
echo "Voltage (Channel 0): " . $voltage/1000.0 . " V\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
