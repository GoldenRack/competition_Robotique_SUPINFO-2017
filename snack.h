void snack(){
	while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) >= 100){
		delayMicroseconds(10);
	}
	rotate(1, 2, rotateSpeed, moteur);
	while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) >= 100){
		delayMicroseconds(10);
	}
	rotate(1, 2, rotateSpeed, moteur);
	while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) >= 50){
		delayMicroseconds(10);
	}
	delay(500);
	motor.stop(3);
	delay(300);
	motorback(movementSpeed, moteur);
	while(getSonarDistance(SonarTriggerArriere, SonarEchoArriere) >= 700){
		delayMicroseconds(10);
	}
	rotate(2, 2, movementSpeed, moteur);
}
