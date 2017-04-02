

// need set up

// pinMode(trig, OUTPUT);
// pinMode(echo, INPUT);
#include "Arduino.h"

void Trig(int trig)
{
    digitalWrite(trig, 0);
    delayMicroseconds(2);
    digitalWrite(trig, 1);
    delayMicroseconds(10);
    digitalWrite(trig, 0);
}

long int hearEcho(int echo)
{
    return pulseIn(echo, HIGH);
}

long int microToCm(long int micro)
{
    return micro * 304 * 100 / 2 / 1000000;
}

long int detectDistance(int trig, int echo)
{
    Trig(trig);
    long int duration = hearEcho(echo);
    long int distance = microToCm(duration);

    return distance;
}
