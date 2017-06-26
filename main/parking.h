void parking(int SonarTriggerAvant, int SonarEchoAvant, int SonarTriggerArriere, int SonarEchoArriere, int SonarTriggerDroite, int SonarEchoDroite, Moteur moteur, int control, int rotationTime)
{
  long mm,mmAr;
  motorstart(128,moteur);
  mm = getSonarDistance(SonarTriggerAvant, SonarEchoAvant);
  delay(10);
  while(mm >=30)
  {
    delay(10);
    mm = getSonarDistance(SonarTriggerAvant, SonarEchoAvant);
    delay(10);
  }
  delay(50);
  moteur.stop(3);
  moteurback(128, moteur);
  delay(10);
  mmAr = getSonarDistance(SonarTriggerArriere, SonarEchoArriere);
  delay(10);
  while(mmAr >=30)
  {
    delay(10);
    mmAr = getSonarDistance(SonarTriggerArriere, SonarEchoArriere);
    delay(10);
  }
  moteur.stop(3);
  delay(3000);
  motorstart(128,moteur);
  mm = getSonarDistance(SonarTriggerAvant, SonarEchoAvant);
  delay(10);
  while(mm >=500)
  {
    delay(10);
    mm = getSonarDistance(SonarTriggerAvant, SonarEchoAvant);
    delay(10);
  }
  moteur.stop(3);
  if(getSonarDistance(SonarTriggerDroite, SonarEchoDroite) > 410)
  {
    rotate(1,2,0,moteur);
  }
  else
  {
    rotate(1,1,0,moteur);
  }
  moteur.stop(3);
  motorstart(128,moteur);
  while(getcolor(control,0,0,0,0) != 2)
  {
    delay(10);
  }


}
