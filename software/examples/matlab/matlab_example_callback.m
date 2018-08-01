function matlab_example_callback()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletIndustrialDualAnalogInV2;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

    ipcon = IPConnection(); % Create IP connection
    idai = handle(BrickletIndustrialDualAnalogInV2(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Register voltage callback to function cb_voltage
    set(idai, 'VoltageCallback', @(h, e) cb_voltage(e));

    % Set period for voltage (channel 0) callback to 1s (1000ms) without a threshold
    idai.setVoltageCallbackConfiguration(0, 1000, false, 'x', 0, 0);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end

% Callback function for voltage callback
function cb_voltage(e)
    fprintf('Channel: %i\n', e.channel);
    fprintf('Voltage: %g V\n', e.voltage/1000.0);
    fprintf('\n');
end
