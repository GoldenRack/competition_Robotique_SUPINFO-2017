void Ftrain(Servo servoarm, int SonarTriggerArriere, int SonarEchoArriere, int SonarEchoDroite, int SonarTriggerDroite, int SonarTriggerAllign, int SonarEchoAllign, int controle, Moteur moteur)

{
	
		int color ;
		color = getcolor(controle);
		if  (color = 3)/// couleur gris train fantom
		{	
			moteur.stop(3);
			//déploiement bras
			servoarm.write(140);
      ratrapage(SonarTriggerDroite, SonarEchoDroite,SonarTriggerAllign, SonarEchoAllign, moteur);
      motorstart(128, moteur);
      moteur.avancer(1, 145);
			while(getSonarDistance(SonarTriggerArriere, SonarEchoArriere)<100)
				{
          delayMicroseconds(10);
				  //motorstart(255, moteur);



			  
				 // statement
				}
				moteur.stop(3);
				servoarm.write(0);
				motorstart(100, moteur);

			

		

	}
	
}
