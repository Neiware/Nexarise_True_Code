#include "Grua.h"
#include "CommunicationUI.h"


const int BUFFER_SIZE = 100;
char buf[BUFFER_SIZE];

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
  // if (Serial.available() > 0) {
  //   // read the incoming bytes:
  //   Serial.print("porqeu");
  //   int rlen = Serial.readBytesUntil('\n', buf, BUFFER_SIZE);

  //   // prints the received data
  //   Serial.print("I received: ");
  //   for(int i = 0; i < rlen; i++)
  //     Serial.print(buf[i]);
  // }
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
