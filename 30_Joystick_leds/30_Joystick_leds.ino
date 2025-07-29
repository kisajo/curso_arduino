#define PIN_X 13
#define PIN_Y 12
#define PIN_SW 14

#define LED_N 19
#define LED_S 21
#define LED_O 15
#define LED_E 5

int cero_x = 1848;
int cero_y = 1840;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_X, INPUT);
  pinMode(PIN_Y, INPUT);
  pinMode(PIN_SW, INPUT_PULLUP); 

  pinMode(LED_N, OUTPUT);
  pinMode(LED_S, OUTPUT);
  pinMode(LED_O, OUTPUT);
  pinMode(LED_E, OUTPUT);

}

void loop() {
  int valor_x = analogRead(PIN_X);
  int valor_y = analogRead(PIN_Y);
  int valor_sw = digitalRead(PIN_SW);

  

  if(valor_x - cero_x > 0){
    Serial.println("Derecha: " + String(valor_x - cero_x));
    digitalWrite(LED_S, LOW);
    digitalWrite(LED_N, LOW);
    digitalWrite(LED_O, LOW);
    digitalWrite(LED_E, HIGH);

  }
  if(valor_x - cero_x  < 0){
    Serial.println("zquierda: " + String(valor_x - cero_x));
    digitalWrite(LED_S, LOW);
    digitalWrite(LED_N, LOW);
    digitalWrite(LED_O, HIGH);
    digitalWrite(LED_E, LOW);

  }
    if(valor_y - cero_y > 0){
    Serial.println("Arriba: " + String(valor_y - cero_y));
    digitalWrite(LED_S, LOW);
    digitalWrite(LED_N, HIGH);
    digitalWrite(LED_O, LOW);
    digitalWrite(LED_E, LOW);
  }
  if(valor_y - cero_y  < 0){
    Serial.println("Abajo: " + String(valor_y - cero_y));
    digitalWrite(LED_S, HIGH);
    digitalWrite(LED_N, LOW);
    digitalWrite(LED_O, LOW);
    digitalWrite(LED_E, LOW);
  }
  Serial.print("X, Y, Z: ");
  Serial.print(String(valor_x) + ", ");
  Serial.print(String(valor_y) + ", ");
  Serial.println(String(valor_sw));

  delay(500);

}
