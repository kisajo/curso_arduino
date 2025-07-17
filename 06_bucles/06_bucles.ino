
void setup() {
  Serial.begin(115200);
  delay(500);

// Bucles controlados por un contador

/*
  for(int i = 0; i < 10; i++){
    Serial.print("Número: ");
    Serial.println(i);
  }
*/
/*
  for(int i = 0; i < 100; i += 3){
    Serial.println("Número: " + String(i));
  }
*/
/*
  for(int i = 100; i > 0; i--){
    Serial.print("Número: ");
    Serial.println(i);
  }
*/

//Bucles en 2 dimensiones
 /* String salida = "";
  for (int fila = 0; fila < 10; fila ++){
    for(int col = 0; col < 10; col ++){
      salida += String(fila) + ":" + String(col) + "\t";
    }
    salida += "\n";
  }
    Serial.print(salida);
*/
  int limite = 10;
  int contador = 0;
  for(;;){
    Serial.print("Infinito: ");
    Serial.println(contador);
    if (contador == limite){
      break;
    }    
    contador++;
  }
  contador = 0;
// Bucle While
  while(contador < limite){
    Serial.print("While: ");
    Serial.println(contador);
  
  contador++;

  }
}

void loop() {

}


