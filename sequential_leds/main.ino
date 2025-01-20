int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;
int LED5 = 9;
int LED6 = 8;

int POT;
int LED7;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  POT = analogRead(A0);
  LED7 = map(POT, 0, 1023, 0, 255);

  analogWrite(5, LED7);

  digitalWrite(LED1, HIGH);
  delay(200);
  digitalWrite(LED2, HIGH);
  delay(200);
  digitalWrite(LED3, HIGH);
  delay(200);
  digitalWrite(LED4, HIGH);
  delay(200);
  digitalWrite(LED5, HIGH);
  delay(200);
  digitalWrite(LED6, HIGH);
  delay(200);
  digitalWrite(LED1, LOW);
  delay(300);
  digitalWrite(LED2, LOW);
  delay(300);
  digitalWrite(LED3, LOW);
  delay(300);
  digitalWrite(LED4, LOW);
  delay(300);
  digitalWrite(LED5, LOW);
  delay(300);
  digitalWrite(LED6, LOW);
  delay(300);

  digitalWrite(LED1, HIGH);
  delay(200);
  digitalWrite(LED1, LOW);
  delay(200);

  digitalWrite(LED2, LOW);
  delay(200);
  digitalWrite(LED2, HIGH);
  delay(200);

  digitalWrite(LED3, HIGH);
  delay(200);
  digitalWrite(LED3, LOW);
  delay(200);

  digitalWrite(LED4, LOW);
  delay(200);
  digitalWrite(LED4, HIGH);
  delay(200);

  digitalWrite(LED5, HIGH);
  delay(200);
  digitalWrite(LED5, LOW);
  delay(200);

  digitalWrite(LED6, LOW);
  delay(200);
  digitalWrite(LED6, HIGH);
  delay(200);
}