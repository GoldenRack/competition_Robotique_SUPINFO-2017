#include <Motor.h>
#include "motor.h"

void departure(){
	motorstart(movementSpeed, motor);
	while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) >= 200){
		delayMicroseconds(10);
	}
	motor.stop(2);
	motor.avancer(1, rotateSpeed);
	delay(rotationTime);
	motorstart(movementSpeed, motor);
}

void strike(){
	while (getSonarDistance(SonarTriggerArriere, SonarEchoArriere) <= 1400){
		delayMicroseconds(10);
	}
	moteurstart(rotationSpeed, motor);
	delay(2000);
	moteur.stop(3);
	moteurback(movementSpeed, moteur);
	while (getSonarDistance(SonarTriggerArriere, SonarEchoArriere) >= 1400){
		delayMicroseconds(10);
	}
	rotate(1, 1, rotationTime, moteur);
	moteurstart(rotationSpeed, moteur);
	while (getSonarDistance(SonarTriggerAvant, SonarEchoAvant) >= 100){
		delayMicroseconds(10);
	}
	moteurback(rotationSpeed, moteur);
	while (getSonarDistance(SonarTriggerArriere, SonarEchoArriere) >= 100){
		delayMicroseconds(10);
	}
	moteurstart(movementSpeed, moteur);
	while (getSonarDistance(SonarTriggerAvant, SonarEchoAvant) >= 150){
		delayMicroseconds(10);
	}
	moteur.stop(3);
	rotate(1, 2, rotationTime, moteur);
	moteurstart(movementSpeed, moteur);
	while (getSonarDistance(SonarTriggerAvant, SonarEchoAvant) >= 200){
		delayMicroseconds(10);
	}
	moteur.stop(3);
}

void bowling(){
	departure():
	strike();
}