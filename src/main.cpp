#include <Arduino.h>

int ledPin = 13; //integrated LED
int serialData;

void setup() {
  Serial.begin(9600);  //initialize serial comms

  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    Serial.print("Estoy aqui");
    serialData = Serial.read();
    if(serialData == '1'){
      digitalWrite(ledPin, HIGH);
    }
    else {
      digitalWrite(ledPin, LOW);
    }
  }
  delay(100);

}