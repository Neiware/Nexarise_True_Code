

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

  void FillData();

public:
  char ReceivedData[50]; // Buffer to store received data
  String mode;
  String eje;
  String milimeters;
  String status;
  int stepsPerMilimeter[3];

  CommunicationUI();
  void ReadAvailable();
  void Send();
  void ProcessData(char receivedData[50]);
  void TestReceivedData();

};

#endif