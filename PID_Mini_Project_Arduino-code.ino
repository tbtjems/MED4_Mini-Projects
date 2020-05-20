// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int potPin1 = A0;
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.clear();

  pinMode(potPin1, INPUT);

}

void loop()
{
  lcd.setCursor(0, 0); // Sets the cursor to col 0 and row 0
  lcd.print("Lie'o'Meter:"); // Prints Sensor Val: to LCD
  lcd.print(analogRead(potPin1)); // Prints value on Potpin1 to LCD
    delay(200);


    switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(8);
      lcd.setCursor(0, 1);

      switch (reply) { // the program will enter the case    assigned to the switch
        case 0:
        lcd.print("True to the bone");
          break;
        case 1:
          lcd.print("White lie, so ok");
          break;
        case 2:
          lcd.print("LIE!");
          break;
        case 3:
          lcd.print("Could be?");
          break;
        case 4:
          lcd.print("Unsure");
          break;
        case 5:
          lcd.print("Ask again");
          break;
        case 6:
          lcd.print("Probably not");
          break;
        case 7:
          lcd.print("OK lets say that");
          break;
      }
    }
  }
prevSwitchState = switchState;
}
