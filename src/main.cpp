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
}

void loop() {
  // Movimiento de Motor X
  
  Serial.println("Motor X corriendo");
  MoveMotorNumerOfMilimeters(stepperX, 500);
  Serial.println("Motor Y corriendo");
  MoveMotorNumerOfMilimeters(stepperY, 100);
  Serial.println("Motor Z corriendo");
  MoveMotorNumerOfMilimeters(stepperZ, 10);
}

