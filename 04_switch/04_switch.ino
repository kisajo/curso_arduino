int dia = 6;
char * nombreDia = "";
int nota = 7;
String cali = "";

void setup() {
  Serial.begin(115200);
  delay(5000);
  switch (dia) {
    case 1:
      nombreDia = "Lunes";
      break;
    case 2:
      nombreDia = "Martes";
      break;
    case 3:
      nombreDia = "Miércoles";
      break;
    case 4:
      nombreDia = "Jueves";
      break;
    case 5:
      nombreDia = "Viernes";
      break;
    case 6:
      nombreDia = "Sábado";
      break;
    case 7:
      nombreDia = "Domingo";
      break;
    }
  
    switch (nota) {
    case 1:
    case 2:
    case 3:
    case 4:
      cali = "Suspenso";
      break;
    case 5 ... 6:
      cali = "Aprobado";
      break;
    case 7:
    case 8:
      cali = "Notable";
      break;
    default:
      cali = "Sobresaliente";
      break;
    }
    
  
  Serial.println(nombreDia);
  //delay(5000);
  Serial.println("La calificación es: " + cali);
}

void loop() {


}
