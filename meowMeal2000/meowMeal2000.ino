#include <Servo.h>

Servo myServo;

int trigPin = 11;
int echoPin = 12;

void setup() {
  Serial.begin(9600);
  myServo.attach(6);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float getDistanceCM() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}

void loop() {
  // Sweep servo 0° -> 180° -> 0°
  for (int angle = 0; angle <= 180; angle += 3) {
    myServo.write(angle);
    delay(20); // allow servo to reach position
    float distance = getDistanceCM();
    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
  }

  for (int angle = 180; angle >= 0; angle -= 3) {
    myServo.write(angle);
    delay(20);
    float distance = getDistanceCM();
    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
  }
}
