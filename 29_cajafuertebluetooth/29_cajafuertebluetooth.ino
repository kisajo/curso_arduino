#include <ESP32Servo.h>
#include <BluetoothSerial.h>

#define PINSERVO 15
#define LED_GREEN 14
#define LED_RED 13

Servo miServo;
BluetoothSerial serialBT;

String entrada = "";
String secreto = "1234";

bool primeraVez = true;

void setup() {
  Serial.begin(115200);
  serialBT.begin("Caja_Fuerte_Jose");
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);


  miServo.setPeriodHertz(50);
  miServo.attach(PINSERVO, 500, 2500); 

  miServo.write(0);
}

void loop() {
  if(primeraVez){
    Serial.println("Introduzca la clave.");
    primeraVez = !primeraVez;
  }
    if(serialBT.available() > 0){
    entrada = serialBT.readStringUntil('\n');
    entrada.trim();
    if(entrada == secreto){
      serialBT.println("Clave correcta");
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_RED, LOW);
      miServo.write(90);
      delay(5000);
      serialBT.println("Puerta cerrada");
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_GREEN, LOW);
      miServo.write(0);
      delay(5000);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_RED, LOW);
      miServo.write(0);
    }
    else{
      serialBT.println("Clave incorrecta. Pruebe otra vez");
    }
  }
}
