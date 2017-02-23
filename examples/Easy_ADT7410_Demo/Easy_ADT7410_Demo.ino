#include <Wire.h>
#include <EasyADT7410.h>

//ADT7410 13/16-bit digital temperature sensor
//RED (VDD): 2.7 ... 5.5V
//BROWN (GND): 0V
//Arduino uno, wires:
//PURPLE 1 (SCL): SCL (near AREF, should be equal to ANALOG5)
//PURPLE 2 (SDA): SDA (near AREF, should be equal to ANALOG4)
//Arduino due, wires:
//PURPLE 1 (SCL): SCL (pin 21)
//PURPLE 2 (SDA): SDA = (pin 20)
//Arduino IDE 1.5 compatible


ADT7410 sensor_ADT7410;
// make a string for assembling the data to log:
String dataString = "";

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  sensor_ADT7410.begin();

  Serial.println("Setting 16-bit mode...");
  sensor_ADT7410.set16bitMode();
}

void loop() {
  serialPrint(); //print on serial port
  delay(5000);
}


void serialPrint()
{
  float temp = sensor_ADT7410.readTemperature();
  
  // make a string for assembling the data to log:
  dataString = "Time: ";
  dataString += String(millis());
  dataString += String("; Temperature: ");
  dataString += String(temp);
  dataString += String(" degrees Celcius");
  Serial.println(dataString);
}
