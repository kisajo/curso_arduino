#define pinRed 12
#define pinGreen 13
#define pinBlue 14

void setup() {
  Serial.begin(112500);
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
}

void loop() {
// Rojo Encendido
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, HIGH);
  digitalWrite(pinBlue, LOW);
  serialprintln("Red");
  delay(500);

  // Verde Encendido
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, HIGH);
  digitalWrite(pinBlue, LOW);
  serialprintln("Green");
  delay(500);

  // Azul Encendido
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, LOW);
  digitalWrite(pinBlue, HIGH);
  serialprintln("Blue");
  delay(500);

}
