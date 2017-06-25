void glass(){
	while(getSonarDistance(SonarTriggerArriere, SonarEchoArriere) <= 650){
		delayMicroseconds(10);
	}
	rotate(1, 1, rotateSpeed, moteur);
	while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) >= 200){
		delayMicroseconds(10);
	}
	//lève le capteur RGB
	delay(400);
	//Fais un flash
	int i;
	for(i = 0 ; i < 10 ; i++){
		servoarm.write(180);
		delay(200);
		servoarm.write(0);
		delay(200);
	}
	rotate(1, 2, rotateSpeed, moteur);
}