#include <DHT.h>

#define DHT_PIN 13
#define DHTTYPE DHT11
#define BLUE_PIN 15

DHT dht(DHT_PIN, DHTTYPE);

float temp = 0.0;
float hum = 0.0;

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(BLUE_PIN, OUTPUT);

}

void loop() {
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  digitalWrite(BLUE_PIN, HIGH);

  Serial.print("Temperatura: ");
  Serial.println(temp);
  Serial.println("Humedad: " + String(hum));

  delay(100);
  digitalWrite(BLUE_PIN, LOW);
  delay(5000);
}
