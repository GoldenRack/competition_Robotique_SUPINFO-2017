#include <Motor.h>
#include "motor.h"

void caisseDanse(){
	motor.reculer(1, rotationSpeed);
	delay(rotationTime/2);
	motor.stop(1);
	motor.reculer(2, rotationSpeed);
	delay(rotationTime);
	motor.stop(2);
	motor.reculer(1, rotationSpeed);
	delay(rotationTime);
	motor.stop(1);
	motor.reculer(2, rotationSpeed);
	delay(rotationTime+rotationTime/2);
}

void moveForward(){
	motorstart(movementSpeed, motor);
	delay(1200);
	motor.stop(2);
	delay(rotationTime/2);
	motor.stop(1);
	motor.avancer(2, movementSpeed);
	delay(rotationTime/2);
	motor.avancer(1, movementSpeed);
}

void caisse(){
	bool inFront = false;
	rotate(1, 1, rotationTime, motor);
	motorstart(movementSpeed, motor);
	while (not inFront){
		if(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) <= 50){
			motor.stop(3);
			rotate(1, 2, rotationTime, motor);
		}
	}
	motorstart(movementSpeed, motor);
	delay(1300);
	motor.stop(3);
	delay(300);
	caisseDanse();
	delay(300);
	moveForward();
}