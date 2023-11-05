

#ifndef Communication_h
#define Communication_h

#include<Arduino.h>
// #include "Arduino.h"

class CommunicationUI
{
private:
  /* data */
  const int BUFFER_SIZE = 100;
  char buf[100];
  String Ready = "Ready";
  String value2Str;
  String value3Str;
  String value4Str;

  char ReceivedData[50]; // Buffer to store received data
  String mode;
  String eje;
  String milimeters;
  String status;
  int stepsPerMilimeter[3];
  float speedMilimetersPerSecond[3];
  float accelerationPerSecondPerSecond[3];
  void FillData();

public:

  CommunicationUI();
  void ReadData();
  void Send();
  void ProcessData(char receivedData[50]);
  void TestReceivedData();
  String GetEje();
  float GetMilimeters();
  String GetMode();

};

#endif