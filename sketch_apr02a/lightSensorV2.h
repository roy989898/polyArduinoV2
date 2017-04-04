#include <Wire.h>
#include "Arduino.h"
int BH1750_address0 = 0x23; // i2c Addresse
int BH1750_address1 = 0x5C; // i2c Addresse
byte buff[2];

// VCC >>> 3.3V
//
// SDA >>> A4
//
// SCL >>> A5
//
// addr >> A3 "Optional and use address 0x23 "
//
// Gnd >>>Gnd

void BH1750_Init(int address)
{
    Wire.beginTransmission(address);
    Wire.write(0x10); // 1 [lux] aufloesung
    Wire.endTransmission();
}

byte BH1750_Read(int address)
{
    byte i = 0;
    Wire.beginTransmission(address);
    Wire.requestFrom(address, 2);
    while (Wire.available())
    {
        buff[i] = Wire.read();
        i++;
    }
    Wire.endTransmission();
    return i;
}
void lightv2Setup()
{
    Wire.begin();
    BH1750_Init(BH1750_address0);
    BH1750_Init(BH1750_address1);
    delay(200);
    Serial.begin(9600);
}

void lightv2Show()
{
    float val = 0;
    if (BH1750_Read(BH1750_address0) == 2)
    {
        val = ((buff[0] << 8) | buff[1]) / 1.2;
        if (val < 0)
            Serial.print("> 65535");
        else
            Serial.print((int)val, DEC);
        Serial.println(" lx on Sensor 0");
    }
    if (BH1750_Read(BH1750_address1) == 2)
    {
        val = ((buff[0] << 8) | buff[1]) / 1.2;
        if (val < 0)
            Serial.print("> 65535");
        else
            Serial.print((int)val, DEC);
        Serial.println(" lx on Sensor 1");
    }
    delay(1000);
}


