# Send sensor data from one Arduino UNO to another using esp8266 and Firebase

In this cool [IoT](https://en.wikipedia.org/wiki/Internet_of_things) project, you read data from a humidity and temperature sensor connected to one Arduino UNO. Send this data to [Firebase](https://firebase.google.com/) using an esp8266 module and then download the data in another Arduino UNO using an esp8266, to finally display it onto an LCD. 

## Components and Supplies:
- Two Arduino UNO
- Two [ESP8266 WiFi Modules](https://en.wikipedia.org/wiki/ESP8266)
- One [DHT11 Temperature/Humidity Sensor](https://create.arduino.cc/projecthub/techno_z/dht11-temperature-humidity-sensor-98b03b)
- One [I2C LCD](https://create.arduino.cc/projecthub/arduino_uno_guy/i2c-liquid-crystal-displays-5b806c)
- Two breadboards
- Male/Female and Male/Male Jump wires

## Resources and Steps:

1.  Understand how Arduino UNO and ESP8266 work. Note that they work as two different boards and have different codes. You use the Arduino UNO to communicate with the ESP8266. You can later send data between the two boards via the Serial terminal.
2.  Connect one Arduino to the LCD and try a template code, you can use [I2C communication](https://create.arduino.cc/projecthub/arduino_uno_guy/i2c-liquid-crystal-displays-5b806c) as we did or [normal communication](https://www.arduino.cc/en/Tutorial/LibraryExamples/HelloWorld).
3.  [Connect the other Arduino to the DHT11 Sensor and try a template code](https://create.arduino.cc/projecthub/techno_z/dht11-temperature-humidity-sensor-98b03b).
4.  [Connect ESP8266 to Firebase to Send & Receive Data](https://create.arduino.cc/projecthub/pulasthi-Narada/connecting-esp8266-to-firebase-to-send-receive-data-4adf66).
5.  Follow this tutorial carefully [Send sensor data to Firebase](https://create.arduino.cc/projecthub/pulasthi-Narada/send-multiple-sensors-data-to-firebase-using-esp8266-f2f38b).
6.  Now that you know how to upload and receive data, you can upload the actual code to the esp8266s connected to the Arduinos and to the Arduinos.
7.  Feel free to modify it if needed. Keep in mind that you should leave delay.
   
# Common Errors and advice:

- **ALWAYS DISCONNECT THE ARDUINO CABLE BEFORE DISCONNECTING ANY WIRE.**

- Code not uploading to ESP8266:
  - Select the esp8266 generic board.
  - Follow this step-by-step [video](https://www.youtube.com/watch?v=ZJnpgYlelEA&t=0s). They connect a NodeMCU to the ESP8266 but you can use the same connections to the Arduino UNO.
  - If the code is still not uploading and giving you an error do [this](https://www.youtube.com/watch?v=tXmM03HMgeg).
  - If still not working unplug, reconnect, try to upload and then try the previous solution again.

- Code not uploading to Arduino UNO:
  -  Read carefully how to upload code to Arduino UNO in this [documentation](https://create.arduino.cc/projecthub/pulasthi-Narada/send-multiple-sensors-data-to-firebase-using-esp8266-f2f38b), step 7.
  -  Take out GPIO-0 (IO0) from GND and Arduino Uno RESET Pin from Uno's Ground/GND Pin.
  -  Remove ESP8266 RX pin from UNO's RX pin and ESP8266 TX pin from UNO's TX pin. 
  -  Re-check your pins, select Arduino UNO board.

- Not working after uploading both codes:
  - Connect the ESP8266 RX pin to Uno's TX pin and ESP8266 TX pin to Uno's RX pin. Yes, you have to connect them in the opposite way. Don't ask me why. Just do it.
  - Disconnect the ESP8266 GPIO-0 (IO0) from GND.
  - Re-check your pins
  - Make sure you are only printing the values you want to share between the Arduino and the ESP8266 in the Serial Monitor. If you print things like "connected" or any other thing the code will not work.

- As for advice, I would suggest you create a google sheet or excel with the colours you are using for the esp8266 so you don't get confused.
- If you get it to work and the LCD prints something weird it should fix it after a few seconds. This may occur due to Serial communication delays. 
  
