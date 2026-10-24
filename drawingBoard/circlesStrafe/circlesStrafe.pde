import processing.serial.*;

Serial myPort;
int padding = 100;
float x;
float myHeight; // 1. Declare myHeight

void setup() {
  size(1440, 900);
  myPort = new Serial(this, Serial.list()[0], 9600);
}

void draw() {
  background(20, 30, 50);

  if (myPort.available() > 0) {
    String inString = myPort.readStringUntil('\n');
    if (inString != null) {
      int value = int(trim(inString));
      println(value);
      x = map(value, 255, 0, padding, width - padding);
      myHeight = map(value, 255, 0, 150, 50);  // 2. Map to 150–50
    }
  }

  stroke(100);
  fill(100, 120, 180);
  line(padding, height/2, width - padding, height/2);
  ellipse(x, height/2, 150, myHeight);  // 3. Use myHeight
}
