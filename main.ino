#include <Adafruit_TCS34725.h>
#include <Moteur.h>
#include <Servo.h>
#include "Capteurrgb"
#include "motor.h"
#include "parking.ino"
#include "caisse.ino"
#include "bowling.ino"

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

int rotationTime = 775;

unsigned char movementSpeed = 200;
unsigned char rotateSpeed = 255;

float robotWidth = 142.98;

Servo servorgb;
Servo servoarm;

//Récupère la distance donnée par un sonar
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
    moteur.avancer(firstWheel, rotationSpeed);
    moteur.reculer(secondWheel, rotationSpeed);
    delay(rotationTime);
    moteur.stop(3);
  }
}


void setup() 
{
  pinMode(SonarTriggerAvant, OUTPUT);
  pinMode(SonarTriggerArriere, OUTPUT);
  pinMode(SonarTriggerDroite, OUTPUT);
  pinMode(SonarTriggerGauche, OUTPUT);

  pinMode(SonarEchoAvant, INPUT);
  pinMode(SonarEchoArriere, INPUT);
  pinMode(SonarEchoDroite, INPUT);
  pinMode(SonarEchoGauche, INPUT);

  digitalWrite(SonarTriggerAvant, LOW);
  digitalWrite(SonarTriggerArriere, LOW);
  digitalWrite(SonarTriggerDroite, LOW);
  digitalWrite(SonarTriggerGauche, LOW);
  servorgb.attach(11);
  servoarm.attach(12);
} 


void loop() {
  char step = 0;
  parking();
  while(step != 1){
  	if(getColor(clear, rouge, vert, bleu, tcs, controle) == 2){
  		step = 1;
  		delay(2000);
  		caisse();
  	}
  }
  while(step != 2){
  	if(getColor(clear, rouge, vert, bleu, tcs, controle) == 3){
  		step = 2;
  		train();
  	}
  }
  while(step != 3){
  	if(getColor(clear, rouge, vert, bleu, tcs, controle) == 4){
  		step = 3;
  		rollerCoaster();
  	}
  }
  while(step != 4){
  	if(getColor(clear, rouge, vert, bleu, tcs, controle) == 1){
  		step = 4;
  		bowling();
  	}
  }
  while(step != 5){
  	if(getColor(clear, rouge, vert, bleu, tcs, controle) == 5){
  		step = 5;
  		balloon();
  	}
  }
  while(step != 6){
  	if(getColor(clear, rouge, vert, bleu, tcs, controle) == 6){
  		step = 6;
  		balloon();
  	}
  }
} 