function matlab_example_simple()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletIndustrialDualAnalogInV2;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

    ipcon = IPConnection(); % Create IP connection
    idai = handle(BrickletIndustrialDualAnalogInV2(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current voltage from channel 0
    voltage = idai.getVoltage(0);
    fprintf('Voltage (Channel 0): %g V\n', voltage/1000.0);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end
