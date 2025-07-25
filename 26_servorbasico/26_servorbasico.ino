#include <ESP32Servo.h>

#define PINSERVO 15

Servo miServo;

void setup() {
  miServo.setPeriodHertz(50);
  miServo.attach(PINSERVO, 500, 2500); 
}

void loop() {
  /*
  for(int i = 0; i < 180; i++){
    miServo.write(i);
    delay(20);
  }
  delay(200);

  for(int i = 180; i > 0; i--){
    miServo.write(i);
    delay(20);
  }
  delay(200);

  */
    for(int i = 0; i <= 180; i+=45){
    miServo.write(i);
    delay(300);
  }
  delay(1000);

  for(int i = 180; i >= 0; i-=45){
    miServo.write(i);
    delay(300);
  }
  delay(1000);

}
