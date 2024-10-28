#include <AccelStepper.h>

//Define the step constant (fordi den bruker 4 gpio pins)
#define MotorInterfaceType 4

int stepper1MoveTo = 0;
//int stepper1MaxSpeed = 500.0;
int stepper1Acceleration = 200.0;
int stepper1StartSpeed = 200.0;
AccelStepper myStepper1(MotorInterfaceType, 8, 10, 9, 11);

/*
 * int stepper2MoveTo = 0;
 * int stepper2MaxSpeed = 1000.0;
 * int stepper2Acceleration = 200.0;
 * int stepper2StartSpeed = 200.0;
 * AccelStepper myStepper2 (MotorInterfaceType, 4, 6, 5, 7
 */


void setup() 
{
  Serial.begin(9600);  
  myStepper1.setMaxSpeed(1000.0);
  myStepper1.setAcceleration(stepper1Acceleration);
  myStepper1.setSpeed(stepper1StartSpeed);
  myStepper1.moveTo(stepper1MoveTo); //Default position is 0

  /*
  myStepper2.setMaxSpeed(1000.0);
  myStepper2.setAcceleration(stepper1Acceleration);
  myStepper2.setSpeed(stepper1StartSpeed);
  myStepper2.moveTo(stepper1MoveTo); //Default position is 0
   */
  
}

void stringSeparator(String stringToRead)
{
  // Create an array with 30 slots, is it enough?
  String stringToSave[10];
  size_t arrayCounter = 0;

  //Break down a string into an array of string
  for (size_t i = 0; i < stringToRead.length(); ++i)
  {
    if(stringToRead[i] != ',')
    {
      stringToSave[arrayCounter] += stringToRead[i];
    }
    else if(stringToRead[i] == ',' && arrayCounter == 0)
    {
      stepper1MoveTo = stringToSave[arrayCounter].toInt();
      ++arrayCounter;
    }
    else if(stringToRead[i] == ',' && arrayCounter == 1)
    {
      stepper1StartSpeed = stringToSave[arrayCounter].toInt();
      ++arrayCounter;
    }
    else if (stringToRead[i] == ',' && arrayCounter == 2)
    {
      stepper1Acceleration = stringToSave[arrayCounter].toInt();
    }
    /*
    else if(stringToRead[i] == ',' && arrayCounter == 3)
    {
      stepper2MoveTo = stringToSave[arrayCounter].toInt();
      ++arrayCounter;
    }
    else if(stringToRead[i] == ',' && arrayCounter == 4)
    {
      stepper2StartSpeed = stringToSave[arrayCounter].toInt();
      ++arrayCounter;
    }
    else if (stringToRead[i] == ',' && arrayCounter == 5)
    {
      stepper2Acceleration = stringToSave[arrayCounter].toInt();
    }
    */
  }
  Serial.print("stringToSave position 0: ");
  Serial.println(stringToSave[0]);
  stepper1MoveTo = stringToSave[0].toInt();

  /*
  Serial.println("stringToSave position 1: ");
  Serial.println(stringToSave[1]);
  stepper1StartSpeed = stringToSave[1].toInt();
  */
  Serial.print("stringToSave position 1: ");
  Serial.println(stringToSave[1]);
  stepper1Acceleration = stringToSave[1].toInt();


  //stepper1MaxSpeed = stringToSave[1].toInt();

  /*
  stepper2MoveTo = stringToSave[4].toInt();
  stepper2MaxSpeed = stringToSave[5].toInt();
  stepper2Acceleration = stringToSave[6].toInt();
  stepper2StartSpeed = stringToSave[7].toInt();  
  */
}

void loop() 
{
  if (Serial.available() > 0)
  {
    String moveToInput = Serial.readString();
    stringSeparator(moveToInput);
    
    //stepperMoveTo = moveToInput.toInt();
    myStepper1.setSpeed(stepper1StartSpeed);
    myStepper1.setAcceleration(stepper1Acceleration);
    myStepper1.moveTo(stepper1MoveTo);

    Serial.println("");
    Serial.println("");
    Serial.print("Speed: ");
    Serial.println(stepper1StartSpeed);
    Serial.print("Acceleration: ");
    Serial.println(stepper1Acceleration);
    Serial.print("Move To: ");
    Serial.println(stepper1MoveTo);
    
    Serial.println(stepper1MoveTo);
    
  }
  // Change direction once the motor reaches target position
  //if (myStepper.distanceToGo() == 0)
  //{
  //myStepper.moveTo(-myStepper.currentPosition());
  //}
  // Move the motor one step
  
  myStepper1.run();
  //myStepper2.run();
  
}
