#define RED_LED 13
#define POT1 4
#define POT2 14
#define ZUMBADOR 12

int valorPot1 = 0;
int valorPot2 = 0;
int valorRedLed = 0;

void setup() {
  Serial.begin(115200);
  pinMode(RED_LED, OUTPUT);
  pinMode(POT1, INPUT);
  pinMode(POT2, INPUT);  
  pinMode(ZUMBADOR, OUTPUT);

}

void loop() {
  valorPot1 = analogRead(POT1);
  valorPot2 = analogRead(POT2);
  valorRedLed = map(valorPot1, 0, 4096, 0, 255);
  
  analogWrite(RED_LED, valorRedLed);
  digitalWrite(ZUMBADOR, HIGH);
  delay(valorPot2);
  digitalWrite(ZUMBADOR, LOW);
  delay(valorPot2);

  Serial.println("Pot1: " + String(valorRedLed) + ("\t") + ("\t") + String(valorPot1));
  Serial.println("Pot2: " + String(valorPot2) + ("\t") + ("\t") + String(valorPot2));

  //delay(500);
 
}
