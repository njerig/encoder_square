const int POWER_RIGHT_PIN = 9;
const int DIR_RIGHT_PIN = 10;
const int POWER_LEFT_PIN = 7;
const int DIR_LEFT_PIN = 8;

const int MOTOR_SPEED = 100;


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
//700

void loop() {
  driveInALine(MOTOR_SPEED, 700);
  turnClockwise(MOTOR_SPEED, 360);
}

void drive(int powerLeft, int dirLeft, int powerRight, int dirRight) {
  analogWrite(POWER_LEFT_PIN, powerLeft);
  analogWrite(DIR_LEFT_PIN, dirLeft);
  analogWrite(POWER_RIGHT_PIN, powerRight);
  analogWrite(DIR_RIGHT_PIN, dirRight);
}

void pause(int t){
  analogWrite(POWER_LEFT_PIN, 0);
  analogWrite(DIR_LEFT_PIN, 0);
  analogWrite(POWER_RIGHT_PIN, 0);
  analogWrite(DIR_RIGHT_PIN, 0);
  delay(t);
}

void driveInALine(int power, int milliseconds) {
  drive(power, 0, power, 0);
  delay(milliseconds);
  pause(1000);
}

void turnClockwise(int power, int milliseconds) {
  drive(power, 255, power, 0);
  delay(milliseconds);
  pause(1000);
}

