#include "Grua.h"
#include "CommunicationUI.h"

const int LED_PIN = 13;
const int ledPin = 13; // Pin number connected to the LED
//iniziatilar Objetos
void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

CommunicationUI comunicador;
Grua gruaNexArise = Grua();


void loop() {
  if (Serial.available() > 0)
  {
    /* code */
    comunicador.ReadData();

    int response;
    if (comunicador.GetMode() == "Automatico")
    {
      response = gruaNexArise.MoveInMilimeters(comunicador.GetEje(), comunicador.GetMilimeters());
      delay(300);
      Serial.print("Done");
    }
    else if (comunicador.GetMode() == "Manual")
    {
      /* code */
    }
    else if(comunicador.GetMode() == "Vel")
    {
      /* code */
    }else if(comunicador.GetMode() == "Ace")
    {

    }else
    {

    }


  }


}
