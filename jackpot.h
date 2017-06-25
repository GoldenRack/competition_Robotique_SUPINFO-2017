#include <Motor.h>
#include "motor.h"

void jackpot(){
	while(getSonarDistance(SonarTriggerArriere, SonarEchoArriere) <= 800){
		delayMicroseconds(10);
	}
	motor.stop(2);
	servoarm.write(180);
	motorstart(rotateSpeed, motor);
	delay(700);
	//lève le capteur RGB
	delay(200)
	//fais un flash
	delay(1000)
	//descends le capteur RGB
	rotate(8, 1, rotateSpeed, motor);
	motorback(movementSpeed, motor);
	while(getSonarDistance(SonarTriggerArriere, SonarEchoArriere) >= 100){
		delayMicroseconds(10);
	}
	motor.stop(3);
	rotate(1, 2, rotateSpeed, motor);
}