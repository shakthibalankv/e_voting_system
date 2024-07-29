#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display

#define sw1 2
#define sw2 3
#define sw3 4
#define confirmButton 5

int selectedParty = 0;
int vote1 = 0;
int vote2 = 0;
int vote3 = 0;

void setup() {
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(confirmButton, INPUT_PULLUP);

  lcd.begin();                      // Initialize the LCD
  lcd.backlight();                 // Turn on backlight
  lcd.setCursor(0, 0);
  lcd.print("Select Party:");
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(sw1) == LOW) {
    selectedParty = 1;
    lcd.setCursor(0, 1);
    lcd.print("Party 1 Selected  ");
    while (digitalRead(sw1) == LOW); // Wait for button release
    delay(100);
  }
  
  if (digitalRead(sw2) == LOW) {
    selectedParty = 2;
    lcd.setCursor(0, 1);
    lcd.print("Party 2 Selected  ");
    while (digitalRead(sw2) == LOW); // Wait for button release
    delay(100);
  }
  
  if (digitalRead(sw3) == LOW) {
    selectedParty = 3;
    lcd.setCursor(0, 1);
    lcd.print("Party 3 Selected  ");
    while (digitalRead(sw3) == LOW); // Wait for button release
    delay(100);
  }

  if (digitalRead(confirmButton) == LOW && selectedParty != 0) {
    if (selectedParty == 1) {
      vote1++;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Party 1 Voted  ");
    }
    else if (selectedParty == 2) {
      vote2++;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Party 2 Voted  ");
    }
    else if (selectedParty == 3) {
      vote3++;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Party 3 Voted  ");
    }
    Serial.print("Party 1 votes : ");
      Serial.println(vote1);
      Serial.print("Party 2 votes : ");
      Serial.println(vote2);
      Serial.print("Party 3 votes : ");
      Serial.print(vote3);
      Serial.println("\n\n");
    selectedParty = 0; // Reset selected party
    delay(3000); // wait for three seconds
    lcd.clear();
    lcd.setCursor(0, 0); 
    lcd.print("Select Party:  ");
  }
}