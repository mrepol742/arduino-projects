#include <Servo.h>

Servo Servo1;

int servoPin = 8;
int potPin = A0;

void setup()
{
  Serial.begin(9600);
  Servo1.attach(servoPin);
}

void loop()
{
  int reading = analogRead(potPin);
  Serial.println(reading);
  int angle = map(reading, 0, 1023, 0, 180);
  Servo1.write(angle);
}