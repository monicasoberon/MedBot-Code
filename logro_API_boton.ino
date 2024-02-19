#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>

/*  ----------- WiFi ----------- */

#define WIFI_SSID "Tec-IoT"
#define WIFI_PASSWORD "spotless.magnetic.bridge"

HTTPClient httpClient;
WiFiClient wClient;

String URL1 = "http://10.14.255.7:10206/dispensar/insert"; 
String URL2 = "http://10.14.255.7:10206/rellenar/insert";

const int button = D4;
const int echo = D6;
const int trig = D5;

int duracion;
int distancia;

int limite = 0;

void setup() {
  Serial.begin(9600);

  pinMode(button, INPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

  WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

      Serial.print("Conectando a red WiFi \"");
      Serial.print(WIFI_SSID);
      Serial.print("\"");

      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }

      Serial.print("\nConectado! IP: ");
      Serial.println(WiFi.localIP());
      delay(500);

}

void loop(){
  getDistancia();

  if (distancia <= 15){
    Serial.println("No Rellenar");
    log_distancia_POST(22206, "No Rellenar");

  }else{
    Serial.println("Rellenar");
        log_distancia_POST(22206, "Rellenar");

  }

  if(limite == 5){
    Serial.println("-----* Boton *-----");
    delay(2500);

    if(digitalRead(button) == HIGH){
      Serial.println("Dispensado");
      log_boton_POST(22206, "Dispensar");

    }else{
      Serial.println("No Dispensado");
      log_boton_POST(22206, "No Dispensar");

    }

    limite = 0;
  }

  limite++;

  delay(1000);
}

void log_boton_POST(int robot_id, String dato){
  String string_a;
  string_a = robot_id;

  // "{\" dispensar\": "si}
  
  if(WiFi.status() == WL_CONNECTED){

    HTTPClient http;   
    http.begin(wClient, URL1);  

    http.addHeader("Content-Type", "application/json"); 

    String httpRequestData = "{\"id_robot\":" + string_a + ", \"dispensar\": \"" + dato + "\"";
    httpRequestData = httpRequestData + "}";

    Serial.print(httpRequestData);
    Serial.println();

    int httpResponseCode = http.POST(httpRequestData);
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
  }
  return;
}

void getDistancia(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  duracion = pulseIn(echo, HIGH);

  distancia = duracion * 0.034 / 2;

  return;
}

void log_distancia_POST(int robot_id, String dato){
  String string_a;
  string_a = robot_id;

  // "{\" dispensar\": "si}
  
  if(WiFi.status() == WL_CONNECTED){

    HTTPClient http;   
    http.begin(wClient, URL2);  

    http.addHeader("Content-Type", "application/json"); 

    String httpRequestData = "{\"id_robot\":" + string_a + ", \"rellenar\": \"" + dato + "\"";
    httpRequestData = httpRequestData + "}";

    Serial.print(httpRequestData);
    Serial.println();

    int httpResponseCode = http.POST(httpRequestData);
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
  }
  return;
}
