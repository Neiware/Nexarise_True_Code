#include "Grua.h"
#include "CommunicationUI.h"


const int BUFFER_SIZE = 100;
char buf[BUFFER_SIZE];

const int LED_PIN = 13;
const int ledPin = 13; // Pin number connected to the LED
CommunicationUI comunicador;
Grua gruaNexArise;
//iniziatilar Objetos
void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  // Serial.print(gruaNexArise.StepsPerMilimeterX);
  pinMode(ledPin, OUTPUT);
  // Grua grua = Grua();
}



void loop() {

  // Serial.print(gruaNexArise.StepsPerMilimeterX);
    // Serial.println("Pruebaslocas");
    // Serial.println(gruaNexArise.getStepsPerMilimeterX());
    

  if (Serial.available() > 0)
  {
    /* code */
    comunicador.ReadAvailable();
    // Serial.print(comunicador.eje);
    // gruaNexArise.MoveInMilimeteSrs(comunicador.eje, comunicador.milimeters);

    // String dataString = comunicador.ReceivedData;
    // int delimiterPos1 = dataString.indexOf(':');
    // int delimiterPos2 = dataString.indexOf(':', delimiterPos1 + 1);
    // int delimiterPos3 = dataString.indexOf(':', delimiterPos2 + 1);

    // if (delimiterPos1 != -1 && delimiterPos2 != -1 && delimiterPos3 != -1) {
    //   String value1Str = dataString.substring(0, delimiterPos1);
    //   String value2Str = dataString.substring(delimiterPos1 + 1, delimiterPos2);
    //   String value3Str = dataString.substring(delimiterPos2 + 1, delimiterPos3);
    //   String value4Str = dataString.substring(delimiterPos3 + 1);
    //   char mode = value1Str.charAt(0);
    //    mode = (char)toupper(mode);
    //   char eje = value2Str.charAt(0);
    //   eje = (char)toupper(eje);
    //   int milimeters = value3Str.toInt();
    //   String status = value4Str;

    // Serial.print(comunicador.mode + comunicador.eje + comunicador.milimeters);
    int response = gruaNexArise.MoveInMilimeters(comunicador.eje, comunicador.milimeters);
    Serial.print(response);
      // Serial.print(mode + eje + milimeters + status);
  }





  // comunicador.ReadAvailable();
  // if (Serial.available() > 0)
  //     {
  //       digitalWrite(LED_PIN, HIGH);
  //       int rlen = Serial.readBytesUntil('\n', buf, BUFFER_SIZE);
  //       for(int i = 0; i < rlen; i++){
  //         Serial.print(buf[i]);
  //       }
  //       digitalWrite(LED_PIN, LOW);

  //       // ProcessData(ReceivedData);
  //       //  respone = true;
  //     }
  // if (Serial.available() > 0) {
  //   // read the incoming bytes:
  //   Serial.print("porqeu");
  //   int rlen = Serial.readBytesUntil('\n', buf, BUFFER_SIZE);

  //   // prints the received data
  //   Serial.print("I received: ");
  //   for(int i = 0; i < rlen; i++)
  //     Serial.print(buf[i]);
  // }
  // if(comunicador.ReadAvailable())
  // {
  //   gruaNexArise.MoveInMilimeters(comunicador.eje, comunicador.milimeters);
  // }
  //   //Modo de Operacion.
  //   // int response;
  //   // switch (comunicador.mode)
  //   // {
  //   // case 'A':
  //   //   /* code */
      // response = gruaNexArise.MoveInMilimeters(comunicador.eje, comunicador.milimeters);
  //   //   break;
  //   // case 'M':
  //   //   /* code */
  //   //   response = gruaNexArise.MoveInMilimeters(comunicador.eje, comunicador.milimeters);
  //   //   break;
  //   // case 'S':
  //   //   /* code */
  //   //   gruaNexArise.SetSpeed(comunicador.stepsPerMilimeter[0],comunicador.stepsPerMilimeter[1],comunicador.stepsPerMilimeter[2]);
  //   //   break;

  //   // default:
  //   //   break;
  //   // }


  // }
}
