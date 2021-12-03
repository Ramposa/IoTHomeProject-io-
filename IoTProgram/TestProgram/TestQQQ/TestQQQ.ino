#include "thingProperties.h"
#include "dht.h"
#define DHTpin A1
#define DHTTYPE DHT22
DHT dht(DHTpin,DHTTYPE);

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  dht_sensor_getdata();
  
}

/*
  Since Msg is READ_WRITE variable, onMsgChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMsgChange()  {
  // Add your code here to act upon Msg change
}
/*
  Since Humdity is READ_WRITE variable, onHumdityChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onHumdityChange()  {
  // Add your code here to act upon Humdity change
}
 void dht_sensor_getdata()
  {
    float hm= dht.readHumidity();
    Serial.print("Humidity ");
    Serial.println(hm);
    float temp=dht.readTemperature();
      Serial.print("Temperature ");
    Serial.println(temp);
    humidity=hm;
    temperature=temp;
    msg="Temperature = " + String (temperature)+"  Humidity = " + String(humidity);
  }
