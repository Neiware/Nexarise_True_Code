#include "Grua.h"

//Constructor
  Grua::Grua()
  {
    


  }
  void Grua::Inicializar()
  {
    pinMode(STEPPERS_ENABLE_PIN, OUTPUT);       // be sure to do this

    ejeX.connectToPins(MOTOR_X_STEP_PIN, MOTOR_X_DIR_PIN);
    ejeY.connectToPins(MOTOR_Y_STEP_PIN, MOTOR_Y_DIR_PIN);
    ejeZ.connectToPins(MOTOR_Z_STEP_PIN, MOTOR_Z_DIR_PIN);

    digitalWrite(STEPPERS_ENABLE_PIN, LOW);     // be sure to do this
    
    ejeX.setStepsPerMillimeter(getStepsPerMilimeterX());
    ejeY.setStepsPerMillimeter(StepsPerMilimeterY);
    ejeZ.setStepsPerMillimeter(StepsPerMilimeterZ);
    // Serial.print(StepsPerMilimeterX);
    // Serial.println(StepsPerMilimeterY);
  }

  int Grua::MoveInMilimeters(String eje, String milimeters)
  {
    int response;
    if (eje == "X")
    {
      /* code */
      ejeX.moveToPositionInMillimeters(milimeters.toFloat());
      response = 1;
    }
    else if (eje == "Y")
    {
      /* code */
      ejeY.moveToPositionInMillimeters(milimeters.toFloat());
      response = 1;
    }
    else if(eje == "Z")
    {
      /* code */
      ejeZ.moveToPositionInMillimeters(milimeters.toFloat());
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
    return StepsPerMilimeterX;
  }
  void Grua::setStepsPerMilimeterX(float value){
    StepsPerMilimeterX = value;
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

