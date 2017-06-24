#include <Moteur.h>
#include <parking.ino>
#include <global.ino>

//Initialise le mode des pins
void setup(){
  pinMode(SonarTriggerAvant, OUTPUT);
  pinMode(SonarTriggerArriere, OUTPUT);
  pinMode(SonarTriggerDroite, OUTPUT);
  pinMode(SonarTriggerGauche, OUTPUT);

  pinMode(SonarEchoAvant, INPUT);
  pinMode(SonarEchoArriere, INPUT);
  pinMode(SonarEchoDroite, INPUT);
  pinMode(SonarEchoGauche, INPUT);

  Serial.begin(9600);
}

void loop(){

	parking()

}