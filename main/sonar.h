int getSonarDistance(int trigger, int echo){
  float mm;
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  mm = pulseIn(echo, HIGH)/5.8;
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
