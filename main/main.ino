#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <Moteur.h>
#include <Servo.h> 
#include "motor.h"
#include "sonar.h"
#include "Capteurrgb.h"
#include "train_fantome.h"
#include "caisse.h"
#include "montagne.h"
#include "bowling.h"
#include "parking.h"

Moteur moteur(2,3,4,5,6,7);

//Définition des pins triggers et echos pour les sonars
int SonarTriggerAvant = 26;
int SonarTriggerArriere = 44;
int SonarTriggerDroite = 22;

int SonarTriggerGauche = 28;

int SonarEchoAvant = 27;
int SonarEchoArriere = 45;
int SonarEchoDroite = 23;

int SonarEchoGauche = 29;

int rotationTime = 18000;

int control = 8;

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

  Serial.begin(9600);

  pinMode(control, OUTPUT);
  
  servorgb.attach(12);
  servoarm.attach(11);
  servoarm.write(10);
}

void loop() {
    //parking(SonarTriggerAvant, SonarEchoAvant, SonarTriggerArriere, SonarEchoArriere, SonarTriggerDroite, SonarEchoDroite, moteur, control, rotationTime);

  //caisse( SonarTriggerAvant, SonarEchoAvant, SonarTriggerDroite, SonarEchoDroite, rotationTime, moteur, servoarm, control);
  //Ftrain(servoarm, SonarTriggerArriere, SonarEchoArriere, SonarEchoDroite, SonarTriggerDroite, control, moteur);
  //montagne(control, moteur);  
  strike(moteur, rotationTime, SonarTriggerAvant, SonarTriggerArriere, SonarEchoArriere,SonarTriggerDroite, SonarEchoDroite, SonarEchoAvant);
}
