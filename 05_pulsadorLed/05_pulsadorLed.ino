#define PULSADOR 13
#define LED_RED 4
#define ZUMBADOR 15

int valorBoton = HIGH;
int estado = LOW;

void setup() {
  pinMode(PULSADOR, INPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(ZUMBADOR, OUTPUT);
}

void loop() {
  valorBoton = digitalRead(PULSADOR);
  
  if (valorBoton == HIGH){
    digitalWrite(LED_RED, LOW);
    digitalWrite(ZUMBADOR, LOW);
  }
  else{
    digitalWrite(LED_RED, HIGH);
    digitalWrite(ZUMBADOR, HIGH);
  }
  
  
  /*if (valorBoton == LOW){
    estado = !estado;
    digitalWrite(LED_RED, estado);
  }
  */
  delay(200);
  
}
  

