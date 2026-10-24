#include <Servo.h>
#include <IRremote.h>
int TRIG_PIN = 11;
int ECHO_PIN = 12;
int SERVO_PIN = 6;
int BUZZER_PIN = 7;
int RED_LED = 9;
int GREEN_LED = 8;
int IR_PIN = 10;
int BUTTON_PIN = 13;
Servo lockServo;
IRrecv irrecv(IR_PIN);
decode_results results;
const unsigned long IR_POWER = 0xFFA25D;   // Power button
const unsigned long IR_UNLOCK = 0xFF30CF;  //1
const int LOCKED_POS = 0;
const int UNLOCKED_POS = 90;
const int DISTANCE_THRESHOLD = 2;
bool isArmed = false;
bool isLocked = false;
bool isBuzzing = false;
bool lastButtonState = HIGH;
unsigned long pressStartTime = 0;
bool buttonHeld = false;
void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lockServo.attach(SERVO_PIN);
  irrecv.enableIRIn();
  unlockSafe();
  isArmed = false;
  updateLEDs();
}
void loop() {
  doIR();
  butPres();
  breaakOpen();
  updateLEDs();
  Serial.print("Distance: ");
  Serial.print(getDistance());
  Serial.println(" cm");
  delay(50);
}
void butPres() {
  bool reading = digitalRead(BUTTON_PIN);
  if (reading == LOW && lastButtonState == HIGH) {
    pressStartTime = millis();
    buttonHeld = false;
  }

  if (reading == LOW && (millis() - pressStartTime >= 500) && !buttonHeld) {
    buttonHeld = true;
    isArmed = !isArmed;
    Serial.println(isArmed ? "Armed via button" : "Disarmed via button");
  }
  lastButtonState = reading;
}
void doIR() {
  if (!isArmed && !isBuzzing) return;

  if (irrecv.decode(&results)) {
    Serial.print("IR Received: ");
    Serial.println(results.value, HEX);

    if (results.value == IR_POWER && !isLocked && dorCliose() && isArmed) {
      lockSafe();
      Serial.println("Locked via remote");
    } 
    else if (results.value == IR_UNLOCK && isLocked) {
      unlockSafe();
      isArmed = false;
      isBuzzing = false;
      digitalWrite(BUZZER_PIN, LOW);
      Serial.println("Unlocked and disarmed via remote");
    }

    irrecv.resume();
  }
}
void breaakOpen() {
  if (isArmed && isLocked && !dorCliose()) {
    if (!isBuzzing) {
      isBuzzing = true;
      Serial.println("breaakOpen DETECTED!");
    }
    digitalWrite(BUZZER_PIN, HIGH);
  } else if (!isBuzzing) {
    digitalWrite(BUZZER_PIN, LOW);
  }
}
bool dorCliose() {
  long distance = getDistance();
  return (distance > 0 && distance <= DISTANCE_THRESHOLD);
}
long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}
void lockSafe() {
  isLocked = true;
  lockServo.write(LOCKED_POS);
  buzTwo();
}
void unlockSafe() {
  isLocked = false;
  lockServo.write(UNLOCKED_POS);
  buzTwo();
}
void updateLEDs() {
  digitalWrite(RED_LED, isArmed ? HIGH : LOW);
  digitalWrite(GREEN_LED, !isLocked ? HIGH : LOc:\Users\Cary\Documents\Arduino\LCDPrototypeMagic8Ball\LCDPrototypeMagic8Ball.inoW);
}
void buzTwo() {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    delay(100);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    delay(100);
}
