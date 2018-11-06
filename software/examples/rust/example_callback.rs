use std::{error::Error, io, thread};
use tinkerforge::{industrial_dual_analog_in_v2_bricklet::*, ipconnection::IpConnection};

const HOST: &str = "127.0.0.1";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection
    let industrial_dual_analog_in_v2_bricklet = IndustrialDualAnalogInV2Bricklet::new(UID, &ipcon); // Create device object

    ipcon.connect(HOST, PORT).recv()??; // Connect to brickd
                                        // Don't use device before ipcon is connected

    //Create listener for voltage events.
    let voltage_listener = industrial_dual_analog_in_v2_bricklet.get_voltage_receiver();
    // Spawn thread to handle received events. This thread ends when the industrial_dual_analog_in_v2_bricklet
    // is dropped, so there is no need for manual cleanup.
    thread::spawn(move || {
        for event in voltage_listener {
            println!("Channel: {}", event.channel);
            println!("Voltage: {}{}", event.voltage as f32 / 1000.0, " V");
            println!();
        }
    });

    // Set period for voltage (channel 0) callback to 1s (1000ms) without a threshold
    industrial_dual_analog_in_v2_bricklet.set_voltage_callback_configuration(0, 1000, false, 'x', 0, 0);

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
