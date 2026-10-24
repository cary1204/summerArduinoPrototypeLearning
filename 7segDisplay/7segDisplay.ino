byte seven_seg_digits[10] = { B11111100,  // = 0
                              B01100000,  // = 1
                              B11011010,  // = 2
                              B11110010,  // = 3
                              B01100110,  // = 4
                              B10110110,  // = 5
                              B10111110,  // = 6
                              B11100000,  // = 7
                              B11111110,  // = 8
                              B11100110   // = 9
                             };


const int latchPin = 3;
const int clockPin = 4;
const int dataPin = 2;



void setup() {
  // put your setup code here, to run once:
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
}

void sevenSegWrite(byte digit){

digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);
digitalWrite(latchPin, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
for(byte digit = 10; digit > 0; digit--){
delay(1000);
sevenSegWrite(digit-1);
}
delay(3000);
}
