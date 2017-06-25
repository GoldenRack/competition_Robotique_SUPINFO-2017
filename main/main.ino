#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <Moteur.h>
#include <Servo.h> 
#include "motor.h"
#include "sonar.h"
#include "Capteurrgb.h"
#include "train_fantome.h"
#include "caisse.h"

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

int rotationTime = 18000;

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
  servoarm.write(0);
}

void loop() {
  caisse(SonarTriggerAvant, SonarEchoAvant, rotationTime, moteur);
  delay(50000);

}
