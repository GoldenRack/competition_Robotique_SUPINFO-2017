#include <Moteur.h>

Moteur moteur(2,3,4,5,6,7);

//Définition des pins triggers et echos pour les sonars
int SonarTriggerAvant = 26;
int SonarTriggerArriere = 32;
int SonarTriggerDroite = 22;
int SonarTriggerGauche = 28;

int SonarEchoAvant = 27;
int SonarEchoArriere = 33;
int SonarEchoDroite = 23;
int SonarEchoGauche = 29;

int rotationTime = 500;

//Définis les variables de vitesse (mouvement de base et rotation)
unsigned char movementSpeed = 200;
unsigned char rotateSpeed = 255;

float robotWidth = 142.98;

//Permet d'utiliser les donnés d'un sonar grâce à SonarTrigger--- et SonarEcho--- en paramètre
int getSonarDistance(int trigger, int echo){
  float mm;
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  mm = pulseIn(echo, HIGH)/5.8;
  return mm;
}

//Permet de récupérer simultanément la distance de tout les sonars pour déterminer la position
int getPos(){
  int mmAvant, mmArriere, mmDroite, mmGauche;
  mmAvant = getSonarDistance(SonarTriggerAvant, SonarEchoAvant);
  mmArriere = getSonarDistance(SonarTriggerArriere, SonarEchoArriere);
  mmDroite = getSonarDistance(SonarTriggerDroite, SonarEchoDroite);
  mmGauche = getSonarDistance(SonarTriggerGauche, SonarEchoGauche);
  return mmAvant, mmArrieren, mmDroite, mmGauche;
}

//turn est le nombre de quart de tour à faire et roation est soit 1 ou soit 2 (1 pour tourner en antihoraire, 2 pour tourner en horaire). 1 si inéfrieur à 1 et 2 si supérieur à 2.
void rotate(char turn, char rotation){
  int firstWheel, secondWheel, i;
  if (rotation <= 1){
    firstWheel = 1;
    secondWheel = 2;
  } else {
    firstWheel = 2;
    secondWheel = 1;
  }
  for(i = 0 ; i < turn ; i++){
    moteur.avancer(firstWheel, 255);
    moteur.reculer(secondWheel, 255);
    delay(rotationTime);
    moteur.stop(3);
  }
}