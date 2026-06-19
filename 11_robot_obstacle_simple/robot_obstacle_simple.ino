// Robot tres simple qui evite les obstacles.
// Materiel : HC-SR04 + pont en H L298N ou L293D + 2 moteurs DC.

const int trigPin = 8;
const int echoPin = 9;

const int leftMotor = 5;
const int rightMotor = 6;

long distanceCm()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long time = pulseIn(echoPin, HIGH, 25000);
  if (time == 0)
    return 999;
  return time * 0.034 / 2;
}

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
}

void loop()
{
  long dist = distanceCm();

  if (dist > 25)
  {
    analogWrite(leftMotor, 180);
    analogWrite(rightMotor, 180);
  }
  else
  {
    analogWrite(leftMotor, 0);
    analogWrite(rightMotor, 180);
    delay(450);
  }
}
