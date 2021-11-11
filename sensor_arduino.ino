#include <SoftwareSerial.h>
#include <dht.h>
#define dht_apin A0

dht DHT;
String values;

void setup() {
  Serial.begin(9600);
  delay(5000);//Delay to let system boot

}

void loop() {
  //Start of Program

  DHT.read11(dht_apin);
  values = (String(DHT.temperature) + ',' + String(DHT.humidity));
  delay(10);
  
  Serial.flush();
  delay(1000);

  // sent sensors data to serial (sent sensors data to ESP8266)
  Serial.print(values);
  delay(2000);

}
