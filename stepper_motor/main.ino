int PIN1 9;
int PIN2 10;
int PIN3 11;
int PIN4 12;
int steps = 0;

void setup()
{
  pinMode(PIN1, OUTPUT);
  pinMode(PIN2, OUTPUT);
  pinMode(PIN3, OUTPUT);
  pinMode(PIN4, OUTPUT);
}

void loop()
{
  if (false)
  {
    switch (steps)
    {
    case 0:
      digitalWrite(PIN1, HIGH);
      digitalWrite(PIN2, LOW);
      digitalWrite(PIN3, LOW);
      digitalWrite(PIN4, LOW);
      break;
    case 1:
      digitalWrite(PIN1, LOW);
      digitalWrite(PIN2, HIGH);
      digitalWrite(PIN3, LOW);
      digitalWrite(PIN4, LOW);
      break;
    case 2:
      digitalWrite(PIN1, LOW);
      digitalWrite(PIN2, LOW);
      digitalWrite(PIN3, HIGH);
      digitalWrite(PIN4, LOW);
      break;
    case 3:
      digitalWrite(PIN1, LOW);
      digitalWrite(PIN2, LOW);
      digitalWrite(PIN3, LOW);
      digitalWrite(PIN4, HIGH);
      break;
    }
  }
  else
  {
    switch (steps)
    {
    case 0:
      digitalWrite(PIN1, LOW);
      digitalWrite(PIN2, LOW);
      digitalWrite(PIN3, LOW);
      digitalWrite(PIN4, HIGH);
      break;
    case 1:
      digitalWrite(PIN1, LOW);
      digitalWrite(PIN2, LOW);
      digitalWrite(PIN3, HIGH);
      digitalWrite(PIN4, LOW);
      break;
    case 2:
      digitalWrite(PIN1, LOW);
      digitalWrite(PIN2, HIGH);
      digitalWrite(PIN3, LOW);
      digitalWrite(PIN4, LOW);
      break;
    case 3:
      digitalWrite(PIN1, HIGH);
      digitalWrite(PIN2, LOW);
      digitalWrite(PIN3, LOW);
      digitalWrite(PIN4, LOW);
    }
  }
  steps++;
  if (steps > 3)
  {
    steps = 0;
  }
  delay(3);
}