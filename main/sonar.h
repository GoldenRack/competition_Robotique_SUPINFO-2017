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
  mmArriere = getSonarDistance(SonarTriggerArriere, SonarEchoArriere);
  mmDroite = getSonarDistance(SonarTriggerDroite, SonarEchoDroite);
  mmGauche = getSonarDistance(SonarTriggerGauche, SonarEchoGauche);
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
