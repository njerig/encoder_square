#include <Encoder.h>

const int POWER_RIGHT_PIN = 9;
const int DIR_RIGHT_PIN = 10;
const int POWER_LEFT_PIN = 7;
const int DIR_LEFT_PIN = 8;

const int ENC_RIGHT_PIN[] = { 24, 25 };
const int ENC_LEFT_PIN[] = { 26, 27 };

Encoder encLeft(ENC_LEFT_PIN[0], ENC_LEFT_PIN[1]);
Encoder encRight(ENC_RIGHT_PIN[0], ENC_RIGHT_PIN[1]);

long oldPositionLeft = 0;
long oldPositionRight = 0;
long newPositionLeft;
long newPositionRight;

void setup() {
  Serial.begin(9600);
  while(Serial);
  delay(1000);
  pinMode(POWER_LEFT_PIN, OUTPUT);
  pinMode(DIR_LEFT_PIN, OUTPUT);
  pinMode(POWER_RIGHT_PIN, OUTPUT);
  pinMode(DIR_RIGHT_PIN, OUTPUT);
  Serial.println("Do The Thing:");
}

int printEncoderPosition(int powerLeft, int dirLeft, int powerRight, int dirRight) {
  analogWrite(POWER_LEFT_PIN, powerLeft);
  analogWrite(DIR_LEFT_PIN, dirLeft);
  analogWrite(POWER_RIGHT_PIN, powerRight);
  analogWrite(DIR_RIGHT_PIN, dirRight);
  
  newPositionLeft = encLeft.read();
  newPositionRight = encRight.read();
  if (newPositionLeft != oldPositionLeft || newPositionRight != oldPositionRight) {
    Serial.print("Left = ");
    Serial.print(newPositionLeft);
    Serial.print(", Right = ");
    Serial.print(newPositionRight);
    Serial.println();
    oldPositionLeft = newPositionLeft;
    oldPositionRight = newPositionRight;
  }
  delay(1000);
  return 0;
}

void loop() {
  printEncoderPosition(80, 255, 80, 255);
}

