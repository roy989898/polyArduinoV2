#include "motor.h"
#include "utSensor.h"
// #include "lightSensor.h" // Sensor Library
#include "lightSensorV2.h"

int Rtrig = 2;
int Recho = 3;
int Ctrig = 8;
int Cecho = 9;
int Ltrig = 7;
int Lecho = 10;

long int Rdistance = 0;
long int Cdistance = 0;
long int Ldistance = 0;
void detectAllDistance()
{
  Rdistance = detectDistance(Rtrig, Recho);
  /*Serial.print("right ");
    Serial.print(Rdistance);
    Serial.println(" cm");*/

  Cdistance = detectDistance(Ctrig, Cecho);
  /*Serial.print("center ");
    Serial.print(Cdistance);
    Serial.println(" cm");
  */
  Ldistance = detectDistance(Ltrig, Lecho);
  /*Serial.print("left ");
    Serial.print(Ldistance);
    Serial.println(" cm");*/
}

void decideTheAvoidMotion(long int Ldistance, long int Cdistance, long int Rdistance)
{

  if (Cdistance < 8)
  {
    Serial.println("center distance <<<<<<<<<8");
    // has something in front of the car
    if (Ldistance > Rdistance)
    {
      while (Cdistance < 8)
      {
        Serial.println("at back left");
        leftMotorMoveBack(255);
        rightMotorMoveFont(0);
        detectAllDistance();
      }
    }
    else
    {
      while (Cdistance < 8)
      {
        Serial.println("at back right");
        rightMotorMoveBack(255);
        leftMotorMoveBack(0);
        detectAllDistance();
      }
    }
  }
  else
  {
    Serial.println("Normal mode");
    // nothing in front of the car
    leftMotorMoveFont(map(Rdistance, 0, 100, 50, 255));
    rightMotorMoveFont(map(Ldistance, 0, 100, 50, 255));
  }
}
void setup()
{
  // put your setup code here, to run once:
  // pinMode(13, OUTPUT);
  lightv2Setup();
  setupMotor();
  pinMode(Rtrig, OUTPUT);
  pinMode(Recho, INPUT);
  pinMode(Ctrig, OUTPUT);
  pinMode(Cecho, INPUT);
  pinMode(Ltrig, OUTPUT);
  pinMode(Lecho, INPUT);
  Serial.begin(9600);

  // lightSensorSetUp();
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

  /*  detectAllDistance();
  decideTheAvoidMotion(Ldistance, Cdistance, Rdistance);*/

  lightv2Show();
}
