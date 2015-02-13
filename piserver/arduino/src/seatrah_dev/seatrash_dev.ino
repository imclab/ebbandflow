#include <AccelStepper.h>

long Abottom = 500;   
long Atop = 80000;
long Bbottom = 500;
long Btop = 50000; 
long Cbottom = 500;
long Ctop = 50000;  
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

int upperLimitA = 6;    
int lowerLimitA = -1;   
int upperLimitB = 5;    
int lowerLimitB = -1; 
int upperLimitC = 5;    
int lowerLimitC = -1; 
int upperLimitD = 5;    
int lowerLimitD = -1;
int upperLimitE = 5;    
int lowerLimitE = -1;
int upperLimitF = 5;    
int lowerLimitF = -1;
int upperLimitG = 5;    
int lowerLimitG = -1;
int upperLimitH = 5;    
int lowerLimitH = -1; 
int upperLimitI = 5;    
int lowerLimitI = -1;     

int motorSpeed = 1600;
int motorAccel = 1600;

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

// long oldPosition;

void setup()
{  
  Serial.begin(57600);
  Serial.println("Arduino is READY");

  motorA.setMaxSpeed(motorSpeed);
  motorA.setSpeed(motorSpeed);
  motorA.setAcceleration(motorAccel);

  motorB.setMaxSpeed(motorSpeed);
  motorB.setSpeed(motorSpeed);
  motorB.setAcceleration(motorAccel);

  motorC.setMaxSpeed(motorSpeed);
  motorC.setSpeed(motorSpeed);
  motorC.setAcceleration(motorAccel);

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

  while(!Serial.available()) ;      //wait till get a serial input 
  
  motorA.moveTo(Abottom);
  motorB.moveTo(Bbottom);
  motorC.moveTo(Bbottom);
  motorD.moveTo(Dbottom);
  motorE.moveTo(Ebottom);
  motorF.moveTo(Fbottom);
  motorG.moveTo(Gbottom);
  motorH.moveTo(Hbottom);
  motorI.moveTo(Ibottom);
}

