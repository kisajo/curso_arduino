#define LED_BLUE 15
#define LED_GREEN 13

int verde;

void setup() {
  pinMode(LED_BLUE, OUTPUT);  
  pinMode(LED_GREEN, OUTPUT);

}

void loop() {
  /*
  digitalWrite(RED_BLUE, HIGH);
  delay(1000);
  digitalWrite(RED_BLUE, LOW);
  delay(1000);
  */
  verde = 255;
  for(int  i = 0; i < 256; i++ ){
    analogWrite(LED_BLUE, i);
    analogWrite(LED_GREEN, verde - i);
    delay(5);
  }
  
  /*digitalWrite(LED_BLUE, LOW);
  delay(1000);
  digitalWrite(LED_BLUE, HIGH);
  */
  delay(1000);
  
  for(int  i = 255; i > -1; i--){
    analogWrite(LED_BLUE, i);
    analogWrite(LED_GREEN, verde + i);
    delay(5);
  }
  
   delay(1000);
}
