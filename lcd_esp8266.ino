#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


#define FIREBASE_HOST "YOUR_FIREBASE_LINK"
#define FIREBASE_AUTH "YOUR_FIREBASE_TOKEN"
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

String values;

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);


}

void loop() {


  String temperature = Firebase.getString("temperature");
  String humidity = Firebase.getString("humidity");

  temperature = temperature.substring(0, 5);
  humidity = humidity.substring(0, 5);
  values = (temperature + humidity);
  delay(10);


  // always flush before printing
  Serial.flush();
  delay(1000);

  Serial.print(values);
  delay(1000);


}
