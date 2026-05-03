#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  Serial.begin(115200);
  delay(1000);

  // ESP32 I2C pins
  Wire.begin(21, 22);

  // CRITICAL FIX: Slow down to 100kHz for PCF8574 backpack compatibility
  Wire.setClock(100000);
  delay(200);

  // Scan to confirm LCD is reachable
  Wire.beginTransmission(0x3F);
  byte error = Wire.endTransmission();
  if (error == 0) {
    Serial.println("LCD found at 0x3F");
  } else {
    Serial.println("LCD NOT found — check wiring or address");
  }

  lcd.init();
  delay(50);
  lcd.init();
  lcd.backlight();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ADEOYE");
  lcd.setCursor(0, 1);
  lcd.print("WORKING NOW");
}

void loop() {
}
