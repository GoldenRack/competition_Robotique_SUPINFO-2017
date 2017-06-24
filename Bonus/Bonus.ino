#include <Moteur.h>
#include <Servo.h> 
#include "motor.h"
#include "sonar.h"


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

int rotationTime = 550;

Servo servorgb;
Servo servoarm;

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

  
  servorgb.attach(12);
  servoarm.attach(11);
  servorgb.write(40);
  servoarm.write(0);
  Serial.begin(9600);
  
}


void loop()
{
  motorstart(128, moteur);
  delay(1000);
  while(getSonarDistance(SonarTriggerArriere, SonarEchoArriere) < 55){
    delayMicroseconds(10);
  }
  moteur.stop(3);
  delay(1000);
  while (getSonarDistance(SonarTriggerArriere, SonarEchoArriere) > 25)
  {
    moteur.reculer(3, 128);
    delayMicroseconds(10);
  }
  moteur.avancer(2, 255);
  moteur.reculer(1, 255);
  delay(rotationTime);
  moteur.stop(3);
  moteur.avancer(3, 255);
  while (getSonarDistance(SonarTriggerArriere, SonarEchoArriere) < 1000)
  {
    moteur.avancer(3, 255);
    delayMicroseconds(10);
  }  
  moteur.stop(3);
  servoarm.write(140);
  delay(2000);
  servoarm.write(0);
  delay(100000);
}

