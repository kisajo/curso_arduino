/*
  PROGRAMACIÓN ESTRUCTURADA
  -------------------------
  Secuencia
  Alternativa
  Repetición
*/

int nota = 8;

void setup() {
  // OPERANDO OPERADOR OPERANDO
  // OR -> ||
  // AMD -> &&
  // NOT -> !
  //

  Serial.begin(115200);
  delay(5000);  
if(nota < 5){
  Serial.println("Suspenso");
}
else
{
  if(nota < 7){
    Serial.println("Aprobado");
  }
  else{
    if(nota < 9){
      Serial.println("Notable");
    }
    else{
      Serial.println("Sobresaliente");
    }
  }
}
}
  


void loop() {
/*
if Serial.avalaible ()> 0{
  edad = Serial.rea();
}
if(edad >= 18){
      // Si se cumple
      Serial.println("La persona es mayor de edad");
  }
  else
  {
    // Si no se cumple
    Serial.println("La persona es menor de edad");
  }
*/
}