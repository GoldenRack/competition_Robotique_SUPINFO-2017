#include <Adafruit_TCS34725.h>
#include <Moteur.h>
#include <Servo.h> 
#include "motor.h"

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

  
  servorgb.attach(11);
  servoarm.attach(12);
}

void loop() {
  moteur.avancer(3, 255);
  delay(3000);
  moteur.stop(3);
  delay(5000);
}
