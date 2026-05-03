#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Using the confirmed address 0x3F
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  // Initialize I2C on the standard pins
  Wire.begin(21, 22);
  
  // Basic initialization sequence
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  // Print to the screen
  lcd.setCursor(0, 0);
  lcd.print("ADEOYE TEST");
  lcd.setCursor(0, 1);
  lcd.print("LCD IS ALIVE!");
}

void loop() {
  // Blink the backlight every 2 seconds to show the code is running
  lcd.backlight();
  delay(2000);
  lcd.noBacklight();
  delay(500);
}
