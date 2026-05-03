#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Updated address to 0x3F as per your instruction
LiquidCrystal_I2C lcd(0x3F, 16, 2); 

void setup() {
  Serial.begin(115200);
  delay(1000);

  // ESP32 I2C pins (SDA: 21, SCL: 22)
  Wire.begin(21, 22);

  // Standard 100kHz for I2C backpack stability
  Wire.setClock(100000);
  delay(200);

  // Verification scan for 0x3F
  Wire.beginTransmission(0x3F);
  byte error = Wire.endTransmission();
  
  if (error == 0) {
    Serial.println("LCD found at 0x3F");
  } else {
    Serial.println("LCD NOT found at 0x3F - Check wiring");
  }

  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Test text
  lcd.setCursor(0, 0);
  lcd.print("ADEOYE");
  lcd.setCursor(0, 1);
  lcd.print("WORKING NOW");
}

void loop() {
}
