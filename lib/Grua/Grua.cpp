#include "Grua.h"

//Constructor
  Grua::Grua()
  {
      
    pinMode(STEPPERS_ENABLE_PIN, OUTPUT);       // be sure to do this

    ejeX.connectToPins(MOTOR_X_STEP_PIN, MOTOR_X_DIR_PIN);
    ejeY.connectToPins(MOTOR_Y_STEP_PIN, MOTOR_Y_DIR_PIN);
    ejeZ.connectToPins(MOTOR_Z_STEP_PIN, MOTOR_Z_DIR_PIN);

    digitalWrite(STEPPERS_ENABLE_PIN, LOW);     // be sure to do this

    ejeX.setStepsPerMillimeter(172);
    ejeY.setStepsPerMillimeter(172);
    ejeZ.setStepsPerMillimeter(172);
  }
  void Grua::Inicializar()
  {

  }

  int Grua::MoveInMilimeters(String eje, float milimeters)
  {
    int response;
    if (eje == "X")
    {
      /* code */
      // ejeX.setStepsPerMillimeter(25 * 1);
      ejeX.setSpeedInMillimetersPerSecond(40.0);
      ejeX.setAccelerationInMillimetersPerSecondPerSecond(20.0);
      ejeX.moveToPositionInMillimeters(milimeters);
      response = 1;
    }
    else if (eje == "Y")
    {
      /* code */
      // ejeY.setStepsPerMillimeter(25 * 1);
      ejeY.setSpeedInMillimetersPerSecond(40.0);
      ejeY.setAccelerationInMillimetersPerSecondPerSecond(20.0);
      ejeY.moveToPositionInMillimeters(milimeters);
      response = 1;
    }
    else if(eje == "Z")
    {
      /* code */
      // ejeZ.setStepsPerMillimeter(25 * 1);
      ejeZ.setSpeedInMillimetersPerSecond(30.0);
      ejeZ.setAccelerationInMillimetersPerSecondPerSecond(10.0);
      ejeZ.moveToPositionInMillimeters(milimeters);
      response = 1;
    }else{
      response = 0;
    }
    delay(300);
    return response;

    //  switch (eje)
    //  {
    //  case 'X':
    //   ejeX.moveToPositionInMillimeters(milimeters);
    //   response = 1;
    //   break;
    //  case 'Y':
    //   ejeY.moveToPositionInMillimeters(milimeters);
    //   response = 1;
    //   break;
    //  case 'z':
    //   ejeZ.moveToPositionInMillimeters(milimeters);
    //   response = 1;
    //   break;
    //  default:
    //  //If something Wrong return 0
    //   response = 0;
    //   break;
    //  delay(300);
    //  return response;
    //  }
  }

  float Grua::getStepsPerMilimeterX(){
     return ejeX.getCurrentVelocityInStepsPerSecond();
  }
  void Grua::setStepsPerMilimeterX(float value){
    // StepsPerMilimeterX = value;
  }

  // void Grua::SetSpeed(int x = 40, int y = 40, int z = 20)
  // {
  //   FlexyStepper stepper[3] = {ejeX,ejeY,ejeZ};
  //   int arrayVel[3] = {x,y,z};
  //   for (int i = 0; i < 3; i++)
  //   {
  //     stepper[i].setSpeedInMillimetersPerSecond(arrayVel[i]);
  //   }
  // }

