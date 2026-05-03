#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  delay(1000);              // Wait for LCD to power up fully
  Wire.begin(21, 22);
  delay(100);               // Let I2C bus stabilise

  lcd.init();               // First init
  delay(50);
  lcd.init();               // Second init — fixes ESP32 I2C cold-start issue
  lcd.backlight();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ADEOYE");
  lcd.setCursor(0, 1);
  lcd.print("WORKING NOW");
}

void loop() {
}
