#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SDA 13
#define SCL 14
#define ADDR 0x3F // lA OTRA ES 0x3F

LiquidCrystal_I2C lcd(ADDR, 16, 2);  // E este manejador es ldd. Manejador en inglés es HNADLE


void setup() {
  Wire.begin(SDA, SCL);
  //Wire.beginTransmission(ADDR);

  lcd.init();

  lcd.noBacklight();
  delay(1000);
  lcd.backlight();
  delay(1000);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Hola Mundo");

  lcd.setCursor(0, 1);
  lcd.print("Bienvenidos...");
}

void loop() {
  /*
  lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);
  */
  lcd.clear();
  delay(5000);
  

  lcd.setCursor(0,0);
  lcd.print("Temp: 12.04");
  lcd.print(char(223));
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Hum: 45%");
  
  delay(5000);
  /*
  lcd.setCursor(5, 0);
  lcd.print("Adiós");
  */
  
}
