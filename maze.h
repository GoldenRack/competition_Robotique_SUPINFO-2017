#include <Motor.h>
#include "motor.h"

void maze(){
  moteurstart(movementSpeed, motor);
  delay(3000);
  servoarm.write(90);
  moteur.stop(1);
  delay(rotationTime*2);
  servoarm.write(0);
  moteur.avancer(1, movementSpeed);
  moteur.stop(2);
  delay(rotationTime);
  moteur.avancer(2);
}
