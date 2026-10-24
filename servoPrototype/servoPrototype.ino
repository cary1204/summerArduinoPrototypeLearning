#include <Servo.h>

Servo myServo;
const int potPin = A0;
int angle = 0;

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT); 
  myServo.attach(9); 

  for (int i = 0; i < 180; i++) {
    myServo.write(i);
    delay(10);
  }
  for (int i = 180; i > 0; i--) {
    myServo.write(i);
    delay(10);
  }

  myServo.write(0);
  delay(500);
  myServo.write(45);
  delay(500);
  myServo.write(90);
  delay(500);
  myServo.write(135);
  delay(500);
  myServo.write(180);
  delay(500);
}

void loop() {
 
  for (angle = 0; angle <= 180; angle++) {
    myServo.write(angle);
    delay(15);
  }

  myServo.write(0);
  delay(500);
}
