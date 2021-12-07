#include <dht.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
dht DHT;

#define buzzer D8
#define DHT11_PIN D1

const char* ssid = "TP-Link_Zayed";
const char* password = "*******";

//Your Domain name with URL path or IP address with path
const char* serverName = "http://d805-2a03-b0c0-1-d0-00-f5d-1001.ngrok.io/";

unsigned long lastTime = 0;
unsigned long timerDelay = 5000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(buzzer, OUTPUT);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int chk = DHT.read11(DHT11_PIN);
  char message[100];
  snprintf(message, 150, "Temperature = %.2f C, Humidity = %.2f %%", DHT.temperature, DHT.humidity);
  Serial.println(message);
  delay(1000);

  int fireAlarm = 0;
  if (DHT.temperature > 30) {
    fireAlarm = 1;
    Buzzer();
  } else {
    fireAlarm = 0;
    digitalWrite(buzzer, LOW);
  }
  
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;
      
      // Your Domain name with URL path or IP address with path
      http.begin(client, serverName);
      
      // Specify content-type header
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      char httpRequestData[100];
      snprintf(httpRequestData, 150, "temperature=%.2f&humidity=%.2f&fireAlarm=%i", DHT.temperature, DHT.humidity, fireAlarm);
        
      // Send HTTP POST request
      int httpResponseCode = http.POST(httpRequestData);
     
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
        
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
  
}

void Buzzer()
    {
    digitalWrite(buzzer,HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    delay(500);
}
