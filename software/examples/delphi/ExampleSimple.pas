program ExampleSimple;

{$ifdef MSWINDOWS}{$apptype CONSOLE}{$endif}
{$ifdef FPC}{$mode OBJFPC}{$H+}{$endif}

uses
  SysUtils, IPConnection, BrickletIndustrialDualAnalogInV2;

type
  TExample = class
  private
    ipcon: TIPConnection;
    idai: TBrickletIndustrialDualAnalogInV2;
  public
    procedure Execute;
  end;

const
  HOST = 'localhost';
  PORT = 4223;
  UID = 'XYZ'; { Change XYZ to the UID of your Industrial Dual Analog In Bricklet 2.0 }

var
  e: TExample;

procedure TExample.Execute;
var voltage: longint;
begin
  { Create IP connection }
  ipcon := TIPConnection.Create;

  { Create device object }
  idai := TBrickletIndustrialDualAnalogInV2.Create(UID, ipcon);

  { Connect to brickd }
  ipcon.Connect(HOST, PORT);
  { Don't use device before ipcon is connected }

  { Get current voltage from channel 0 }
  voltage := idai.GetVoltage(0);
  WriteLn(Format('Voltage (Channel 0): %f V', [voltage/1000.0]));

  WriteLn('Press key to exit');
  ReadLn;
  ipcon.Destroy; { Calls ipcon.Disconnect internally }
end;

begin
  e := TExample.Create;
  e.Execute;
  e.Destroy;
end.
