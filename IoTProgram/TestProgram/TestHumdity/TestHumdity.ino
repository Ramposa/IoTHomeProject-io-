#include "DHT.h"                  //Required libraries for DHT and OLED

#define Atomizer 3       //Atomizer EN pin
#define DHTpin 2         //DHT signal pin
#define DHTTYPE DHT11    //you can use DHT 22...

DHT dht(DHTpin, DHTTYPE);

void setup() {
  
    Serial.begin(9600);
    dht.begin();
    pinMode(Atomizer, OUTPUT);
      
}

void loop() {
 
  float h = dht.readHumidity();         //Reading the humidity/Temperature values, you can calibrate them if you want
  //float t = dht.readTemperature();      //You can add true between those brackets to make it Fahrenheit instead of Celsius

  if(h>=70){                           //if the humidity % is equal or above the setpoint (70) the atomizer stops
    digitalWrite(Atomizer,LOW);
    Serial.print("Off \n");
    
    }
  
    if(h<70){                      //Otherwise it will be on and it will show "On" on the display alongside the current temperature and humidity
    digitalWrite(Atomizer,HIGH);
    Serial.print("On \n");
    }
                
  delay(100);

}
