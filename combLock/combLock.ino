// and is && and || is or
int attempt = 0;
int value1 = LOW;
int value2 = LOW;
int value3 = LOW;
int value4 = LOW;
const int redPin = 10;
const int greenPin = 13;
const int button1 = 4;
const int button2 = 5;
const int button3 = 6;
const int button4 = 7;
const int combination = 6;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  digitalWrite(10 , LOW);
  digitalWrite(13 , LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  value1 = digitalRead(button1);
  value2 = digitalRead(button2);
  value3 = digitalRead(button3);
  value4 = digitalRead(button4);
  Serial.print("Value1: "); Serial.print(value1);
  Serial.print("Value2: "); Serial.print(value2);
  Serial.print("Value3: "); Serial.print(value3);
  Serial.print("Value4: "); Serial.print(value4);
  Serial.print("Attempt: "); Serial.println(attempt);
  if (attempt == 0 && value1 == HIGH) {
    attempt++;
    delay(150);
  }
  else if (attempt == 1 && value2 == HIGH) {
    attempt++;
    delay(150);
  }
  else if (attempt == 2 && value1 == HIGH) {
    attempt++;
    delay(150);
  }
  else if (attempt == 3 && value3 == HIGH) {
    attempt++;
    delay(150);
  }
  else if (attempt == 4 && value4 == HIGH) {
    attempt++;
    delay(150);
  }
  else if (attempt == 5 && value2 == HIGH) {
    attempt++;
    delay(150);
  }
  else if (value1 == HIGH || value2 == HIGH || value3 == HIGH || value4 == HIGH) {
    attempt = 0;
    digitalWrite(redPin, HIGH);
    delay(500);
    digitalWrite(redPin, LOW);
  }

  if (attempt == combination) {
    digitalWrite(greenPin, HIGH);
    delay(1000);
    digitalWrite(greenPin, LOW);
    attempt = 0;
    delay(100);
    }

  delay(50);
}
