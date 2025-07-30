#define SENSOR 33

void setup() {
  Serial.begin(115200);

}

void loop() {
  int lectura = touchRead(SENSOR);
  Serial.println("Sensor: " + String(lectura));

  delay(200);

}
