#include "Arduino_LSM6DS3.h"

void setup() {
  Serial.begin(9600);
   //start the IMU:
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU");
    // stop here if you can't access the IMU:
    while (true);
  }
}

void loop() {
  float x, y, z;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x,y,z);
 
   
  
   int mappedValue = map(x, 0, 1023, 0, 255);
   
    Serial.println(mappedValue);
    
  // print different formats:
  Serial.write(mappedValue);  // Print the raw binary value
  Serial.print('\t');             // print a tab
  // print ASCII-encoded values:
  Serial.print(mappedValue, BIN); // print ASCII-encoded binary value
  Serial.print('\t');             // print a tab
  Serial.print(mappedValue);      // print decimal value
  Serial.print('\t');             // print a tab
  Serial.print(mappedValue, HEX); // print hexadecimal value
  Serial.print('\t');             // print a tab
  Serial.print(mappedValue, OCT); // print octal value
  Serial.println();               // print linefeed and carriage return
}

}
