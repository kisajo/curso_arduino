#define PIN_LED 2
#define PIN_BLUE 12

int contador;

void setup() {  
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void loop() {
  digitalWrite(PIN_LED, HIGH);
  digitalWrite(PIN_BLUE, LOW);
  Serial.println("Encendido");
  delay(500);
  contador++;
  Serial.println(contador);
  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_BLUE, HIGH);
  Serial.println("Apagado");
  delay(500);
}
