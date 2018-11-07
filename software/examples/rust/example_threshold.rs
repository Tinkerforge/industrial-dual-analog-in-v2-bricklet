use std::{error::Error, io, thread};
use tinkerforge::{industrial_dual_analog_in_v2_bricklet::*, ip_connection::IpConnection};

const HOST: &str = "localhost";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0.

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection.
    let idai = IndustrialDualAnalogInV2Bricklet::new(UID, &ipcon); // Create device object.

    ipcon.connect((HOST, PORT)).recv()??; // Connect to brickd.
                                          // Don't use device before ipcon is connected.

    let voltage_receiver = idai.get_voltage_callback_receiver();

    // Spawn thread to handle received callback messages.
    // This thread ends when the `idai` object
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for voltage in voltage_receiver {
            println!("Channel: {}", voltage.channel);
            println!("Voltage: {} V", voltage.voltage as f32 / 1000.0);
            println!();
        }
    });

    // Configure threshold for voltage (channel 0) "greater than 10 V"
    // with a debounce period of 10s (10000ms).
    idai.set_voltage_callback_configuration(0, 10000, false, '>', 10 * 1000, 0);

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
