#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

char * mqtt_topic_sub = "curso_arduino/#";
char * mqtt_topic_pub = "curso_arduino/jose";
char * mqtt_client_id = "ESP_Jose";



char * ssid = "Aula 1";
char * pwd = "Horus.2025";

char* mqtt_server = "192.168.0.25";
int mqtt_port = 1883;

unsigned long now;
static unsigned long lastMsg = 0;

void setup() {


  Serial.begin(115200);
  

// WIFI
  WiFi.begin(ssid, pwd);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");  
}
  Serial.print("Conectado a la IP: ");
  Serial.println(WiFi.localIP());

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

}

void loop() {
  
  now = millis();

  if(!client.connected()){
    reconnect();
  }
  client.loop();
  if(now - lastMsg > 10000){
    lastMsg = now;
    String mensaje = "Hola, soy Jose";
    client.publish(mqtt_topic_pub, mensaje.c_str());
    Serial.println("Mensaje enviado: " + mensaje);
  }
}

void callback(char* topic, byte* payload, unsigned int lenght){
  Serial.print("Mensaje recibido en [");
  Serial.print(topic);
  Serial.print("]:");
  for(int i = 0; i < lenght; i++){
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect(){
  while(!client.connected()){
    Serial.println("Reconectando...");
    if(client.connect(mqtt_client_id)){
      Serial.println("Conectado a MQTT");
      client.subscribe(mqtt_topic_sub);
    }
    else{
      Serial.println("Fallo en la conexión");
      Serial.println("Error: " + client.state());
      delay(5000);
    }
  }
}