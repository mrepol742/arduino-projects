#include <SPI.h>
#include <RFID.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

RFID rfid(10, 9);
LiquidCrystal_I2C lcd(0x27, 16, 2);
unsigned char status;
unsigned char str[MAX_LEN];

String rfidList[1] = {
    "159253514"};
int totalAccess = 1;

Servo lockServo;
int lockPos = 15;
int unlockPos = 75;
boolean locked = true;

int redLEDPin = 5;
int greenLEDPin = 6;

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  lcd.begin();
  lcd.backlight();
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  digitalWrite(redLEDPin, HIGH);
  delay(200);
  digitalWrite(greenLEDPin, HIGH);
  delay(200);
  digitalWrite(redLEDPin, LOW);
  delay(200);
  digitalWrite(greenLEDPin, LOW);
  lockServo.attach(3);
  lockServo.write(lockPos);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Tap the card");
}

void loop()
{
  if (rfid.findCard(PICC_REQIDL, str) == MI_OK)
  {
    String temp = "";
    if (rfid.anticoll(str) == MI_OK)
    {
      for (int i = 0; i < 4; i++)
      {
        temp = temp + (0x0F & (str[i] >> 4));
        temp = temp + (0x0F & str[i]);
      }
      checkAccess(temp);
    }
    rfid.selectTag(str);
  }
  rfid.halt();
}

void checkAccess(String temp)
{
  boolean granted = false;
  int j;
  for (int i = 0; i <= (totalAccess - 1); i++)
  {
    j = i;
    if (rfidList[i] == temp)
    {
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Welcome");
      delay(500);
      granted = true;
      if (locked == true)
      {
        lockServo.write(unlockPos);
        locked = false;
      }
      else if (locked == false)
      {
        lockServo.write(lockPos);
        locked = true;
      }
      digitalWrite(greenLEDPin, HIGH);
      delay(200);
      digitalWrite(greenLEDPin, LOW);
      delay(200);
      digitalWrite(greenLEDPin, HIGH);
      delay(200);
      digitalWrite(greenLEDPin, LOW);
      delay(200);
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Tap the card");
    }
  }
  if ((totalAccess - 1) == j && granted == false)
  {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Access Denied");
    delay(300);
    tone(0, 460);
    delay(200);
    noTone(1);
    delay(200);
    digitalWrite(0, HIGH);
    digitalWrite(redLEDPin, HIGH);
    delay(200);
    digitalWrite(redLEDPin, LOW);
    delay(200);
    digitalWrite(redLEDPin, HIGH);
    delay(200);
    digitalWrite(redLEDPin, LOW);
    delay(200);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Tap the card");
  }
}