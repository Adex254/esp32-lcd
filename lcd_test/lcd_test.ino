#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Using the confirmed address 0x3F
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  // Direct pin assignment
  Wire.begin(21, 22);
  
  // Standard initialization
  lcd.init();
  lcd.backlight();
  
  // Clear and Print
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ADEOYE");
  lcd.setCursor(0, 1);
  lcd.print("WORKING NOW");
}

void loop() {
  // Stay quiet to avoid I2C bus noise
}
