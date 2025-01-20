#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int analogInPin = A0;
int sensorValue = 0;

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop()
{

  sensorValue = analogRead(analogInPin);
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\n");

  delay(2);

  if (sensorValue <= 100)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    lcd.print("Lvl: Dry ");
    lcd.print(sensorValue);
  }
  else if (sensorValue < 250)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    lcd.print("Lvl: Wet ");
    lcd.print(sensorValue);
  }
  else if (sensorValue < 420)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    lcd.print("Lvl: Partial ");
    lcd.print(sensorValue);
  }
  else
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    lcd.print("Lvl: Full ");
    lcd.print(sensorValue);
  }

  delay(500);
  lcd.clear();
}