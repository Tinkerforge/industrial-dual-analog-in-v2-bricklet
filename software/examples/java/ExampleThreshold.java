import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletIndustrialDualAnalogInV2;

public class ExampleThreshold {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;

	// Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0
	private static final String UID = "XYZ";

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions
	//       you might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletIndustrialDualAnalogInV2 idai =
		  new BrickletIndustrialDualAnalogInV2(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Add voltage listener
		idai.addVoltageListener(new BrickletIndustrialDualAnalogInV2.VoltageListener() {
			public void voltage(int channel, int voltage) {
				System.out.println("Channel: " + channel);
				System.out.println("Voltage: " + voltage/1000.0 + " V");
				System.out.println("");
			}
		});

		// Configure threshold for voltage (channel 0) "greater than 10 V"
		// with a debounce period of 10s (10000ms)
		idai.setVoltageCallbackConfiguration(0, 10000, false, '>', 10*1000, 0);

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
