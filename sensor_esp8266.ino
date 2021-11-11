#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "YOUR_FIREBASE_LINK"
#define FIREBASE_AUTH "YOUR_FIREBASE_TOKEN"
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

String sensor_data, values;

void setup() {


  delay(1000);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.begin(9600);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {

  bool Sr = false;

  while (Serial.available()) {

    //get sensor data from serial put in sensor_data
    sensor_data = Serial.readString();
    Sr = true;

  }

  delay(1000);

  if (Sr == true) {

    values = sensor_data;

    //get comma indexes from values variable
    int fristCommaIndex = values.indexOf(',');
    int secondCommaIndex = values.indexOf(',', fristCommaIndex + 1);

    //get sensors data from values variable by  spliting by commas and put in to variables
    String temperature = values.substring(0, fristCommaIndex);
    String humidity = values.substring(fristCommaIndex + 1, secondCommaIndex);

    //store ultrasonic sensor data as string in firebase
    Firebase.setString("temperature", temperature);
    delay(10);
    //store IR sensor 1 data as string in firebase
    Firebase.setString("humidity", humidity);
    delay(10);
    
    //store previous sensors data as string in firebase

    delay(1000);

    if (Firebase.failed()) {
      return;
    }

  }
}
