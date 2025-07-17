#define LED 2
#define ZUMBADOR 15

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(ZUMBADOR, OUTPUT);

}

int duracion;
void loop() {
  duracion = 100;
  for(int i = 0; i < 100; i++){
    digitalWrite(LED, HIGH);
    //digitalWrite(ZUMBADOR, LOW);
    delay(duracion);
    digitalWrite(LED, LOW);
    //digitalWrite(ZUMBADOR, HIGH);
    delay(duracion);
    Serial.println(duracion);
    duracion += 100;
  }
}
