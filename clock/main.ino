#include <virtuabotixRTC.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
virtuabotixRTC rtcv(6, 7, 8);
int LED = 4;

void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  // seconds, minutes, hours, day of the week, day of the month, month, year
  rtcv.setDS1302Time(18, 10, 10, 7, 18, 7, 2023);
  pinMode(LED, OUTPUT);
}
void loop()
{
  digitalWrite(LED, HIGH);
  rtcv.updateTime();
  lcd.clear();
  lcd.print(rtcv.month);
  lcd.print("/");
  lcd.print(rtcv.dayofmonth);
  lcd.print("/");
  lcd.print(rtcv.year);
  lcd.print("  ");
  lcd.print(rtcv.hours);
  lcd.print(":");
  lcd.print(rtcv.minutes);
  lcd.print(":");
  lcd.print(rtcv.seconds);
  lcd.print(":");
  digitalWrite(LED, LOW);
  delay(500);
}