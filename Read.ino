#include <Moteur.h>

int enA = 8;
int enB = 9;

int avB = 6;
int arB = 5;

int avA = 4;
int arA = 3;

int A = A3;
int B = A4;

int valeur1;
int valeur2;

Moteur moteur(avB, arB, enB, avA, arA, enA);

void setup() {
  
  Serial.begin(9600);
  

}

void loop() {
  //moteur.gauche(1, 1024);
 // moteur.gauche(2, 1024);
  

  valeur1 = analogRead(A);
  valeur2 = analogRead(B);

  Serial.println("A");
  Serial.println(A);
  Serial.println("B");
  Serial.println(B);

  //delay(1000);

}