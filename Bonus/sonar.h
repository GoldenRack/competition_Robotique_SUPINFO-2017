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
  delayMicroseconds(10);
  mmArriere = getSonarDistance(SonarTriggerArriere, SonarEchoArriere);
  delayMicroseconds(10);
  mmDroite = getSonarDistance(SonarTriggerDroite, SonarEchoDroite);
  delayMicroseconds(10);
  mmGauche = getSonarDistance(SonarTriggerGauche, SonarEchoGauche);
  delayMicroseconds(10);
  return mmAvant, mmArriere, mmDroite, mmGauche;
}

