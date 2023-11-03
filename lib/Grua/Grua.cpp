#include "Grua.h"

//Constructor
  Grua::Grua(float StepsPerMilimeterX, float StepsPerMilimeterY, float StepsPerMilimeterZ)
  {
    pinMode(STEPPERS_ENABLE_PIN, OUTPUT);       // be sure to do this

    ejeX.connectToPins(MOTOR_X_STEP_PIN, MOTOR_X_DIR_PIN);
    ejeY.connectToPins(MOTOR_Y_STEP_PIN, MOTOR_Y_DIR_PIN);
    ejeZ.connectToPins(MOTOR_Z_STEP_PIN, MOTOR_Z_DIR_PIN);

    digitalWrite(STEPPERS_ENABLE_PIN, LOW);     // be sure to do this

    ejeX.setStepsPerMillimeter(StepsPerMilimeterX);
    ejeY.setStepsPerMillimeter(StepsPerMilimeterY);
    ejeZ.setStepsPerMillimeter(StepsPerMilimeterZ);

  }

  int Grua::MoveInMilimeters(char eje, float milimeters)
  {
    eje = (char)toupper(eje);
    int response;
     switch (eje)
     {
     case 'X':
      ejeX.moveToPositionInMillimeters(milimeters);
      response = 1;
      break;
     case 'Y':
      ejeY.moveToPositionInMillimeters(milimeters);
      response = 1;
      break;
     case 'z':
      ejeZ.moveToPositionInMillimeters(milimeters);
      response = 1;
      break;
     default:
     //If something Wrong return 0
      response = 0;
      break;
     delay(300);
     return response;
     }
  }

  void Grua::SetSpeed(int x = 40, int y = 40, int z = 20)
  {
    FlexyStepper stepper[3] = {ejeX,ejeY,ejeZ};
    int arrayVel[3] = {x,y,z};
    for (int i = 0; i < 3; i++)
    {
      stepper[i].setSpeedInMillimetersPerSecond(arrayVel[i]);
    }
  }

