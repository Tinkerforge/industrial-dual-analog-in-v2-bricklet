using System;
using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

	// Callback function for voltage callback
	static void VoltageCB(BrickletIndustrialDualAnalogInV2 sender, byte channel,
	                      int voltage)
	{
		Console.WriteLine("Channel: " + channel);
		Console.WriteLine("Voltage: " + voltage/1000.0 + " V");
		Console.WriteLine("");
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletIndustrialDualAnalogInV2 idai =
		  new BrickletIndustrialDualAnalogInV2(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Register voltage callback to function VoltageCB
		idai.VoltageCallback += VoltageCB;

		// Configure threshold for voltage (channel 0) "greater than 10 V"
		// with a debounce period of 10s (10000ms)
		idai.SetVoltageCallbackConfiguration(0, 10000, false, '>', 10*1000, 0);

		Console.WriteLine("Press enter to exit");
		Console.ReadLine();
		ipcon.Disconnect();
	}
}
