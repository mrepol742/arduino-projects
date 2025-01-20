#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.begin();
  lcd.backlight();
}

void loop()
{
  lcd.clear();
  lcd.print("Hello World!");
  delay(1000);
  lcd.clear();
  lcd.print("I'm Mj an AI");
  lcd.setCursor(3, 1);
  lcd.print("created by");
  delay(1000);
  lcd.clear();
  lcd.print("Melvin Jones Repol");
  delay(1000);
  lcd.clear();
  lcd.print("How can i help");
  lcd.setCursor(3, 1);
  lcd.print("you?");
  delay(1000);
  lcd.clear();
  lcd.print("mrepol742.github.io");
  delay(1000);
  lcd.clear();
}
