#include "CommunicationUI.h"

  CommunicationUI::CommunicationUI(){};
  void CommunicationUI::FillData()
  {
    String Data[3] = {value2Str,value3Str,value4Str};
    if (mode == "A")
    {
      eje = Data[0];
    }
    else if (mode == "M")
    {
      milimeters = Data[2];
    }
    else if(mode == "S")
    {
      /* code */
    }else{

    }
    
    // switch (mode.ch)
    // {
    // case 'A':
    //   /* code */
    //   eje = Data[0].charAt(0);
  
    //   milimeters = Data[1].toFloat();
    //   break;
    // case 'M':
    //   /* code */
    //   eje = Data[0].charAt(0);
    //   milimeters = Data[1].toFloat();
    //   break;
    // case 'S':
    //   /* code */
    //   for (int i = 0; i < 3; i++)
    //   {
    //     stepsPerMilimeter[i] = Data[i].toInt(); 
    //   }
    //   break;

    // default:
    //   break;
    // }
  }


  void CommunicationUI::ReadAvailable( )
  {
      /* code */
    Serial.readBytesUntil('\n', ReceivedData, sizeof(ReceivedData));
    ProcessData(ReceivedData);
    // FillData();
      // for(int i = 0; i < test; i++){
      //   Serial.print(ReceivedData[i]);
      // }

    
    
    
    //Data Incoming Template
    // Mode:Stepper:Milimeters:Extra;
    // Mode:x:y:z:prueba

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
      eje = dataString.substring(delimiterPos1 + 1, delimiterPos2);
      milimeters = dataString.substring(delimiterPos2 + 1, delimiterPos3);
      status = dataString.substring(delimiterPos3 + 1);
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




