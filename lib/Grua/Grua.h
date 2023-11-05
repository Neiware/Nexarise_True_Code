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
   float speedMilimeterPerSecondX;
   float speedMilimeterPerSecondY;
   float speedMilimeterPerSecondZ;
  // float StepsPerMilimeterX = 30;//calculate with the rule.
  // float StepsPerMilimeterY = 30;
  // float StepsPerMilimeterZ = 30;
    FlexyStepper ejeX;
    FlexyStepper ejeY;
    FlexyStepper ejeZ;
  
    
public:
//Constructor
  Grua();
  void Inicializar();
  int MoveInMilimeters(String eje, float milimeters);
  float getStepsPerMilimeterX();
  void setStepsPerMilimeterX(float value);
  // void SetSpeed(int x = 40, int y = 40, int z = 20);
};


#endif