int getSonarDistance(int trigger, int echo){
  long echo_distance;
  long mm;
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  echo_distance = pulseIn(echo, HIGH);
  mm = echo_distance / 5,8;
  return mm;
}

//Permet de récupérer simultanément la distance de tout les sonars pour déterminer la position
int getPos(int SonarTriggerAvant, int SonarTriggerArriere, int SonarTriggerDroite, int SonarTriggerGauche, int SonarEchoAvant, int SonarEchoArriere, int SonarEchoDroite, int SonarEchoGauche){
  int mmAvant, mmArriere, mmDroite, mmGauche;
  mmAvant = getSonarDistance(SonarTriggerAvant, SonarEchoAvant);
  delay(10);
  mmArriere = getSonarDistance(SonarTriggerArriere, SonarEchoArriere);
  delay(10);
  mmDroite = getSonarDistance(SonarTriggerDroite, SonarEchoDroite);
  delay(10);
  mmGauche = getSonarDistance(SonarTriggerGauche, SonarEchoGauche);
  delay(10);
  return mmAvant, mmArriere, mmDroite, mmGauche;
}

void getOrientation(int SonarTriggerAvant, int SonarTriggerArriere, int SonarTriggerDroite, int SonarTriggerGauche, int SonarEchoAvant, int SonarEchoArriere, int SonarEchoDroite, int SonarEchoGauche, int robotWidth, int rotationTime, Moteur moteur)
{
  bool north;
  int mmAvant, mmArriere, mmDroite, mmGauche = getPos(SonarTriggerAvant, SonarTriggerArriere, SonarTriggerDroite, SonarTriggerGauche, SonarEchoAvant, SonarEchoArriere, SonarEchoDroite, SonarEchoGauche);
  if (getSonarDistance(SonarTriggerDroite, SonarEchoDroite) >= 500 - robotWidth/2 or 
    getSonarDistance(SonarTriggerGauche, SonarEchoGauche) >= 500 - robotWidth/2)north = true;
  else north = false;
  
  if (north){
    rotate(1, 2, rotationTime, moteur);
    moteur.stop(3);
  }
}

long allignement(int SonarTriggerDroite, int SonarEchoDroite,int SonarTriggerAllign, int SonarEchoAllign)
{
  long mmAvant, mmAllign,delta;
  mmAvant = getSonarDistance(SonarTriggerDroite, SonarEchoDroite);
  delay(10);
  mmAllign = getSonarDistance(SonarTriggerAllign, SonarEchoAllign);
  delay(10);
  delta = mmAvant - mmAllign;
  return delta;
}

void ratrapage(int SonarTriggerDroite, int SonarEchoDroite,int SonarTriggerAllign, int SonarEchoAllign, Moteur moteur)
{
  long delta = allignement(SonarTriggerDroite, SonarEchoDroite, SonarTriggerAllign, SonarEchoAllign);
  delay(10);
  while((delta <= 5)^(delta >= -5))
  {
    if(delta <= 5)
    {
      delay(10);
      rotateA(1,1,100,moteur);
      delay(10);
      moteur.stop(3);
    }
    else
    {
      delay(10);
      rotateA(1,2,100,moteur);
      delay(10);
      moteur.stop(3);
    }
    delta = allignement(SonarTriggerDroite, SonarEchoDroite, SonarTriggerAllign, SonarEchoAllign);
    delay(10);
  }
  delay(10);
}
