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

    // Create receiver for voltage events.
    let voltage_receiver = idai.get_voltage_receiver();

    // Spawn thread to handle received events. This thread ends when the `idai` object
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for voltage in voltage_receiver {
            println!("Channel: {}", voltage.channel);
            println!("Voltage: {} V", voltage.voltage as f32 / 1000.0);
            println!();
        }
    });

    // Set period for voltage (channel 0) callback to 1s (1000ms) without a threshold.
    idai.set_voltage_callback_configuration(0, 1000, false, 'x', 0, 0);

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
