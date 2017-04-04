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
BH1750FVI rightSensor;
BH1750FVI leftSensor;
void lightSensorSetUp()
{

  rightSensor.begin();
  leftSensor.begin();
  rightSensor.SetAddress(Device_Address_H); //addr connect to 5v
  // To adjust the slave on other address , uncomment this line
  leftSensor.SetAddress(Device_Address_L); //addr connect to GND
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
  rightSensor.SetMode(Continuous_H_resolution_Mode);
  leftSensor.SetMode(Continuous_H_resolution_Mode);
}

uint16_t getLeftLightSensorLux()
{
  uint16_t lux = leftSensor.GetLightIntensity(); // Get Lux value
  lux = map(lux, 0, 300, 0, 100);
  return lux;
}

uint16_t getrightLightSensorLux()
{
  uint16_t lux = rightSensor.GetLightIntensity(); // Get Lux value
  lux = map(lux, 0, 300, 0, 100);
  return lux;
}
