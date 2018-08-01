Imports System
Imports Tinkerforge

Module ExampleThreshold
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0

    ' Callback subroutine for voltage callback
    Sub VoltageCB(ByVal sender As BrickletIndustrialDualAnalogInV2, _
                  ByVal channel As Byte, ByVal voltage As Integer)
        Console.WriteLine("Channel: " + channel.ToString())
        Console.WriteLine("Voltage: " + (voltage/1000.0).ToString() + " V")
        Console.WriteLine("")
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim idai As New BrickletIndustrialDualAnalogInV2(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Register voltage callback to subroutine VoltageCB
        AddHandler idai.VoltageCallback, AddressOf VoltageCB

        ' Configure threshold for voltage "greater than 10 V"
        ' with a debounce period of 10s (10000ms)
        idai.SetVoltageCallbackConfiguration(0, 10000, False, ">"C, 10*1000, 0)

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
