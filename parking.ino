#include <Moteur.h>
#include <main.ino>

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
  moteur.avancer(3, movementSpeed);
  while (not pushed){
    if (getSonarDistance(SonarTriggerAvant, SonarEchoAvant) <= 50 or 
      getSonarDistance(SonarTriggerArriere, SonarEchoArriere) <= 50){
      delay(1000)
      pushed = true;
      moteur.stop(3);
      delay(500);
      moteur.reculer(3, movementSpeed);
      delay(1000);
    }
  }
}

void moveToCenter(){
  bool center = false;

  while(not center){
    if(getSonarDistance(SonarTriggerDroite, SonarEchoDroite) >= 500 - robotWidth or 
    getSonarDistance(SonarTriggerGauche, SonarEchoGauche) >= 500 - robotWidth){
      if(getSonarDistance(SonarTriggerDroite, SonarEchoDroite) <= 230 - robotWidth/2){
        rotate(1, 1);
      } else {
        rotate(1, 2);
      }
      center = true;
    }
  }
}

void parkingDance(){

  moteur.avancer(1, rotateSpeed);
  moteur.reculer(2, rotateSpeed);
  delay(300);
  moteur.reculer(1, rotateSpeed);
  moteur.avancer(2, rotateSpeed);
  delay(600);
  moteur.avancer(1, rotateSpeed);
  moteur.reculer(2, rotateSpeed);
  delay(600);
  moteur.reculer(1, rotateSpeed);
  moteur.avancer(2, rotateSpeed);
  delay(rotationTime);
  moteur.stop(3);

void parking(){
  getOrientation();
  moveForward();
  rotation(2, 1);
  moveForward();
  moveToCenter();
  parkingDance();
  moveForward();
}