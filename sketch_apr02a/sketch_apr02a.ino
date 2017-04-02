#include "motor.h"

void setup()
{
  // put your setup code here, to run once:
  // pinMode(13, OUTPUT);
  setupMotor();
}

void loop()
{
  // put your main code here, to run repeatedly:
  // digitalWrite(13, HIGH);
  // delay(1000);
  // digitalWrite(13, LOW);
  // delay(1000);

  rightMotorMoveBack(200);
  leftMotorMoveFont(200);
  delay(2000);
  rightMotorMoveBack(0);
  leftMotorMoveFont(0);
  delay(2000);
}
