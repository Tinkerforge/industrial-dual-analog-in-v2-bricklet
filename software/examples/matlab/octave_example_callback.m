function octave_example_callback()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    idai = javaObject("com.tinkerforge.BrickletIndustrialDualAnalogInV2", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Register voltage callback to function cb_voltage
    idai.addVoltageCallback(@cb_voltage);

    % Set period for voltage (channel 0) callback to 1s (1000ms) without a threshold
    idai.setVoltageCallbackConfiguration(0, 1000, false, "x", 0, 0);

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end

% Callback function for voltage callback
function cb_voltage(e)
    fprintf("Channel: %d\n", e.channel);
    fprintf("Voltage: %g V\n", e.voltage/1000.0);
    fprintf("\n");
end
