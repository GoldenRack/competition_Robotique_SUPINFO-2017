//turn est le nombre de quart de tour à faire et roation est soit 1 ou soit 2 (1 pour tourner en antihoraire, 2 pour tourner en horaire). 1 si inéfrieur à 1 et 2 si supérieur à 2.
void rotate(int turn, int rotation, int rotationTime, Moteur moteur){
  int firstWheel, secondWheel, i;
  if (rotation <= 1){
    firstWheel = 1;
    secondWheel = 2;
  } else {
    firstWheel = 2;
    secondWheel = 1;
  }
  for(i = 0 ; i < turn ; i++){
    moteur.avancer(firstWheel, 255);
    moteur.reculer(secondWheel, 255);
    delay(rotationTime);
    moteur.stop(3);
  }
}

void moteurstart(Moteur moteur){
  for (int i = 0; i < 256; ++i)
  {
    moteur.avancer(3,i);
    delay(10);
  }
}
