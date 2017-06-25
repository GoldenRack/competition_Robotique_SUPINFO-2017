jardin(){
	moteurstart(movementSpeed, moteur);
	while(getSonarDistance(SonarTriggerArriere, SonarEchoArriere) <= 400){
		delayMicroseconds(10);
	}
	moteur.stop(2);
	delay(rotationTime);
	moteurstart(movementSpeed, moteur);
	while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) >= 800){
		delayMicroseconds(10);
	}
	moteur.stop(1);
	delay(rotationTime);
	moteurstart(movementSpeed, moteur);
	while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) >= 400){
		delayMicroseconds(10);
	}
	moteur.stop(1);
	delay(rotationTime/2);
	moteur.stop(3);
	delay(3000);
	moteur.reculer(2, movementSpeed);
	delay(rotationTime/2);
	moteur.stop(2);
}