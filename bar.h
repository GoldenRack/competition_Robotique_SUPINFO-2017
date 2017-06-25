void bar(){
	while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) >= 350){
		delayMicroseconds(10);
	}
	moteur.stop(3);
	delay(4000);
	servoarm.write(45);
	delay(200);
	servoarm.write(0);
	moteurstart(127, motor);
	while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) >= 100){
		delayMicroseconds(10);
		servoarm.write(45);
		delay(200);
		servoarm.write(0);
	}
	rotate(1, 1, rotateSpeed, motor);
	moteurstart(movementSpeed, motor);
}
