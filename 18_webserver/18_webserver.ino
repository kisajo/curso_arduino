#include <WiFi.h>
#include <WebServer.h>

#define GREEN_LED 13

char* ssid = "Aula 1";
char* pwd = "Horus.2025";

WebServer server(80);

String home = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Primera Página</title></head><body><h1>Hola Mundo</h1><h2>La primera página</h2><a href=\"/segunda\">Ir a la segunda página</a></body></html>";
String segunda = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Segunda Página</title></head><body><h1>Esta es la Segunda Página</h1></body></html>";
String encender = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Página Encendida</title></head><body><h1>Se tiene que encender</h1></body></html>";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pwd);

  Serial.print("Conectando a WiFi");
  
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    
  }

  if(WiFi.status() == WL_CONNECTED){
    Serial.print("\nConectado a la IP: ");
    Serial.println(WiFi.localIP());

    // sOLICITUDES WEB
    server.on("/", handle_OnConnect);
    server.on("/segunda", handle_Segunda);
    server.on("/led", handle_Led);

    server.begin();
    Serial.println("Servidor web iniciado");  
  }
  pinMode(GREEN_LED, OUTPUT);
  /*
  digitalWrite(GREEN_LED, HIGH);
  delay(5000);
  digitalWrite(GREEN_LED, LOW);
  */
}

void loop() {
  server.handleClient();
}

void handle_OnConnect(){
  server.send(200, "text/html", home);
}
void handle_Segunda(){
  server.send(200, "text/html", segunda);
}
void handle_Led(){
  digitalWrite(GREEN_LED, HIGH);server.send(200, "text/html", home);
  delay(5000);
  digitalWrite(GREEN_LED, LOW);
  delay(5000);
  server.send(200, "text/html", "");
}