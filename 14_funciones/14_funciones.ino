
void setup() {
  Serial.begin(115200);
  delay(500);
//  int numero = sumar(3, 2);

//  Serial.println(numero);

  int acumulador = 0;
  int valores[] = {1, 3, 4 ,5 ,8, 12,34};

  for(int i = 0; i < 7; i++){
    acumulador = sumar(acumulador, valores[i]);
  }

  Serial.print("Total: ");
  Serial.println(acumulador);

  char cadena[] = "Hola Mundo";
  int largo = longitudCadena(cadena);

  Serial.print("Longitud: ");
  Serial.println(largo);
}

void loop() {


}

/* FUNCIONES

TIPO DE DATO QUE DEVUEVLE LA FUNCIÓN
NOMBRE DE LA FUNCIÓN
DENTRO DE LOS PARÉNTESIS ESTÁN LOS PARÁMETROS QUE NECESITARÍA UNA FUNCIÓN SI LA NECESITA Y DENTRO DE LAS LLAVES, EL CÓDIGO NECESARIO PARA QUE LA FUNCIÓN REALICE LA TAREA ESPECIFICADA
TIPO NOMBRE_FUNCION() {

}
int nombre_funcion(parametr1, parametr2,....){

}

int variable = nombre_funcion() para recoger el valor de la función anterior teniendo en cuenta que tiene que ser del mismo tipo

*/

// Función que suma dos números

  int sumar(int primero, int segundo){
  /*
    Validadr las entradas PRECONDICIÓN
    Hacer el trabajo INVARIANTE
    Validar los resultados POSTCONDICIÓN
  */

    int temp = primero + segundo;
    return temp;  

}

  // Función que calcules la longitud de una cadena
  // camelCase

  int longitudCadena(char cadena[]){
    int i = 0;
    while(cadena[i] != '\0'){
      i++;
    }
    return i;

  }

  /*char * invertirCadena(char * cadena){
    int n_car = longitudCadena(cadena);
    char * aux_cadena = "";
   
    for(i = n_car - 1; i > 0; i-- ){
      aux_cadena = aux_cadena + cadena(i);
    }
    return aux_cadena;
  }
  */

  char* invertirCadena(char *cadena){
    int longitud = lingtudCadena(dadena);
    char* inversa = new char[longitud - 1; i> = 0; i--]{
      inversa[j] = cadena[i};
      j++;
      ]
    }
  }