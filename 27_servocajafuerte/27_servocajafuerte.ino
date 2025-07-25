#include <ESP32Servo.h>

#define PINSERVO 15

Servo miServo;
String entrada = "";
String secreto = "1234";

bool primeraVez = true;

void setup() {
  Serial.begin(115200);
  miServo.setPeriodHertz(50);
  miServo.attach(PINSERVO, 500, 2500); 

  miServo.write(0);
}

void loop() {
  if(primeraVez){
    Serial.println("Introduzca la clave.");
    primeraVez = !primeraVez;
  }
    if(Serial.available() > 0){
    entrada = Serial.readStringUntil('\n');
    entrada.trim();
    if(entrada == secreto){
      Serial.print("Clave correcta");
      miServo.write(90);
      delay(5000);
      Serial.println("Puerta cerrada");
      miServo.write(0);
    }
    else{
      Serial.println("Clave incorrecta. Pruebe otra vez");
    }
  }
}
