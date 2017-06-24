#include <Moteur.h>
#include <global.ino>
int SonarTriggerAvant = 26;
int SonarTriggerArriere = 32;
int SonarTriggerDroite = 22;
int SonarTriggerGauche = 28;

int SonarEchoAvant = 27;
int SonarEchoArriere = 33;
int SonarEchoDroite = 23;
int SonarEchoGauche = 29;

unsigned char movementSpeed = 200;
unsigned char rotateSpeed = 255;
unsigned char color ;
float distance ;

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

Moteur moteur(2,3,4,5,6,7);

void Ftrain(servo2)
{	
	unsigned char color ;
	float distance ;
	color = getcolor();
	if  (color = 3)/// couleur gris train fantom
	{	
		moteur.stop(3);
		distance = getSonarDistance(  SonarTriggerArriere, SonarEchoArriere);
		servo2.write(90);
		while(distance<190)
			{

			distance = getSonarDistance(SonarTriggerArriere, SonarEchoArriere)
			moteur.avancer(3,200)



		  
			 // statement
			}
			moteur.stop(3);
			servo2.write(0);
			moteur.avancer(3,200)

		

	}












