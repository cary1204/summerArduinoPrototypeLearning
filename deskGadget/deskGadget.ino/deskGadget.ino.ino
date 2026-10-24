#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String input = "";

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\n') {         // end of line
      displayData(input);
      input = "";
    } else {
      input += c;
    }
  }
}

void displayData(String data) {
  int split = data.indexOf('|');

  if (split == -1) return;  // invalid packet

  String line1 = data.substring(0, split);
  String line2 = data.substring(split + 1);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);

  lcd.setCursor(0, 1);
  lcd.print(line2);
}