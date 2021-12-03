#define MQ2pin (1)
#include "dht.h"
#define dht_apin A5 // Analog Pin sensor is connected to A0
 
dht DHT;
float sensorValue;  //variable to store sensor value

void setup(){
  Serial.begin(9600); // sets the serial port to 9600
  Serial.println("Gas sensor warming up!");
  delay(20000); // allow the MQ-6 to warm up
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
}

void loop(){
  sensorValue = analogRead(MQ2pin); // read analog input pin 0
  DHT.read11(dht_apin);
  Serial.print("MQ2 Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" ");
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature); 
  Serial.println("C  ");
    
  if(sensorValue > 300){
    Serial.print(" | Smoke detected!");
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
  }
  
  Serial.println("");
  delay(2000); // wait 2s for next reading
}...
