// Projet plus complexe : trieur d'objets par couleur.
// Capteur type TCS3200/TCS230 + deux servos.
// Les valeurs changent beaucoup selon la lumiere, donc il faut calibrer.

#include <Servo.h>

Servo gateServo;
Servo trayServo;

const int s2 = 4;
const int s3 = 5;
const int sensorOut = 6;

int readColorPulse(int modeA, int modeB)
{
  digitalWrite(s2, modeA);
  digitalWrite(s3, modeB);
  delay(60);
  return pulseIn(sensorOut, LOW);
}

void setup()
{
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(sensorOut, INPUT);

  gateServo.attach(9);
  trayServo.attach(10);
  gateServo.write(20);
  trayServo.write(90);

  Serial.begin(9600);
}

void loop()
{
  int redValue = readColorPulse(LOW, LOW);
  int blueValue = readColorPulse(LOW, HIGH);
  int greenValue = readColorPulse(HIGH, HIGH);

  Serial.print("R:");
  Serial.print(redValue);
  Serial.print(" G:");
  Serial.print(greenValue);
  Serial.print(" B:");
  Serial.println(blueValue);

  // Sur ce capteur, une valeur plus petite veut souvent dire couleur plus forte.
  if (redValue < greenValue && redValue < blueValue)
    trayServo.write(40);
  else if (blueValue < redValue && blueValue < greenValue)
    trayServo.write(140);
  else
    trayServo.write(90);

  delay(400);
  gateServo.write(80);
  delay(350);
  gateServo.write(20);
  delay(700);
}
