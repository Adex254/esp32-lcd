#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Using 0x3F as confirmed by your previous success
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  // 1. Give the hardware a moment to stabilize power
  delay(1000); 

  // 2. Start I2C on Pins 21 and 22
  Wire.begin(21, 22);
  delay(100);

  // 3. Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // 4. Print messages
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ADEOYE ONLINE");
  lcd.setCursor(0, 1);
  lcd.print("LCD TEST OK");
}

void loop() {
  // Heartbeat: Blink the backlight so we know the ESP32 hasn't crashed
  lcd.backlight();
  delay(1000);
  lcd.noBacklight();
  delay(1000);
}
