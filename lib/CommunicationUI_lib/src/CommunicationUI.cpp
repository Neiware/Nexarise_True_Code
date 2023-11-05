#include "CommunicationUI.h"

  CommunicationUI::CommunicationUI(){};
  void CommunicationUI::FillData()
  {
    if (mode == "Automatico")
    {
      eje = value2Str;
      milimeters = value3Str.toFloat();
    }
    else if (mode == "Manual")
    {
      milimeters = value3Str.toFloat();
    }
    else if(mode == "Vel")
    {
      speedMilimetersPerSecond[0] = value2Str.toFloat();
      speedMilimetersPerSecond[1] = value3Str.toFloat();
      speedMilimetersPerSecond[2] = value4Str.toFloat();
    }else if(mode =="Ace")
      {
      accelerationPerSecondPerSecond[0] = value2Str.toFloat();
      accelerationPerSecondPerSecond[1] = value3Str.toFloat();
      accelerationPerSecondPerSecond[2] = value4Str.toFloat();

    }else
    {

    }
    
  }


  void CommunicationUI::ReadData( )
  {
    //Data Incoming Template
    // Mode : EjeStepper : numMilimeters : Extra;
    // Automatico:X:50:prueba
    Serial.readBytesUntil('\n', ReceivedData, sizeof(ReceivedData));
    ProcessData(ReceivedData);
    FillData();
    
    
    

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
      mode = dataString.substring(0, delimiterPos1);
      value2Str = dataString.substring(delimiterPos1 + 1, delimiterPos2);
      value3Str = dataString.substring(delimiterPos2 + 1, delimiterPos3);
      value4Str = dataString.substring(delimiterPos3 + 1);
      // mode = value1Str.charAt(0);
      // mode = (char)toupper(mode);
      // eje = value2Str.charAt(0);
      // eje = (char)toupper(eje);
      // milimeters = value3Str.toInt();
      // status = value4Str;
    }
  }

  void CommunicationUI::TestReceivedData(){
    bool respone = false;
    while (respone == false)
    {

      if (Serial.available() > 0)
      {
        int test = Serial.readBytesUntil('\n', ReceivedData, sizeof(ReceivedData));
        for(int i = 0; i < test; i++){
          Serial.print(ReceivedData[i]);
        }
      }
      /* code */
    }
  }

  //GETTERS AND SETTERS
  String CommunicationUI::GetEje(){
    return eje;
  }
  
  float CommunicationUI::GetMilimeters()
  {
    return milimeters.toFloat();
  }

  String  CommunicationUI::GetMode()
  {
    return mode;
  }



