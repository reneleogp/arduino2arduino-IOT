#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


#define FIREBASE_HOST "arduino-final-f8154-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "fe830SpD5qJVo4xISkc43JGgKw9Bm4Ic5dQtEKCr"
#define WIFI_SSID "HWDSB-GUEST"
#define WIFI_PASSWORD "Education"

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

  Serial.flush();
  delay(1000);

  Serial.print(values);
  delay(1000);


}
