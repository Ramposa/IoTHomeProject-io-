#include <WiFiNINA.h>
#include <ThingSpeak.h>

#include "dht.h"
dht DHT; // Initalize dht to DHT
const int dht_apin = A5; // Analog Pin sensor is connected to A0
char ssid[] = "TestNetwork"; // Network name
const char password [] = "7HzOTHxq"; // PWD
const unsigned long channel_id = 1563136; // CH ID
const char write_api_key[] = "NLIND3V0XNHBGZRB";// API key
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
  
  DHT.read11(dht_apin);
  Serial.println("Posting " + String(DHT.humidity, 2) + "% to ThingSpeak");
  ThingSpeak.setField(1, String(DHT.humidity, 2));
  Serial.println("Posting " + String(DHT.temperature, 2) + " to ThingSpeak");
  ThingSpeak.setField(2, String(DHT.temperature, 2));
  ThingSpeak.writeFields(channel_id, write_api_key);
  Serial.println();
  //delay(300000);
  delay(30000);
}
