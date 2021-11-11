#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "arduino-final-f8154-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "fe830SpD5qJVo4xISkc43JGgKw9Bm4Ic5dQtEKCr"
#define WIFI_SSID "HWDSB-GUEST"
#define WIFI_PASSWORD "Education"

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
