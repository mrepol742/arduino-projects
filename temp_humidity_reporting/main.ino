#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// DHT sensor data pin
#define DHT11_PIN 2
// DHT type
#define DHTTYPE DHT11
DHT dht(DHT11_PIN, DHTTYPE);

// using I2C LCD Display A4 & A5
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    lcd.clear();
    lcd.print("Sensor Error!");
    return delay(2000);
  }

  lcd.clear();

  // first row (temp)
  lcd.setCursor(0, 0);
  lcd.print("Temp   ");
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C");

  // second row (hum)
  lcd.setCursor(0, 1);
  lcd.print("Hum    ");
  lcd.print(humidity);
  lcd.print("%");

  delay(5000);
}
