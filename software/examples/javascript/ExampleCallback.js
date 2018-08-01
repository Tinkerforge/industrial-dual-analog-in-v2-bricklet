var Tinkerforge = require('tinkerforge');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'XYZ'; // Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

var ipcon = new Tinkerforge.IPConnection(); // Create IP connection
var idai = new Tinkerforge.BrickletIndustrialDualAnalogInV2(UID, ipcon); // Create device object

ipcon.connect(HOST, PORT,
    function (error) {
        console.log('Error: ' + error);
    }
); // Connect to brickd
// Don't use device before ipcon is connected

ipcon.on(Tinkerforge.IPConnection.CALLBACK_CONNECTED,
    function (connectReason) {
        // Set period for voltage (channel 0) callback to 1s (1000ms) without a threshold
        idai.setVoltageCallbackConfiguration(0, 1000, false, 'x', 0, 0);
    }
);

// Register voltage callback
idai.on(Tinkerforge.BrickletIndustrialDualAnalogInV2.CALLBACK_VOLTAGE,
    // Callback function for voltage callback
    function (channel, voltage) {
        console.log('Channel: ' + channel);
        console.log('Voltage: ' + voltage/1000.0 + ' V');
        console.log();
    }
);

console.log('Press key to exit');
process.stdin.on('data',
    function (data) {
        ipcon.disconnect();
        process.exit(0);
    }
);
