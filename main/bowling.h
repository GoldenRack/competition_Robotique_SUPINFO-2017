void strike(Moteur moteur, int rotationTime, int SonarTriggerAvant, int SonarTriggerArriere, int SonarEchoArriere, int SonarTriggerDroite, int SonarEchoDroite, int SonarEchoAvant){
	float mm;
	moteur.avancer(3, 128);
	do{
		mm = getSonarDistance(SonarTriggerAvant, SonarEchoAvant);
	}while(mm > 30);

	moteur.stop(3);
 
	rotate(1, 1, rotationTime, moteur);
 
	motorstart(128, moteur);

	while(getSonarDistance(SonarTriggerArriere, SonarEchoArriere) < 120){
		moteur.avancer(3, 128);
	}
	moteur.stop(3);
 
	while(getSonarDistance(SonarTriggerArriere, SonarEchoArriere) > 35){
		moteur.reculer(3, 128);
	}
	moteur.stop(3);
 

	rotate(1, 1, rotationTime, moteur);

	moteur.avancer(3, 128);
	delay(1000);

	while(getSonarDistance(SonarTriggerArriere, SonarEchoArriere) < 500){
		moteur.avancer(3, 128);
	}
	moteur.stop(3);
 

	rotate(1, 2, rotationTime, moteur);

	motorstart(128, moteur);

}
