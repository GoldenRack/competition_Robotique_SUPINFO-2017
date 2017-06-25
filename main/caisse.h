void caisseDanse(int rotationTime, Moteur moteur){
	rotate(1, 1, rotationTime, moteur);
	rotate(2, 2, rotationTime, moteur);
	rotate(1, 1, rotationTime, moteur);
}

void caisse(int SonarTriggerAvant, int SonarEchoAvant, int rotationTime, Moteur moteur){
	while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) > 30){
		moteur.avancer(3, 128);
	}
	moteur.stop(3);

	rotate(1, 2, rotationTime, moteur);
	moteur.avancer(3, 128);
	delay(1000);
	moteur.reculer(3, 128);
	delay(1000);
	rotate(1, 1, rotationTime, moteur);
	while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant)< 200){
		moteur.reculer(3, 128);
	}
	moteur.stop(3);
	rotate(1, 1, rotationTime, moteur);
	motorstart(255, moteur);
}
