#include "pins_arduino.h"
#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to A0
#define Atomizer 3

dht DHT;
 
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor

}

void loop() {
  DHT.read22(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
if(DHT.humidity>=51){ //if the humidity % is equal or above the setpoint 51% the atomizer turn ON (HIGH)
    digitalWrite(Atomizer,HIGH);
    Serial.print("ON \n");
    
    }
  
    else if(DHT.humidity<50){ //Otherwise it will be on and it will show "OFF" on the display alongside the current humidity
    digitalWrite(Atomizer,LOW);
    Serial.print("OFF \n");
    }

    else if(DHT.humidity>30){ 
    digitalWrite(Atomizer,LOW);
    Serial.print("OFF \n");
    }

    else if(DHT.humidity<29){ 
    digitalWrite(Atomizer,HIGH);
    Serial.print("ON \n");
    }
 
    delay(1000);//Wait 60 seconds before accessing sensor again.
  
}
