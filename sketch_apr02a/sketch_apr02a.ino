#include "motor.h"
#include "utSensor.h"

int trig=2;
int echo=3;
void setup()
{
  // put your setup code here, to run once:
  // pinMode(13, OUTPUT);
  setupMotor();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);  
}

void loop()
{
  // put your main code here, to run repeatedly:
  // digitalWrite(13, HIGH);
  // delay(1000);
  // digitalWrite(13, LOW);
  // delay(1000);

// test motor code
  // rightMotorMoveBack(200);
  // leftMotorMoveFont(200);
  // delay(2000);
  // rightMotorMoveBack(0);
  // leftMotorMoveFont(0);
  // delay(2000);

  // test ultra sensor code
  long int distance=detectDistance(trig,echo);
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);   
}
