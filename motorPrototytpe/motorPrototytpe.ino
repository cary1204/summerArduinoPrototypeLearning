int i;
const int enablePin = 5;
const int dirA = 4;
const int dirB = 3;

void setup() {
  pinMode(enablePin, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  Serial.begin(9600);

  digitalWrite(dirA, LOW);
  digitalWrite(dirB, HIGH);
}

void loop() {
  Serial.println("Increasing speed...");

  for (i = 0; i <= 255; i += 2) {
    analogWrite(enablePin, i);
    delay(50);
  }

  delay(2000);

  Serial.println("Decreasing speed...");


  for (i = 255; i >= 0; i -= 2) {
    analogWrite(enablePin, i);
    delay(50);
  }

  delay(1000);
