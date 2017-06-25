sortie(){
	moteur.start(1, movementSpeed);
	delay(rotationTime);
	moteurstart(movementSpeed, moteur);
	while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) >= 150){
		delayMicroseconds(10);
	}
	rotate(10, 2, rotateSpeed, moteur);
	//lève la loupiotte et clignote avec
}