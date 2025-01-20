#include "NewPing.h"
#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 400
#define BUZZER 8

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  lcd.clear();
  int ping = sonar.ping_cm();
  Serial.print("Distance = ");
  Serial.print(ping);
  Serial.println(" cm");
  lcd.print(ping);
  lcd.print(" cm ");
  lcd.print(ping / 2.54);
  lcd.print(" inch");
  delay(500);
}