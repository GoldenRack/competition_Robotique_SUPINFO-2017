void maze(){
  moteurstart(movementSpeed, moteur);
  while(getSonarDistance(SonarTriggerAvant, SonarEchoAvant) >= 300){
    delayMicroseconds(10);
  }
  servoarm.write(90);
  moteur.stop(1);
  delay(rotationTime*2);
  servoarm.write(0);
  moteur.avancer(1, movementSpeed);
  moteur.stop(2);
  delay(rotationTime);
  moteur.avancer(2);
}
