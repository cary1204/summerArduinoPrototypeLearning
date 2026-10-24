const int bluePin = 8;
const int greenPin = 9;
const int redPin = 10;

int redValue;
int greenValue;
int blueValue;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop(){  
  //C 255
  redValue = 255; 
  greenValue = 0;
  blueValue = 0;
    
  for(int i = 0; i < 255; i++){ 
    redValue--; 
    greenValue++; // Fade In (green)
    analogWrite(redPin, redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);
    delay(10); //  0.01 
  }  
  redValue = 0; 
  greenValue = 255;
  blueValue = 0;
    
  for(int i = 0; i < 255; i++){ /
   
    greenValue--;
    
    blueValue++;
    analogWrite(redPin, redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);
    
    delay(10);
  }
  redValue = 0; 
  greenValue = 0;
  blueValue = 255;
  
  for(int i = 0; i < 255; i++){ /
    
    blueValue --;
   
    redValue ++;
    analogWrite(redPin, redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);
    
    delay(10);
  }

}

