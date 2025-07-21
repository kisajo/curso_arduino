#include <DHT.h>
#include <WiFi.h>
#include <HTTPClient.h>


#define DHTPIN 13
#define DHTTYPE DHT11  // Aquí hay un valor que es el que se le asigna a DHTTYPE

DHT sensor(DHTPIN, DHT11);
//sensor() es un constructor

float temp = 0.0;
float hum = 0.0;

// Conexión a Internet

WiFiClient clienteWifi;
HTTPClient http;

char * servidor = "http://192.168.0.34:5000/datos";

//Datos de la Conexión WIFI

char * ssid = "Aula 1";
char * pwd = "Horus.2025";

void setup() {
  Serial.begin(115200);
  sensor.begin();

// WIFI
WiFi.begin(ssid, pwd);
while(WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.print(".");  
}
Serial.print("Conectado a la IP: ");
Serial.println(WiFi.localIP());
}

void loop() {
  temp = sensor.readTemperature();
  hum = sensor.readHumidity();

  postData(temp, hum, "Jose Local");

  //Serial.println("Temp: " + String(temp));
  //Serial.println("Hum: " + String(hum));

  delay(5000);

}

void postData(float t, float h, String per){
  String parametros = "temp=" + String(t) + "&hum=" + String(h) + "&persona=" + per;
  int httpCode;
  String payload;

  if (WiFi.status() == WL_CONNECTED){
    http.begin(clienteWifi, servidor);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    httpCode = http.POST(parametros);
    payload = http.getString();
    Serial.print("HTTP Code: ");
    Serial.println(httpCode);
    Serial.print("Mensaje:");
    Serial.println(payload);
  }
}