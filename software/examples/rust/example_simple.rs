use std::{error::Error, io};

use tinkerforge::{industrial_dual_analog_in_v2_bricklet::*, ipconnection::IpConnection};

const HOST: &str = "127.0.0.1";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection
    let industrial_dual_analog_in_v2_bricklet = IndustrialDualAnalogInV2Bricklet::new(UID, &ipcon); // Create device object

    ipcon.connect(HOST, PORT).recv()??; // Connect to brickd
                                        // Don't use device before ipcon is connected

    // Get current voltage from channel 0
    let voltage = industrial_dual_analog_in_v2_bricklet.get_voltage(0).recv()?;
    println!("Voltage (Channel 0): {}{}", voltage as f32 / 1000.0, " V");

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
