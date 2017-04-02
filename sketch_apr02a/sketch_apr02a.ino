#include "motor.h"
#include "utSensor.h"

int Rtrig=2;
int Recho=3;
int Ctrig=8;
int Cecho=9;
int Ltrig=7;
int Lecho=10;
void setup()
{
  // put your setup code here, to run once:
  // pinMode(13, OUTPUT);
  setupMotor();
  pinMode(Rtrig, OUTPUT);
  pinMode(Recho, INPUT);
   pinMode(Ctrig, OUTPUT);
  pinMode(Cecho, INPUT);
  pinMode(Ltrig, OUTPUT);
  pinMode(Lecho, INPUT);
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
  long int Rdistance=detectDistance(Rtrig,Recho);
  // Serial.print("right ");
  // Serial.print(Rdistance);
  // Serial.println(" cm");

  long int Cdistance=detectDistance(Ctrig,Cecho);
  // Serial.print("center ");
  // Serial.print(Cdistance);
  // Serial.println(" cm");
  

  long int Ldistance=detectDistance(Ltrig,Lecho);
  // Serial.print("left ");
  // Serial.print(Ldistance);
  // Serial.println(" cm");



}
