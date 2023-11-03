#ifndef Grua_h
#define Grua_h

#include <FlexyStepper.h>

class Grua
{
private:
  /* data */
    FlexyStepper ejeX = FlexyStepper();
    FlexyStepper ejeY = FlexyStepper();
    FlexyStepper ejeZ = FlexyStepper();
    const int MOTOR_X_STEP_PIN = 2;
    const int MOTOR_Y_STEP_PIN = 3;
    const int MOTOR_Z_STEP_PIN = 4;
    const int MOTOR_X_DIR_PIN = 5;
    const int MOTOR_Y_DIR_PIN = 6;
    const int MOTOR_Z_DIR_PIN = 7;
    const int STEPPERS_ENABLE_PIN = 8;
public:
//Constructor
  Grua(float StepsPerMilimeterX, float StepsPerMilimeterY, float StepsPerMilimeterZ);
  int MoveInMilimeters(char eje, float milimeters);
  void SetSpeed(int x = 40, int y = 40, int z = 20);
};


#endif