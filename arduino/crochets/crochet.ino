//CROCHET
//  Pins 6 and 7 seem to be non-functional for motors

#include <AccelStepper.h>

long Abottom = 500;   
long Atop = 9000;   //115000;  //medium green algae
long Bbottom = 500;
long Btop = 8000;    // blue thin
long Cbottom = 500;
long Ctop = 10000;     // medium clear
long Dbottom = 500;
long Dtop = 11000;  //large with green ink


int motorSpeed = 1600;
int motorAccel = 1600;

int motorADirPin = 0;
int motorAStepPin = 1;

int motorBDirPin = 10;
int motorBStepPin = 11;

int motorCDirPin = 4;
int motorCStepPin = 5;

int motorDDirPin = 8;
int motorDStepPin = 9;

AccelStepper motorA(1, motorAStepPin, motorADirPin);
AccelStepper motorB(1, motorBStepPin, motorBDirPin);
AccelStepper motorC(1, motorCStepPin, motorCDirPin);
AccelStepper motorD(1, motorDStepPin, motorDDirPin);


void setup()
{  
  motorA.setMaxSpeed(motorSpeed);
  motorA.setSpeed(motorSpeed);
  motorA.setAcceleration(motorAccel);
  motorA.moveTo(Abottom);
  
  motorB.setMaxSpeed(motorSpeed);
  motorB.setSpeed(motorSpeed);
  motorB.setAcceleration(motorAccel);
  motorB.moveTo(Bbottom);

  motorC.setMaxSpeed(motorSpeed);
  motorC.setSpeed(motorSpeed);
  motorC.setAcceleration(motorAccel);
  motorC.moveTo(Cbottom); 

  motorD.setMaxSpeed(motorSpeed);
  motorD.setSpeed(motorSpeed);
  motorD.setAcceleration(motorAccel);
  motorD.moveTo(Dbottom);

  
}

void loop()
{
  //MOTOR A
  if (motorA.currentPosition() == Abottom) {
     motorA.moveTo(Atop); 
  }
  if (motorA.currentPosition() == Atop) {
     motorA.moveTo(Abottom); 
  }
  if (motorA.currentPosition() > Atop) {
     motorA.moveTo(Atop); 
  }
  if (motorA.currentPosition() < Abottom) {
     motorA.moveTo(Abottom); 
  }

  //MOTOR B
  if (motorB.currentPosition() == Bbottom) {
     motorB.moveTo(Btop); 
  }
  if (motorB.currentPosition() == Btop) {
     motorB.moveTo(Bbottom); 
  }
  if (motorB.currentPosition() > Btop) {
     motorB.moveTo(Btop); 
  }
  if (motorB.currentPosition() < Bbottom) {
     motorB.moveTo(Bbottom); 
  }

  //MOTOR C
  if (motorC.currentPosition() == Cbottom) {
     motorC.moveTo(Ctop); 
  }
  if (motorC.currentPosition() == Ctop) {
     motorC.moveTo(Cbottom); 
  }
  if (motorC.currentPosition() > Ctop) {
     motorC.moveTo(Ctop); 
  }
  if (motorC.currentPosition() < Cbottom) {
     motorC.moveTo(Cbottom); 
  }

  //MOTOR D
  if (motorD.currentPosition() == Dbottom) {
     motorD.moveTo(Dtop); 
  }
  if (motorD.currentPosition() == Dtop) {
     motorD.moveTo(Dbottom); 
  }
  if (motorD.currentPosition() > Dtop) {
     motorD.moveTo(Dtop); 
  }
  if (motorD.currentPosition() < Dbottom) {
     motorD.moveTo(Dbottom); 
  }
  
  //upDown(motorA, Atop, Abottom);

  motorA.run();
  motorB.run();
  motorC.run();  
  motorD.run();  

}



// long upDown(AccelStepper motor, long top, long bottom) {
  
//   if (motor.currentPosition() == bottom) {
//      motor.moveTo(top); 
//   }
//   if (motor.currentPosition() == top) {
//      motor.moveTo(bottom); 
//   }
//   if (motor.currentPosition() > top) {
//      motor.moveTo(top); 
//   }
//   if (motor.currentPosition() < bottom) {
//      motor.moveTo(bottom); 
//   }
 
//   motor.run();
//   return motor.currentPosition();
// }
