// code is a bit of a mess, didnt bother to indent it for betting reading, good luck reading it
// added some changes make it more like a hour glass
// see video in the same folder
// video format: .mp4

unsigned long previousTime = 0;
long interval = 500; //Time to wait before changing to the next LED (1000 = 1 second, so 10000 = 10 seconds)
int led = 1;
int switchState = 0;
int prevSwitchState = 0;
void setup() {

  for(int x = 2; x < 8; x++){
    pinMode(x, OUTPUT);
  }
  pinMode(8, INPUT);
}

void loop() {
  prevSwitchState = switchState;
  unsigned long currentTime = millis();
  if (currentTime - previousTime > interval){
    previousTime = currentTime;
    if (digitalRead(8) == LOW) {
      digitalWrite(led, HIGH);
      if (led < 8){led++;}
      if(led > 7){
        digitalWrite(7, HIGH);
        delay(750);
        digitalWrite(7, LOW);
        delay(750);
    }
    }
    if (digitalRead(8) == HIGH) {
      digitalWrite(led, LOW);
      if (led > 1){led--;}
      if(led < 2){
        
        digitalWrite(2, HIGH);
        delay(750);
        digitalWrite(2, LOW);
        delay(750);
    }
    }
  }
} 

