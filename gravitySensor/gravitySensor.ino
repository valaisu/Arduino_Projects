#include <Wire.h>
// Made following the tutorial from
// https://howtomechatronics.com/tutorials/arduino/how-to-track-orientation-with-arduino-and-adxl345-accelerometer/

// for this code to work, make following connections
// 5V -> 5V
// GND -> GND
// SCL -> A5 / SCL
// SDA -> A4 / SDA
int ADXL345 = 0x53;

float x_out, y_out, z_out;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  Wire.begin();

  Wire.beginTransmission(ADXL345);
  Wire.write(0x2D);

  Wire.write(8);
  Wire.endTransmission();
  delay(10);

  // My sensors calibrations are so to say fucked,
  // so here they are manually adjusted

  // red
  Wire.beginTransmission(ADXL345);
  Wire.write(0x1E);
  Wire.write(26);
  Wire.endTransmission();
  delay(10);

  // yellow
  Wire.beginTransmission(ADXL345);
  Wire.write(0x1F);
  Wire.write(38);
  Wire.endTransmission();
  delay(10);

  // blue
  // especially this dude is royally fucked
  Wire.beginTransmission(ADXL345);
  Wire.write(0x20);
  Wire.write(100);
  Wire.endTransmission();
  delay(10);


}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32);
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true);
  x_out = (Wire.read()| Wire.read()<<8);
  x_out = x_out/310; // calibrates the values between -1 and 1
  y_out = (Wire.read()| Wire.read()<<8);
  y_out = y_out/310;
  z_out = (Wire.read()| Wire.read()<<8);
  z_out = z_out/256;

  Serial.print("Xa= ");
  Serial.print(x_out);
  Serial.print("    Ya= ");
  Serial.print(y_out);
  Serial.print("    Za= ");
  Serial.println(z_out);  
}
