#include <Moteur.h>

//Définition des pins triggers et echos pour les sonars
int SonarTriggerAvant = 26;
int SonarTriggerArriere = 32;
int SonarTriggerDroite = 22;
int SonarTriggerGauche = 28;

int SonarEchoAvant = 27;
int SonarEchoArriere = 33;
int SonarEchoDroite = 23;
int SonarEchoGauche = 29;

//Définis les variables de vitesse (mouvement de base et rotation)
char movementSpeed = 200;
char rotateSpeed = 255;

//Permet d'utiliser les donnés d'un sonar grâce à SonarTrigger--- et SonarEcho--- en paramètre
int getSonarDistance(int trigger, int echo){
  int mm;
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  mm = pulseIn(echo, HIGH)/5.8;
  return mm;
}

//Permet de récupérer simultanément la distance de tout les sonars pour déterminer la position
int getPos(){
  int mmAvant, mmArriere, mmDroite, mmGauche, mmList[3];
  mmAvant = getSonarDistance(SonarTriggerAvant, SonarEchoAvant);
  mmArriere = getSonarDistance(SonarTriggerArriere, SonarEchoArriere);
  mmDroite = getSonarDistance(SonarTriggerDroite, SonarEchoDroite);
  mmGauche = getSonarDistance(SonarTriggerGauche, SonarEchoGauche);
  return mmAvant, mmArrieren, mmDroite, mmGauche;
}