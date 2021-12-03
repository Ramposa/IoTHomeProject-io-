// Air Quality monitoring 
#include <YunClient.h>
#include <ThingerYun.h>

// The Thinger.io cloud
#define USERNAME "YOUR_USER_NAME"
#define DEVICE_ID "YOUR_DEVICE_ID"
#define DEVICE_CREDENTIAL "YOUR_CREDENTIAL"

ThingerYun thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);


void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

  // initialize bridge
  Bridge.begin();


  // resource output example (i.e. reading a sensor value, a variable, etc)
  thing["LPG"] >> outputValue(analogRead(A0)); // optional 
  thing["CO2"] >> outputValue(analogRead(A1));
  thing["CO"] >> outputValue(analogRead(A2));
  thing["AIRQ"] >> outputValue(analogRead(A3));

  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
}
