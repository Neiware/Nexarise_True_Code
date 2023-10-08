#include <Arduino.h>

int serialData;
const int ledPin = 13; // Pin number connected to the LED
char receivedData[50]; // Buffer to store received data
float value1, value2, value3;

void setup() {
  Serial.begin(9600);  //initialize serial comms

  pinMode(ledPin, OUTPUT);
  String data; 
}

void loop() {


  if (Serial.available() > 0) {
    Serial.readBytesUntil('\n', receivedData, sizeof(receivedData));

    // Use a stringstream to parse the received data
    String dataString = receivedData;
    int delimiterPos1 = dataString.indexOf(':');
    int delimiterPos2 = dataString.lastIndexOf(':');

    if (delimiterPos1 != -1 && delimiterPos2 != -1) {
      String value1Str = dataString.substring(0, delimiterPos1);
      String value2Str = dataString.substring(delimiterPos1 + 1, delimiterPos2);
      String value3Str = dataString.substring(delimiterPos2 + 1);

      value1 = value1Str.toFloat();
      value2 = value2Str.toFloat();
      value3 = value3Str.toFloat();

      digitalWrite(ledPin, HIGH);
      delay(1500);
      digitalWrite(ledPin, LOW);
    }
  }
  delay(100);

}