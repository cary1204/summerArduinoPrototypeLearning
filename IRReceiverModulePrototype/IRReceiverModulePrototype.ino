#include "IRremote.h"

int receiver = 7; // Signal Pin of IR receiver to Arduino Digital Pin 11

/*-----( Declare objects )-----
Both of these are coming from the library that we included up above.*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void setup(){   
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver
}


void loop() {  
  if (irrecv.decode(&results)){ // Checks if a button was pressed
    translateIR(); //This calls the method below that to display the correct message to the Serial Monitor
    irrecv.resume(); // receive the next value
  }  
}

/*-----( Function )-----
  Functions are created to simplify code and make programs easier to use and read.
  Functions can be used when a large section of code need to be used multiple times.*/
void translateIR(){ // takes action based on IR code received
  // describing Remote IR codes 
  switch(results.value){

    /* THIS IS THE ONLY PART YOU CHANGE:
    Use the chart provided in the lesson to fill in the print statements.
    The chart is not in the same order as the cases found here. 
    Be sure to double check the values*/
    case 0xFFA25D: Serial.println("POWER");  break;
    case 0xFFE21D: Serial.println("FUNC/STOP");  break;
    case 0xFF629D: Serial.println("VOLUME+");  break;
    case 0xFF22DD: Serial.println("<< (FAST REWIND)");  break;
    case 0xFF02FD: Serial.println(">|| PAUSE");  break;
    case 0xFFC23D: Serial.println(">> (FAST FORWARD)	");  break;
    case 0xFFE01F: Serial.println("- (DOWN)");  break;
    case 0xFFA857: Serial.println("VOLUME -");  break;
    case 0xFF906F: Serial.println("+ (UP)");  break;
    case 0xFF9867: Serial.println("EQ");  break;
    case 0xFFB04F: Serial.println("ST/REPT");  break;
    case 0xFF6897: Serial.println("0");  break;
    case 0xFF30CF: Serial.println("1");  break;
    case 0xFF18E7: Serial.println("2");  break;
    case 0xFF7A85: Serial.println("3");  break;
    case 0xFF10EF: Serial.println("4");  break;
    case 0xFF38C7: Serial.println("5");  break;
    case 0xFF5AA5: Serial.println("6");  break;
    case 0xFF42BD: Serial.println("7");  break;
    case 0xFF4AB5: Serial.println("8");  break;
    case 0xFF52AD: Serial.println("9");  break;
    case 0xFFFFFFFF: Serial.println("REPEAT");break;  

    default: 
      Serial.println(" other button : ");
      Serial.println(results.value);
  }
  delay(500); // Wait before you repeat
} 
