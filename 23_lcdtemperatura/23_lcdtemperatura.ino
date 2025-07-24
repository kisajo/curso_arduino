#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>

#define SDA 13
#define SCL 14
#define ADDR 0x3F // lA OTRA ES 0x3F
#define DHT_PIN 15
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(ADDR, 16, 2);  // E este manejador es ldd. Manejador en inglés es HNADLE

DHT dht(DHT_PIN, DHTTYPE);
float temp = 0.0;
float hum = 0.0;

void setup() {
  Serial.begin(115200);

  Wire.begin(SDA, SCL);
  dht.begin();
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() {
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  lcd.clear();
  delay(5000);
  
  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(temp) + char(223) + "C");
  lcd.setCursor(0, 1);
  lcd.print("Hum: " + String(hum) + "%");
  /*
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(temp) + char(223) + "C");
  lcd.setCursor(0, 1);
  lcd.print("Hum: " + String(hum) + "%");
  */
  
  delay(5000);
}
