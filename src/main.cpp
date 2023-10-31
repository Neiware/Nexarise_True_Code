#include <Arduino.h>
#include <FlexyStepper.h>


class CommunicationUI
{
private:
  /* data */
  char ReceivedData[50]; // Buffer to store received data
  String Ready = "Ready";
  String value2Str;
  String value3Str;
  String value4Str;

  void FillData()
  {
    String Data[3] = {value2Str,value3Str,value4Str};
    switch (mode)
    {
    case 'A':
      /* code */
      eje = Data[0].charAt(0);
      milimeters = Data[1].toFloat();
      break;
    case 'M':
      /* code */
      eje = Data[0].charAt(0);
      milimeters = Data[1].toFloat();
      break;
    case 'S':
      /* code */
      for (int i = 0; i < 3; i++)
      {
        stepsPerMilimeter[i] = Data[i].toInt(); 
      }
      break;

    default:
      break;
    }
  }

public:
  char mode;
  char eje;
  float milimeters;
  String status;
  int stepsPerMilimeter[3];
  CommunicationUI(/* args */);
  ~CommunicationUI();

  bool ReadAvailable()
  {
    if (Serial.available() <= 0)
    {
      return false;
    }
    Serial.readBytesUntil('\n', ReceivedData, sizeof(ReceivedData));
    ProcessData(ReceivedData);
    return true;
    //Data Incoming Template
    // Mode:Stepper:Milimeters:Extra;
    // Mode:x:y:z;

    //Tipos de Modos. A = Automatico. M = Manual. S = SetSpeed.

  }
  void Send(){}

  void ProcessData(char receivedData[50] )
  {
    String dataString = receivedData;
    int delimiterPos1 = dataString.indexOf(':');
    int delimiterPos2 = dataString.indexOf(':', delimiterPos1 + 1);
    int delimiterPos3 = dataString.indexOf(':', delimiterPos2 + 1);

    if (delimiterPos1 != -1 && delimiterPos2 != -1 && delimiterPos3 != -1) {
      String value1Str = dataString.substring(0, delimiterPos1);
      value2Str = dataString.substring(delimiterPos1 + 1, delimiterPos2);
      value3Str = dataString.substring(delimiterPos2 + 1, delimiterPos3);
      value4Str = dataString.substring(delimiterPos3 + 1);
      mode = value1Str.charAt(0);
      mode = (char)toupper(mode);
    }
  }


};

CommunicationUI::CommunicationUI(/* args */)
{
}

CommunicationUI::~CommunicationUI()
{
}
class Grua
{
private:
  /* data */
FlexyStepper ejeX = FlexyStepper();
FlexyStepper ejeY = FlexyStepper();
FlexyStepper ejeZ = FlexyStepper();
const int MOTOR_X_STEP_PIN = 2;
const int MOTOR_Y_STEP_PIN = 3;
const int MOTOR_Z_STEP_PIN = 4;
const int MOTOR_X_DIR_PIN = 5;
const int MOTOR_Y_DIR_PIN = 6;
const int MOTOR_Z_DIR_PIN = 7;
const int STEPPERS_ENABLE_PIN = 8;

public:
  Grua(float StepsPerMilimeterX, float StepsPerMilimeterY, float StepsPerMilimeterZ)
  {
    pinMode(STEPPERS_ENABLE_PIN, OUTPUT);       // be sure to do this

    ejeX.connectToPins(MOTOR_X_STEP_PIN, MOTOR_X_DIR_PIN);
    ejeY.connectToPins(MOTOR_Y_STEP_PIN, MOTOR_Y_DIR_PIN);
    ejeZ.connectToPins(MOTOR_Z_STEP_PIN, MOTOR_Z_DIR_PIN);

    digitalWrite(STEPPERS_ENABLE_PIN, LOW);     // be sure to do this

    ejeX.setStepsPerMillimeter(StepsPerMilimeterX);
    ejeY.setStepsPerMillimeter(StepsPerMilimeterY);
    ejeZ.setStepsPerMillimeter(StepsPerMilimeterZ);

  }
  

  int MoveInMilimeters(char eje, float milimeters)
  {
    eje = (char)toupper(eje);
    int response;
     switch (eje)
     {
     case 'X':
      ejeX.moveToPositionInMillimeters(milimeters);
      response = 1;
      break;
     case 'Y':
      ejeY.moveToPositionInMillimeters(milimeters);
      response = 1;
      break;
     case 'z':
      ejeZ.moveToPositionInMillimeters(milimeters);
      response = 1;
      break;
     default:
     //If something Wrong return 0
      response = 0;
      break;
     delay(300);
     return response;
     }
  }

  void SetSpeed(int x = 40, int y = 40, int z = 20)
  {
    FlexyStepper stepper[3] = {ejeX,ejeY,ejeZ};
    int arrayVel[3] = {x,y,z};
    for (int i = 0; i < 3; i++)
    {
      stepper[i].setSpeedInMillimetersPerSecond(arrayVel[i]);
    }
  }

};


const int LED_PIN = 13;
const int ledPin = 13; // Pin number connected to the LED
//iniziatilar Objetos 
CommunicationUI comunicador;
Grua GruaNexArise;

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
      response = GruaNexArise.MoveInMilimeters(comunicador.eje, comunicador.milimeters);
      break;
    case 'M':
      /* code */
      response = GruaNexArise.MoveInMilimeters(comunicador.eje, comunicador.milimeters);
      break;
    case 'S':
      /* code */
      GruaNexArise.SetSpeed(comunicador.stepsPerMilimeter[0],comunicador.stepsPerMilimeter[1],comunicador.stepsPerMilimeter[2]);
      break;

    default:
      break;
    }


  }
}
