#define ROJO 13
#define VERDE 12
#define AZUL 14

#define POT_R 19
#define POT_G 18
#define POT_B 15

int pot_r, pot_g, pot_b;
int led_r, led_g, led_b;

void setup() {
  Serial.begin(115200);

  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL,OUTPUT);

  pinMode(POT_R, INPUT);
  pinMode(POT_G, INPUT);
  pinMode(POT_B, INPUT);
}

void loop() {
  pot_r = analogRead(POT_R);
  led_r = map(pot_r, 0, 4096, 0, 255);
  analogWrite(ROJO, 255 - led_r);

  pot_g = analogRead(POT_G);
  led_g = map(pot_r, 0, 4096, 0, 255);
  analogWrite(VERDE, 255 - led_g);

  pot_b = analogRead(POT_B);
  led_b = map(pot_b, 0, 4096, 0, 255);
  analogWrite(AZUL, 255 - led_r);

  Serial.print("Red: " + String(led_r) + "Green: " + String(led_g) + "Blue: " + String(led_b));
}
