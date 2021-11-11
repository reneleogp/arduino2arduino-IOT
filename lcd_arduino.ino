#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal_I2C lcd(0x3F, 20, 4);
String values, sensor_data;

void setup() {
  Serial.begin(9600);
  delay(2000);
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.init(); // initialize the lcd
  lcd.backlight();
  delay(2000);
  lcd.setCursor(0, 0); lcd.print("Temperature: " );
  delay(10);
  lcd.setCursor(18, 0); lcd.print("C");
  delay(10);

  lcd.setCursor(0, 1); lcd.print("Humidity: ");
  delay(10);
  lcd.setCursor(15, 1); lcd.print("%");
  delay(2000);

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

    //get sensors data from values variable by spliting by commas and put in to variables
    String temperature = values.substring(0, 5);
    String humidity = values.substring(6, 11);


    initialize();
    lcd.setCursor(13, 0);
    delay(10);
    lcd.print(temperature);//set cursor to print temperature
    delay(10);
    lcd.setCursor(10, 1);
    delay(10);
    lcd.print(humidity);

  }
  delay(2000);

}
void initialize() {
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("Temperature: " );
  delay(10);
  lcd.setCursor(18, 0); lcd.print("C");
  delay(10);

  lcd.setCursor(0, 1); lcd.print("Humidity: ");
  delay(10);
  lcd.setCursor(15, 1); lcd.print("%");
}
