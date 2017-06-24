void Ftrain(Servo servoarm, int SonarTriggerArriere, int SonarEchoArriere, int SonarEchoDroite, int SonarTriggerDroite, int controle, Moteur moteur)

{
	int lecheMur = 100;

	if (getSonarDistance(SonarTriggerDroite, SonarEchoDroite)<lecheMur)

	{
		unsigned char color ;
		float distance ;
		color = getcolor(controle);
		if  (color = 3)/// couleur gris train fantom
		{	
			moteur.stop(3);
			//déploiement bras
			distance = getSonarDistance( SonarTriggerArriere, SonarEchoArriere);
			servoarm.write(90);
			while(distance<190)
				{

				distance = getSonarDistance(SonarTriggerArriere, SonarEchoArriere);
				motorstart(255, moteur);



			  
				 // statement
				}
				moteur.stop(3);
				servoarm.write(0);
				motorstart(255, moteur);

			

		}

	}
	else if (getSonarDistance(  SonarTriggerDroite, SonarEchoDroite)>lecheMur)
	{
		moteur.reculer(3,200);
		delay(1000);
		moteur.avancer(2, 200);
		delay(500);
		motorstart(255, moteur);
		Ftrain(servoarm, SonarTriggerArriere, SonarEchoArriere, SonarEchoDroite, SonarTriggerDroite, controle, moteur);

	}
}
