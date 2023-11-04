#include "CommunicationUI.h"

  CommunicationUI::CommunicationUI(){};
  void CommunicationUI::FillData()
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


  bool CommunicationUI::ReadAvailable()
  {
    bool respone = false;
    while (respone == false)
    {

      if (Serial.available() > 0)
      {
        Serial.println("after readbyte");
        Serial.readBytesUntil('\n', ReceivedData, sizeof(ReceivedData));
        ProcessData(ReceivedData);
         respone = true;
      }
      /* code */
    }
    return respone;
    
    //Data Incoming Template
    // Mode:Stepper:Milimeters:Extra;
    // Mode:x:y:z;

    //Tipos de Modos. A = Automatico. M = Manual. S = SetSpeed.

  }
  void CommunicationUI::Send(){}

  void CommunicationUI::ProcessData(char receivedData[50])
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



