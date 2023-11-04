#ifndef Grua_h
#define Grua_h

#include <FlexyStepper.h>

class Grua
{
private:
  /* data */
   int MOTOR_X_STEP_PIN = 2;
   int MOTOR_Y_STEP_PIN = 3;
   int MOTOR_Z_STEP_PIN = 4;
   int MOTOR_X_DIR_PIN = 5;
   int MOTOR_Y_DIR_PIN = 6;
   int MOTOR_Z_DIR_PIN = 7;
   int STEPPERS_ENABLE_PIN = 8;
  float StepsPerMilimeterX = 30;
  float StepsPerMilimeterY = 30;
  float StepsPerMilimeterZ = 30;
    
public:
    FlexyStepper ejeX = FlexyStepper();
    FlexyStepper ejeY = FlexyStepper();
    FlexyStepper ejeZ = FlexyStepper();
//Constructor
  Grua();
  void Inicializar();
  int MoveInMilimeters(String eje, String milimeters);
  float getStepsPerMilimeterX();
  void setStepsPerMilimeterX(float value);
  // void SetSpeed(int x = 40, int y = 40, int z = 20);
};


#endif