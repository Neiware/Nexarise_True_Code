#include "Grua.h"
#include "CommunicationUI.h"


const int LED_PIN = 13;
const int ledPin = 13; // Pin number connected to the LED
//iniziatilar Objetos
CommunicationUI comunicador;
Grua gruaNexArise(25,25,25);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  // Grua grua = Grua();
}

void loop() {
  if(comunicador.ReadAvailable())
  {
    //Modo de Operacion.
    int response;
    switch (comunicador.mode)
    {
    case 'A':
      /* code */
      response = gruaNexArise.MoveInMilimeters(comunicador.eje, comunicador.milimeters);
      break;
    case 'M':
      /* code */
      response = gruaNexArise.MoveInMilimeters(comunicador.eje, comunicador.milimeters);
      break;
    case 'S':
      /* code */
      gruaNexArise.SetSpeed(comunicador.stepsPerMilimeter[0],comunicador.stepsPerMilimeter[1],comunicador.stepsPerMilimeter[2]);
      break;

    default:
      break;
    }


  }
}
