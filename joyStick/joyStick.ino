#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 6, 7, 8, 9);
const int switchPin = 12;
const int xPin = A0;
const int yPin = A1;

int cursorX = 0;
int cursorY = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  lcd.print("Move the X with joystick");
  delay(1000);
  lcd.clear();
  lcd.setCursor(cursorX, cursorY);
  lcd.print("X");
}

void loop() {
  // put your main code here, to run repeatedly:
  int currentX = analogRead(xPin);
  int currentY = analogRead(yPin);
  int buttonState = digitalRead(12);

  // LEFT
  if (currentX < 400) {
    if (cursorX > 0) {
      cursorX--;
    }
  }

  // RIGHT
  if (currentX > 600) {
    if (cursorX < 15) {
      cursorX++;
    }
  }

  // DOWN
  if (currentY < 400) {
    if (cursorY > 0) {
      cursorY--;
    }
  }

  // UP
  if (currentY > 600) {
    if (cursorY < 1) {
      cursorY++;
    }
  }
  // RS
    if (buttonState == LOW) {
    cursorX = 0;
    cursorY = 0;
  }

  lcd.clear();
  lcd.setCursor(cursorX, cursorY);
  lcd.print("x");

  delay(150);
}
