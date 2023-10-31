#include <Arduino.h>
#include <FlexyStepper.h>


const int LED_PIN = 13;
const int MOTOR_X_STEP_PIN = 2;
const int MOTOR_Y_STEP_PIN = 3;
const int MOTOR_Z_STEP_PIN = 4;
const int MOTOR_X_DIR_PIN = 5;
const int MOTOR_Y_DIR_PIN = 6;
const int MOTOR_Z_DIR_PIN = 7;
const int STEPPERS_ENABLE_PIN = 8;
const float STEPS_PER_MILIMETER = 23;


//Crear objetos de Flexy Stepper
FlexyStepper stepperX;
FlexyStepper stepperY;
FlexyStepper stepperZ;

void MoveMotorNumerOfMilimeters(FlexyStepper stepper, float NumberMilimeters)
{
  stepper.setSpeedInMillimetersPerSecond(50);
  stepper.setAccelerationInMillimetersPerSecondPerSecond(100);
  stepper.moveToPositionInMillimeters(NumberMilimeters);
  delay(2000);
  stepper.moveToPositionInMillimeters(0);
  delay(2000);
}

int serialData;
const int ledPin = 13; // Pin number connected to the LED
char receivedData[50]; // Buffer to store received data
float value1, value2, value3;

void setup() {
   //
  // setup the LED pin and enable print statements
  //
  pinMode(LED_PIN, OUTPUT);   
  pinMode(STEPPERS_ENABLE_PIN, OUTPUT);       // be sure to do this
  Serial.begin(9600);

  //
  // connect and configure the stepper motor to there IO pins
  //
  stepperX.connectToPins(MOTOR_X_STEP_PIN, MOTOR_X_DIR_PIN);
  stepperY.connectToPins(MOTOR_Y_STEP_PIN, MOTOR_Y_DIR_PIN);
  stepperZ.connectToPins(MOTOR_Z_STEP_PIN, MOTOR_Z_DIR_PIN);

  //
  // enable the stepper motors
  //
  digitalWrite(STEPPERS_ENABLE_PIN, LOW);     // be sure to do this

  stepperX.setStepsPerMillimeter(STEPS_PER_MILIMETER);
  stepperY.setStepsPerMillimeter(STEPS_PER_MILIMETER);
  stepperZ.setStepsPerMillimeter(STEPS_PER_MILIMETER);
  Serial.begin(9600);  //initialize serial comms

  pinMode(ledPin, OUTPUT);
  String data; 
}

void loop() {


  if (Serial.available() > 0) {
    Serial.readBytesUntil('\n', receivedData, sizeof(receivedData));

    // Use a stringstream to parse the received data
    String dataString = receivedData;
    int delimiterPos1 = dataString.indexOf(':');
    int delimiterPos2 = dataString.lastIndexOf(':');

    if (delimiterPos1 != -1 && delimiterPos2 != -1) {
      String value1Str = dataString.substring(0, delimiterPos1);
      String value2Str = dataString.substring(delimiterPos1 + 1, delimiterPos2);
      String value3Str = dataString.substring(delimiterPos2 + 1);

      value1 = value1Str.toFloat();
      value2 = value2Str.toFloat();
      value3 = value3Str.toFloat();

      digitalWrite(ledPin, HIGH);
      delay(1500);
      digitalWrite(ledPin, LOW);

      Serial.println("1");
      delay(100);
    }
  }
  delay(100);

}

class CommunicationUI
{
private:
  /* data */
  char receivedData[50]; // Buffer to store received data

public:
  CommunicationUI(/* args */);
  ~CommunicationUI();

  void Read(){}
  void Send(){}


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
public:
  Grua(/* args */);
  ~Grua();
};

Grua::Grua(/* args */)
{
}

Grua::~Grua()
{
}

  // Movimiento de Motor X
  
  Serial.println("Motor X corriendo");
  MoveMotorNumerOfMilimeters(stepperX, 500);
  Serial.println("Motor Y corriendo");
  MoveMotorNumerOfMilimeters(stepperY, 100);
  Serial.println("Motor Z corriendo");
  MoveMotorNumerOfMilimeters(stepperZ, 10);
}

