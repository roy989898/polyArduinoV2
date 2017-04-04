// VCC >>> 3.3V
//
// SDA >>> A4
//
// SCL >>> A5
//
// addr >> A3 "Optional and use address 0x23 "
//
// Gnd >>>Gnd
#include <BH1750FVI.h> // Sensor Library
#include <Wire.h>      // I2C Library
#include "Arduino.h"
BH1750FVI LightSensor;
int rightLightSensorPin = 4;
int leftLightSensorPin = 11;
void lightSensorSetUp()
{
   pinMode(rightLightSensorPin, OUTPUT);
  pinMode(leftLightSensorPin, OUTPUT);
  digitalWrite(leftLightSensorPin, LOW);
  digitalWrite(rightLightSensorPin, LOW);
  delay(1000);
  

  // LightSensor.begin();
  // LightSensor.SetAddress(Device_Address_H);//Address 0x5C
  // To adjust the slave on other address , uncomment this line
  // lightMeter.SetAddress(Device_Address_L); //Address 0x5C
  //-----------------------------------------------
  /*
  set the Working Mode for this sensor
  Select the following Mode:
  Continuous_H_resolution_Mode
  Continuous_H_resolution_Mode2
  Continuous_L_resolution_Mode
  OneTime_H_resolution_Mode
  OneTime_H_resolution_Mode2
  OneTime_L_resolution_Mode
  The data sheet recommanded To use Continuous_H_resolution_Mode
  */
  // LightSensor.SetMode(Continuous_H_resolution_Mode);
}

uint16_t getRightLightLux()
{
  digitalWrite(rightLightSensorPin, HIGH);
  delay(150);
  LightSensor.begin();
  LightSensor.SetAddress(Device_Address_H); //Address 0x5C
  LightSensor.SetMode(Continuous_H_resolution_Mode);
  uint16_t lux = LightSensor.GetLightIntensity(); // Get Lux value
  digitalWrite(rightLightSensorPin, LOW);
  lux = map(lux, 0, 300, 0, 100);
  return lux;
}

uint16_t getLeftLightLux()
{
  digitalWrite(leftLightSensorPin, HIGH);
  delay(150);
  LightSensor.begin();
  LightSensor.SetAddress(Device_Address_H); //Address 0x5C
  LightSensor.SetMode(Continuous_H_resolution_Mode);
  uint16_t lux = LightSensor.GetLightIntensity(); // Get Lux value
  digitalWrite(leftLightSensorPin, LOW);
  lux = map(lux, 0, 300, 0, 100);
  return lux;
}
