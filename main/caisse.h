void caisseDanse(int rotationTime, Moteur moteur){
	rotate(1, 1, rotationTime, moteur);
	rotate(2, 2, rotationTime, moteur);
	rotate(1, 1, rotationTime, moteur);
}

void caisse(int SonarTriggerAvant, int SonarEchoAvant, int rotationTime, Moteur moteur, Servo servoarm){
	while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) > 50){
		moteur.avancer(3, 128);
   delayMicroseconds(10);
	}
 delay(1000);
	moteur.stop(3);
  servoarm.write(180);
  delay(1000);
  servoarm.write(0);
  delay(1000);
  while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) < 220){
    moteur.reculer(3, 128);
   delayMicroseconds(10);
  }
	rotate(1, 1, rotationTime, moteur);
	motorstart(255, moteur);
}
