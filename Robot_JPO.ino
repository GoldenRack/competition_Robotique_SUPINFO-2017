#include <Moteur.h> 

int avg = 3;
int avd = 7; 
int arg = 5; 
int ard = 6;
int trigg = 13;
int echo = 2;
int enableA = 9;
float limite = 500;
boolean arret = false;
bool turn = true;
int i = 0;

Moteur moteur(arg, avg, enableA, ard, avd, enableA);

float distance() { 
  float rep;
  float dist;
  digitalWrite(trigg, LOW);
  delay(2);
  digitalWrite(trigg, HIGH);
  delay(10);
  digitalWrite(trigg, LOW);
  rep = pulseIn(echo,HIGH);
  dist = (rep/58)*10;    
  Serial.print(dist);
  Serial.println("mm");
  return dist;
  
}

void setup() {
  Serial.begin(9600);
  pinMode(arg, OUTPUT);//arrière gauche
  pinMode(avg, OUTPUT);//avant gauche
  pinMode(ard, OUTPUT);//arrière droit
  pinMode(avd, OUTPUT);//avant droit
  pinMode(trigg, OUTPUT);
  pinMode(echo, INPUT);

  digitalWrite(avg, LOW);
  digitalWrite(avd, LOW);
  digitalWrite(ard, LOW);
  digitalWrite(arg, LOW);
  digitalWrite(trigg, LOW);
}

void loop(){
  if ((distance() > limite) && arret == false){
    moteur.droite(1,60);
    moteur.droite(2,60);
    i ++;
    Serial.println(i);
  }
  else{
    arret = true;
    moteur.stop(3);
    delay(500);
  }
  if (arret && turn){
    moteur.droite(2,80);
    moteur.gauche(1,80);
    delay(1000);
    turn = false;    
  }
  if (not turn){
    moteur.stop(3);
    delay(1000);
    for (int x = 0; x <= i ; x++){
      moteur.droite(1,60);
      moteur.droite(2,60);
      Serial.println(x);
      delay(12);
    }
    moteur.stop(3);
    delay(500);
    moteur.droite(1,80);
    moteur.gauche(2,80);
    delay(1000);
    moteur.stop(3);
    delay(3600000);    
  }
  
  
}









