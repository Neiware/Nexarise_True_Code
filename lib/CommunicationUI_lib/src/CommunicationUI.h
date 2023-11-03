

#ifndef Communication_h
#define Communication_h

#include<Arduino.h>
// #include "Arduino.h"

class CommunicationUI
{
private:
  /* data */
  char ReceivedData[50]; // Buffer to store received data
  String Ready = "Ready";
  String value2Str;
  String value3Str;
  String value4Str;

  void FillData();

public:
  char mode;
  char eje;
  float milimeters;
  String status;
  int stepsPerMilimeter[3];

  CommunicationUI();
  bool ReadAvailable();
  void Send();
  void ProcessData(char receivedData[50]);


};

#endif