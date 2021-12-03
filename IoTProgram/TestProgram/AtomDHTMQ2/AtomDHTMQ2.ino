#include <WiFiNINA.h>
#include <ThingSpeak.h>

#define Atomizer 0
#define MQ2pin (2)
#include "dht.h"
dht DHT; // Initalize dht to DHT
float atomizerValue;
float sensorValue;  //variable to store sensor value
const int dht_apin = A3; // Analog Pin sensor is connected to A0
char ssid[] = "IoTTestNetwork"; // Network name
const char password [] = "7HzOTHxq"; // PWD
const unsigned long channel_id = 1573881; // CH ID
const char write_api_key[] = "CTXB3D7BB16SI71Y";// API key LOOK INNTO API KEYS TAB
WiFiClient client; // Connect to to a specified internet IP address

void setup() {
  // Setting up connection
  Serial.begin(9600);
  delay(100);
  Serial.print("Connecting to " + String(ssid));
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED ) {
    delay(500);
    Serial.println("Attempting to Connect to " + String(ssid) + " .");
    delay(100);
  }
  Serial.println();
  Serial.println("Connected!");
  ThingSpeak.begin(client);
  
  }

void loop() {
  
  sensorValue = analogRead(MQ2pin); // read analog input pin 5
  DHT.read22(dht_apin);
  Serial.println("Posting " + String(DHT.humidity, 2) + "% to ThingSpeak");
  ThingSpeak.setField(1, String(DHT.humidity, 2));
  
  Serial.println("Posting " + String(DHT.temperature, 2) + " to ThingSpeak");
  ThingSpeak.setField(2, String(DHT.temperature, 2));
  
  Serial.println("Posting " + String(sensorValue, 2) + " to ThingSpeak");
  ThingSpeak.setField(3, String(sensorValue, 2));
  
  ThingSpeak.writeFields(channel_id, write_api_key);
  Serial.println();

  if(DHT.humidity>=50){ //if the humidity % is equal or above the setpoint 51% the atomizer turn ON (HIGH)
    digitalWrite(Atomizer,HIGH);
    Serial.print("ON \n");
    Serial.println("Posting Atomizer ON" + String(atomizerValue, 1) + " to ThingSpeak");
    ThingSpeak.setField(4, String(atomizerValue= 1));
    }

    else if(DHT.humidity<=30){ 
    digitalWrite(Atomizer,HIGH);
    Serial.print("ON \n");
    Serial.println("Posting Atomizer ON" + String(atomizerValue, 1) + " to ThingSpeak");
    ThingSpeak.setField(4, String(atomizerValue = 1));
    }

    else if(DHT.humidity){
      digitalWrite(Atomizer,LOW);
      Serial.print("OFF \n");
      Serial.println("Posting Atomizer OFF " + String(atomizerValue, 0) + " to ThingSpeak");
      ThingSpeak.setField(4, String(atomizerValue = 0));
    }
    
  //delay(600000); // 10min delay
  //delay(300000); // 5min delay
  delay(10000); // 10s delay Testing purposes
}
