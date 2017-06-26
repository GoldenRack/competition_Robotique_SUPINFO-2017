void caisseDanse(int rotationTime, int SonarTriggerDroite, int SonarEchoDroite, Moteur moteur, int control){
	rotate(1, 1, rotationTime, moteur);
	rotate(2, 2, rotationTime, moteur);
	rotate(1, 1, rotationTime, moteur);
}

void caisse(int SonarTriggerAvant, int SonarEchoAvant, int SonarTriggerDroite, int SonarEchoDroite, int rotationTime, Moteur moteur, Servo servoarm, int control){
	while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) > 50){
		moteur.avancer(3, 128);
   delayMicroseconds(10);
	}
 delay(1000);
	moteur.stop(3);
  servoarm.write(180);
  delay(1000);
  servoarm.write(25);
  delay(1000);
  servoarm.write(180);
  delay(1000);
  servoarm.write(25);
  delay(1000);
  servoarm.write(180);
  delay(1000);
  servoarm.write(25);
  delay(1000);
  while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) < 220){
    moteur.reculer(3, 128);
   delayMicroseconds(10);
  }
	rotate(1, 1, rotationTime, moteur);
  delay(10);
  moteur.avancer(3,255);
  while(getcolor(control,0,0,0,0)==2){
    Serial.print("");
    }
  
}
