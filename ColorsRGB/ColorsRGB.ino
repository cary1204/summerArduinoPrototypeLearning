const int redPin = 11;

const int greenPin= 9;

const int bluePin= 8;
int redValue = 0;

int blueValue = 0;

int greenValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);

  pinMode(bluePin, OUTPUT);

  pinMode(greenPin, OUTPUT);
}

void loop() {
//Red

  analogWrite(redPin, 255);

  analogWrite(greenPin, 0);

  analogWrite(bluePin, 0);

  delay(500);

  //Red

  analogWrite(redPin, 0);

  analogWrite(greenPin, 255);

  analogWrite(bluePin, 0);

  delay(500);
  
    //blue

  analogWrite(redPin, 0);

  analogWrite(greenPin, 0);

  analogWrite(bluePin, 255);

  delay(500);

      //yellow

  analogWrite(redPin, 255);

  analogWrite(greenPin, 255);

  analogWrite(bluePin, 0);

  delay(500);

        //orange

  analogWrite(redPin, 255);

  analogWrite(greenPin, 100);

  analogWrite(bluePin, 0);

  delay(500);

          //purple

  analogWrite(redPin, 128);

  analogWrite(greenPin, 0);

  analogWrite(bluePin, 128);

  delay(500);

        //white

  analogWrite(redPin, 255);

  analogWrite(greenPin, 255);

  analogWrite(bluePin, 255);

  delay(500);
          //pink

  analogWrite(redPin, 255);

  analogWrite(greenPin, 51);

  analogWrite(bluePin, 255);

  delay(500);
            //cyan

  analogWrite(redPin, 102);

  analogWrite(greenPin, 255);

  analogWrite(bluePin, 255);

  delay(500);
  }