void loop()
{ 
  
  float seaLevel = 0;
  long currentPosition = 0;

  if (Serial.available() > 0) 
  { 
    seaLevel = Serial.parseFloat();
    int stopChar = Serial.read();

    switch (stopChar) {
      case 'A':
        goToSeaLevel(motorA, seaLevel, upperLimitA, lowerLimitA, Atop, Abottom);
      break;

      case 'B':
        goToSeaLevel(motorB, seaLevel, upperLimitB, lowerLimitB, Btop, Bbottom);
      break;

      case 'C':
        goToSeaLevel(motorC, seaLevel, upperLimitC, lowerLimitC, Ctop, Cbottom);
      break;

      case 'D':
        goToSeaLevel(motorD, seaLevel, upperLimitD, lowerLimitD, Dtop, Dbottom);
      break;

      case 'E':
        goToSeaLevel(motorE, seaLevel, upperLimitE, lowerLimitE, Etop, Ebottom);
      break;

      case 'F':
        goToSeaLevel(motorF, seaLevel, upperLimitF, lowerLimitF, Ftop, Fbottom);
      break;

      case 'G':
        goToSeaLevel(motorG, seaLevel, upperLimitG, lowerLimitG, Gtop, Gbottom);
      break;

      case 'H':
        goToSeaLevel(motorH, seaLevel, upperLimitH, lowerLimitH, Htop, Hbottom);
      break;

      case 'I':
        goToSeaLevel(motorI, seaLevel, upperLimitI, lowerLimitI, Itop, Ibottom);
      break;

      case 'Z':
        goHome(motorA, Abottom);
        goHome(motorB, Bbottom);
        goHome(motorC, Cbottom);
        goHome(motorD, Dbottom);
        goHome(motorE, Ebottom);
        goHome(motorF, Fbottom);
        goHome(motorG, Gbottom);
        goHome(motorH, Hbottom);
        goHome(motorI, Ibottom);
      break;

      case 'X':
        // upDown(motorA, Atop, Abottom);
        // upDown(motorB, Btop, Bbottom);
        // upDown(motorC, Ctop, Cbottom);
        // upDown(motorD, Dtop, Dbottom);
        // upDown(motorE, Etop, Ebottom);
        // upDown(motorF, Ftop, Fbottom);
        // upDown(motorG, Gtop, Gbottom);
        // upDown(motorH, Htop, Hbottom);
        // upDown(motorI, Itop, Ibottom);
      break;
    }    
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


void goToSeaLevel(AccelStepper &motor, float seaLevel, float upperLimit, float lowerLimit, long motorTop, long motorBottom) {

    float newPosition = mapfloat(seaLevel, upperLimit, lowerLimit, motorTop, motorBottom);

    if(motor.currentPosition() > motorTop) {
      motor.moveTo(motorTop);
    }
    if(motor.currentPosition() < motorBottom) {
      motor.moveTo(motorBottom);
    }

    motor.moveTo(newPosition);

}


float mapfloat(float seaLevel, float in_min, float in_max, float out_min, float out_max)
{
    return (seaLevel - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}



// void upDown(AccelStepper &motor, long top, long bottom) {
  
//   bool running = true;

//   Serial.print('Arduino Entering Up Down mode');

//   while(running == true) {
//     if(Serial.available() > 0) {
//       newCommand = Serial.read();
//       if(newCommand == 'X') {
//         running = 0;
//       }
//     }

//     if(motor.currentPosition() == bottom) {
//       motor.moveTo(top);
//     }
//     if (motor.currentPosition() == top) {
//       motor.moveTo(bottom);
//     }
//     if (motor.currentPosition() > top) {
//       motor.moveTo(top);
//     }
//     if (motor.currentPosition() < bottom) {
//       motor.moveTo(bottom);
//     }
//     if (motor.currentPosition() < top) {
//       motor.moveTo(top);
//     }
//   }

//   // motor.moveTo(top);
//   // motor.run();
// }


void goHome(AccelStepper &motor, long bottom) {
  Serial.print("all go home");

  if (motor.currentPosition() < bottom) {
    motor.moveTo(bottom);
  }

  motor.moveTo(bottom);
  // motor.run();
}



// void AgoToHeight(float seaLevel) {

//         Serial.print("seaLevel = ");
//         Serial.println(seaLevel); 
      
//         long motorHeight = mapfloat(seaLevel, 6, -1, Atop, Abottom);
        
//         Serial.print("going to: ");
//         Serial.println(motorHeight); 

//         motorA.moveTo(motorHeight);  
             
// }

// void BgoToHeight(float seaLevel) {

//         Serial.print("seaLevel = ");
//         Serial.println(seaLevel); 
      
//         long motorHeight = mapfloat(seaLevel, 6, -1, Btop, Bbottom);
        
//         Serial.print("going to: ");
//         Serial.println(motorHeight); 

//         motorB.moveTo(motorHeight);       
// }


// void AcheckPosition() {
//   if (motorA.distanceToGo() == 0)
//        {
//           long current = motorA.currentPosition();

//           if (current != oldPosition) {
//             Serial.print("motor A stopped at: ");
//             Serial.print(motorA.currentPosition());
//             Serial.print('\n');
//             oldPosition = current;
//           }
//        }
// }

// void BcheckPosition() {
//   if (motorB.distanceToGo() == 0)
//        {
//           long current = motorB.currentPosition();

//           if (current != oldPosition) {
//             Serial.print("motor B stopped at: ");
//             Serial.print(motorB.currentPosition());
//             Serial.print('\n');
//             oldPosition = current;
//           }
//        }
// }


// void defaultPattern() {
//   Serial.print("Entering Default Mode");

//   motorA.run();
//   motorB.run();

//   motorA.moveTo(Abottom);

//   int running = 1;
//   int newCommand; 

//   while(running == 1) {
//     if(Serial.available() > 0) {
//       newCommand = Serial.read();
//       if(newCommand == 'X') {
//         running = 0;
//       }
//     }
    
//     //MOTOR A
//     if (motorA.currentPosition() == Abottom) {
//        motorA.moveTo(Atop); 
//     }
//     if (motorA.currentPosition() == Atop) {
//        motorA.moveTo(Abottom); 
//     }
//     if (motorA.currentPosition() > Atop) {
//        motorA.moveTo(Atop); 
//     }
//     if (motorA.currentPosition() < Abottom) {
//        motorA.moveTo(Abottom); 
//     }

//     //MOTOR B
//     if (motorB.currentPosition() == Bbottom) {
//        motorB.moveTo(Btop); 
//     }
//     if (motorB.currentPosition() == Btop) {
//        motorB.moveTo(Bbottom); 
//     }
//     if (motorB.currentPosition() > Btop) {
//        motorB.moveTo(Btop); 
//     }
//     if (motorB.currentPosition() < Bbottom) {
//        motorB.moveTo(Bbottom); 
//     }
//   }

// }










