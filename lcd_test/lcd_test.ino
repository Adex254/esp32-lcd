#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Use 0x27 as established in your previous hardware tests
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Initialize I2C on ESP32 default pins (SDA: 21, SCL: 22)
  Wire.begin(21, 22);

  // Set clock to 100kHz for better compatibility with the PCF8574 backpack
  Wire.setClock(100000);
  delay(200);

  // Verification scan for the address 0x27
  Wire.beginTransmission(0x27);
  byte error = Wire.endTransmission();
  
  if (error == 0) {
    Serial.println("LCD found at 0x27");
  } else {
    Serial.println("LCD NOT found - Check wiring or address");
  }

  // Proper initialization sequence
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Display your specified test message
  lcd.setCursor(0, 0);
  lcd.print("ADEOYE"); 
  lcd.setCursor(0, 1);
  lcd.print("WORKING NOW");
}

void loop() {
  // Empty loop for testing
}
