#include <Motor.h>
#include "motor.h"

void departure(){
	motorstart(movementSpeed, motor);
	delay(2300);
	motor.stop(3);
	motor.avancer(1, rotationSpeed);
	delay(rotationTime);
	motorstart(movementSpeed, motor);
}

void strike(){
	bool inFront = false;
	while (not inFront){
		if(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) <= 50){
			inFront = true;
			moteurstart(rotationSpeed, motor);
			delay(2000);
			moteur.stop(3);
		}
	}
	moteurback(movementSpeed, moteur);
	delay(500);
	moteur.stop(3);
	rotation(1, 1, rotationTime, moteur);
	moteurstart(rotationSpeed, moteur);
	delay(500);
	moteurback(rotationSpeed, moteur);
	delay(1000);
	moteurstart(movementSpeed, moteur);
	delay(500);
	moteur.stop(3);
	rotation(1, 2, rotationTime, moteur);
	moteurstart(movementSpeed, moteur);
	delay(2000);
	moteur.stop(3);
}

void bowling(){
	departure():
	strike();
}