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
}



void parking(int SonarTriggerDroite, int SonarEchoDroite,int SonarTriggerAllign, int SonarEchoAllign, Moteur moteur)
{
  long mm;
  allignement(SonarTriggerDroite, SonarEchoDroite, SonarTriggerAllign, SonarEchoAllign);
  motorstart(128,moteur);
  mm = getSonarDistance(SonarTriggerAvant, SonarEchoAvant);
  delay(10);
  while(mm >=30)
  {
    delay(10);
    mm = getSonarDistance(SonarTriggerAvant, SonarEchoAvant);
    delay(10);
  }
  delay(250);
  moteur.stop(3);
  moteurback(128, moteur);
  mm = getSonarDistance(SonarTriggerArriere, SonarEchoArriere);
  delay(10);
  while(mm >=30)
  {
    delay(10);
    mm = getSonarDistance(SonarTriggerArriere, SonarEchoArriere);
    delay(10);
  }
  delay(255);
  moteur.stop(3);
  motorstart(128,moteur);
  mm = getSonarDistance(SonarTriggerAvant, SonarEchoAvant);
  delay(10);
  while(mm >=40)
  {
    delay(10);
    mm = getSonarDistance(SonarTriggerAvant, SonarEchoAvant);
    delay(10);
  }
  moteur.stop(3);
  if(getSonarDistance(SonarTriggerDroite, SonarEchoDroite) > 41)
  {
    rotate(1,2,0,moteur);
  }
  else
  {
    rotate(1,1,0,moteur);
  }
  moteur.stop(3);
  motorstart(128,moteur);
  while(getcolor(control,0,0,0,0) == 1)
  {

  }
  break;


}