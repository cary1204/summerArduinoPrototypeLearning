#include <pitches.h>

const int buzzerPin = 10;

const int button1 = 3;
const int button2 = 4;
const int button3 = 5;
const int button4 = 6;
const int button5 = 7;

int note[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4}; // Notes for buttons

// STAIR AY TO HEAVEN (Led Zeppelin)
int melody1[] = {0, NOTE_C5, NOTE_E5, NOTE_A5, NOTE_B5, NOTE_E5, NOTE_C5, NOTE_B5,
                 NOTE_C6, NOTE_E5, NOTE_C5, NOTE_C6, NOTE_FS5, NOTE_D5, NOTE_A4, NOTE_FS5,
                 NOTE_E5, NOTE_C5, NOTE_A4, NOTE_C5};
int duration1[] = { 2, 5, 3, 3, 3, 3, 3, 3, 
                    3, 3, 3, 3, 3, 3, 3, 3,
                    3, 3, 3, 1};
int songSize1 = sizeof(melody1) / sizeof(melody1[0]);

// NOKIA RIGNTONE
int melody2[] = {
0, NOTE_E4, NOTE_D4, NOTE_FS3, NOTE_GS3, NOTE_CS4, NOTE_B3, NOTE_D3, NOTE_E3, NOTE_B3, NOTE_A3, NOTE_CS3, NOTE_E3, NOTE_A3};
int duration2[] = {
2, 6, 6, 4, 4, 6, 6, 4, 4, 6, 6, 4, 4, 3};
int songSize2 = sizeof(melody2) / sizeof(melody2[0]);

bool melodyPlaying = false;

void setup() {
  Serial.begin(9600);

  for (int i = 3; i <= 7; i++) {
    pinMode(i, INPUT);
  }

  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  bool b1 = digitalRead(button1) == HIGH;
  bool b2 = digitalRead(button2) == HIGH;
  bool b3 = digitalRead(button3) == HIGH;
  bool b4 = digitalRead(button4) == HIGH;
  bool b5 = digitalRead(button5) == HIGH;

  Serial.print("B1: "); Serial.print(b1);
  Serial.print("  B2: "); Serial.print(b2);
  Serial.print("  B3: "); Serial.print(b3);
  Serial.print("  B4: "); Serial.print(b4);
  Serial.print("  B5: "); Serial.println(b5);

  if (b1 && b2) {
    if (!melodyPlaying) {
      melodyPlaying = true;
      for (int i = 0; i < songSize1; i++) {
        int d = 1000 / duration1[i];
        if (melody1[i] == 0) {
          noTone(buzzerPin);
          delay(d);
        } else {
          tone(buzzerPin, melody1[i], d);
          delay(d * 1.30);
          noTone(buzzerPin);
        }
      }
    }
  }
  else if (b2 && b3) {
    if (!melodyPlaying) {
      melodyPlaying = true;
      for (int i = 0; i < songSize2; i++) {
        int d = 1000 / duration2[i];
        if (melody2[i] == 0) {
          noTone(buzzerPin);
          delay(d);
        } else {
          tone(buzzerPin, melody2[i], d);
          delay(d * 1.30);
          noTone(buzzerPin);
        }
      }
    }
  }
  else {
    melodyPlaying = false;

    if (b1) {
      tone(buzzerPin, note[0], 200);
      delay(200);
      noTone(buzzerPin);
    } else if (b2) {
      tone(buzzerPin, note[1], 200);
      delay(200);
      noTone(buzzerPin);
    } else if (b3) {
      tone(buzzerPin, note[2], 200);
      delay(200);
      noTone(buzzerPin);
    } else if (b4) {
      tone(buzzerPin, note[3], 200);
      delay(200);
      noTone(buzzerPin);
    } else if (b5) {
      tone(buzzerPin, note[4], 200);
      delay(200);
      noTone(buzzerPin);
    }
  }

  delay(10);
}
