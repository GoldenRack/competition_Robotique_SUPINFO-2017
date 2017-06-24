#include <Moteur.h>
#include "moteur.h"

void getOrientation(){
  bool north;
  int mmAvant, mmArriere, mmDroite, mmGauche = getPos();
  if (getSonarDistance(SonarTriggerDroite, SonarEchoDroite) >= 500 - robotWidth/2 or 
    getSonarDistance(SonarTriggerGauche, SonarEchoGauche) >= 500 - robotWidth/2)north = true;
  else north = false;
  
  if (north){
    rotate(1, 2);
    moteur.stop(3);
}


void moveForward(){
  bool pushed = false;
  moteur.start(movementSpeed, motor);
  while (not pushed){
    if (getSonarDistance(SonarTriggerAvant, SonarEchoAvant) <= 50 or 
      getSonarDistance(SonarTriggerArriere, SonarEchoArriere) <= 50){
      delay(1000)
      pushed = true;
      moteur.stop(3);
      delay(300);
      moteurback(movementSpeed, motor);
    }
  }
}


void moveToCenter(){
  bool center = false;

  while(not center){
    if(getSonarDistance(SonarTriggerDroite, SonarEchoDroite) >= 500 - robotWidth or 
    getSonarDistance(SonarTriggerGauche, SonarEchoGauche) >= 500 - robotWidth){
      if(getSonarDistance(SonarTriggerDroite, SonarEchoDroite) <= 230 - robotWidth/2){
        rotate(1, 1, rotationTime, motor);
      } else {
        rotate(1, 2, rotationTime, motor);
      }
      center = true;
    }
  }
}


void parkingDance(){

  moteur.avancer(1, rotateSpeed);
  moteur.reculer(2, rotateSpeed);
  delay(rotationTime/2);
  moteur.reculer(1, rotateSpeed);
  moteur.avancer(2, rotateSpeed);
  delay(rotationTime);
  moteur.avancer(1, rotateSpeed);
  moteur.reculer(2, rotateSpeed);
  delay(rotationTime);
  moteur.reculer(1, rotateSpeed);
  moteur.avancer(2, rotateSpeed);
  delay(rotationTime*4);
  moteur.stop(3);


void parking(){
  getOrientation();
  moveForward();
  delay(1000);
  rotation(2, 1);
  moveForward();
  delay(1000);
  moveToCenter();
  parkingDance();
  moveForward();
}