#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 6, 7, 8, 9);

int switchState = 0; // Used for Tilt Switch
int prevSwitchState = 0; // Used for Tilt Switch
int reply; // Will store the random used to generate Magic 8-Ball responses
const int switchPin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT); // Tilt Switch is an INPUT
  lcd.begin(16,2); // Our LCD has 16 columns and 2 rows.
  lcd.print("Ask the"); //Displays "Ask the" on the First row of the LCD
  lcd.setCursor(0,1); // Moves the cursor to the 1st column, 2nd row.
  lcd.print("Magic 8-Ball"); // Displays "Magic 8-Ball" on the second row of the LCD
  delay(1000);
}

void loop() {
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState){
    if(switchState == LOW){ //If Tilt Switch is "off", pick new reply
      reply = random(8);
      lcd.clear(); //Clears the LCD
      lcd.setCursor(0,0); // 1st column, 1st row
      lcd.print("The ball says: ");
      lcd.setCursor(0,1); // 1st column, 2nd row

      switch(reply){
        case 0:
          lcd.print("Yes");
          break;
        case 1:
          lcd.print("No");
          break;
        case 2:
          lcd.print("Depends");
          break;
        case 3:
          lcd.print("Possibly");
          break;
        case 4:
          lcd.print("Possibly Not");
          break;
        case 5:
          lcd.print("Ask Again");
          break;
        case 6:
          lcd.print("Unlikely");
          break;
        case 7:
          lcd.print("Absolutely");
          break;
        default:
          lcd.print(reply);
      }
    }
  }
  prevSwitchState = switchState;

}
