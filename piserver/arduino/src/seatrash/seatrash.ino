
#include <AccelStepper.h>

long Abottom = 500;   
long Atop = 80000;   
long Bbottom = 500;
long Btop = 40000;    
long Cbottom = 500;
long Ctop = 60000;     
long Dbottom = 500;
long Dtop = 50000;  
long Ebottom = 500;
long Etop = 60000;
long Fbottom = 500;
long Ftop = 50000;
long Gbottom = 500;
long Gtop = 60000;
long Hbottom = 500;
long Htop = 30000;
long Ibottom = 500;
long Itop = 40000;

int motorSpeed = 1600;
int motorAccel = 500;

int motorADirPin = 2;
int motorAStepPin = 3;

int motorBDirPin = 4;
int motorBStepPin = 5;

int motorCDirPin = 8;
int motorCStepPin = 9;

int motorDDirPin = 10;
int motorDStepPin = 11;

int motorEDirPin = 12;
int motorEStepPin = 13;

int motorFDirPin = 0;
int motorFStepPin = 1;

int motorGDirPin = A4;
int motorGStepPin = A5;

int motorHDirPin = A0;
int motorHStepPin = A1;

int motorIDirPin = A2;
int motorIStepPin = A3;

AccelStepper motorA(1, motorAStepPin, motorADirPin);
AccelStepper motorB(1, motorBStepPin, motorBDirPin);
AccelStepper motorC(1, motorCStepPin, motorCDirPin);
AccelStepper motorD(1, motorDStepPin, motorDDirPin);
AccelStepper motorE(1, motorEStepPin, motorEDirPin);
AccelStepper motorF(1, motorFStepPin, motorFDirPin);
AccelStepper motorG(1, motorGStepPin, motorGDirPin);
AccelStepper motorH(1, motorHStepPin, motorHDirPin);
AccelStepper motorI(1, motorIStepPin, motorIDirPin);

void setup()
{  
  Serial.begin(57600);
  Serial.println("Arduino is READY");

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

  motorE.setMaxSpeed(motorSpeed);
  motorE.setSpeed(motorSpeed);
  motorE.setAcceleration(motorAccel);
  motorE.moveTo(Ebottom);

  motorF.setMaxSpeed(motorSpeed);
  motorF.setSpeed(motorSpeed);
  motorF.setAcceleration(motorAccel);
  motorF.moveTo(Fbottom);

  motorG.setMaxSpeed(motorSpeed);
  motorG.setSpeed(motorSpeed);
  motorG.setAcceleration(motorAccel);
  motorG.moveTo(Gbottom);

  motorH.setMaxSpeed(motorSpeed);
  motorH.setSpeed(motorSpeed);
  motorH.setAcceleration(motorAccel);
  motorH.moveTo(Hbottom);
  
  motorI.setMaxSpeed(motorSpeed);
  motorI.setSpeed(motorSpeed);
  motorI.setAcceleration(motorAccel);
  motorI.moveTo(Ibottom);
  
}

void loop()
{ 

  //MOTOR A BASIC TEST
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
  
  //MOTOR E
  if (motorE.currentPosition() == Ebottom) {
     motorE.moveTo(Etop); 
  }
  if (motorE.currentPosition() == Etop) {
     motorE.moveTo(Ebottom); 
  }
  if (motorE.currentPosition() > Etop) {
     motorE.moveTo(Etop); 
  }
  if (motorE.currentPosition() < Ebottom) {
     motorE.moveTo(Ebottom); 
  }

  //MOTOR F
  if (motorF.currentPosition() == Fbottom) {
     motorF.moveTo(Ftop); 
  }
  if (motorF.currentPosition() == Ftop) {
     motorF.moveTo(Fbottom); 
  }
  if (motorF.currentPosition() > Ftop) {
     motorF.moveTo(Ftop); 
  }
  if (motorF.currentPosition() < Fbottom) {
     motorF.moveTo(Fbottom); 
  }

  //MOTOR G
  if (motorG.currentPosition() == Gbottom) {
     motorG.moveTo(Gtop); 
  }
  if (motorG.currentPosition() == Gtop) {
     motorG.moveTo(Gbottom); 
  }
  if (motorG.currentPosition() > Gtop) {
     motorG.moveTo(Gtop); 
  }
  if (motorG.currentPosition() < Gbottom) {
     motorG.moveTo(Gbottom); 
  }

  //MOTOR H
  if (motorH.currentPosition() == Hbottom) {
     motorH.moveTo(Htop); 
  }
  if (motorH.currentPosition() == Htop) {
     motorH.moveTo(Hbottom); 
  }
  if (motorH.currentPosition() > Htop) {
     motorH.moveTo(Htop); 
  }
  if (motorH.currentPosition() < Hbottom) {
     motorH.moveTo(Hbottom); 
  }

  //MOTOR I
  if (motorI.currentPosition() == Ibottom) {
     motorI.moveTo(Itop); 
  }
  if (motorI.currentPosition() == Itop) {
     motorI.moveTo(Ibottom); 
  }
  if (motorI.currentPosition() > Itop) {
     motorI.moveTo(Itop); 
  }
  if (motorI.currentPosition() < Ibottom) {
     motorI.moveTo(Ibottom); 
  }

  motorA.run();
  motorB.run();
  motorC.run();  
  motorD.run();  
  motorE.run(); 
  motorF.run(); 
  motorG.run();  
  motorH.run();
  motorI.run();

}

void changePosition(AccelStepper motor, float seaLevel, long lowerLimit, long upperLimit) {
    
    long motorPosition = mapfloat(seaLevel, 0, 6.0, lowerLimit, upperLimit);
    Serial.print("seaLevel: ");
    Serial.println(seaLevel);
    Serial.print("Motor Position: ");
    Serial.println(motorPosition);
    motor.moveTo(motorPosition);   
    // motor.run();
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
