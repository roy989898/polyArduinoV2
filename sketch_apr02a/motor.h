#include "Arduino.h"

int inPMW1 = 5;
int in2 = 12;
int in3PMW = 6;
int in4 = 13;

// pinMode(int1,OUTPUT);
// pinMode(int2,OUTPUT);
// pinMode(in3,OUTPUT);
// pinMode(in4,OUTPUT);

// when int3>in4,move back,right
void setupMotor()
{
  pinMode(inPMW1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3PMW, OUTPUT);
  pinMode(in4, OUTPUT);
}

void leftMotorMove(int outPmw3, int out4)
{
  analogWrite(in3PMW, outPmw3);
  digitalWrite(in4, out4);
}

void leftMotorMoveBack(int pmw)
{
  leftMotorMove(pmw, 0);
}

void leftMotorMoveFont(int pmw)
{
  leftMotorMove(255 - pmw, 1);
}

void rightMotorMove(int outPmw1, int out2)
{
  analogWrite(inPMW1, outPmw1);
  digitalWrite(in2, out2);
}

void rightMotorMoveBack(int pmw)
{
  rightMotorMove(pmw, 0);
}

void rightMotorMoveFont(int pmw)
{
  rightMotorMove(255 - pmw, 1);
}

void mototMoveFont(int pmw)
{
  rightMotorMoveFont(pmw);
  leftMotorMoveFont(pmw);
}

void motorMoveBack(int pmw)
{
  rightMotorMoveBack(pmw);
  leftMotorMoveBack(pmw);
}

void motorMoveLeft(int pmw)
{
  rightMotorMoveFont(pmw);
  leftMotorMoveBack(0);
}

void motorMoveRight(int pmw)
{
  leftMotorMoveFont(pmw);
  rightMotorMoveFont(0);
}

void motorStop()
{
  leftMotorMoveBack(0);
  rightMotorMoveFont(0);
}
