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
			distance = getSonarDistance(  SonarTriggerArriere, SonarEchoArriere);
			servoarm.write(90);
			while(distance<190)
				{

				distance = getSonarDistance(SonarTriggerArriere, SonarEchoArriere);
				moteur.Start(3,200);



			  
				 // statement
				}
				moteur.stop(3);
				servo2.write(0);
				moteurstart(255, moteur);

			

		}

	}
	else if (getSonarDistance(  SonarTriggerDroite, SonarEchoDroite)>lecheMur)
	{
		motor.reculer(3,200);
		delay(1000);
		motor.avancer(2, 200);
		delay(500);
		moteurstart(255, moteur);
		Ftrain(servoarm, SonarTriggerArriere, SonarEchoArriere, SonarEchoDroite, SonarTriggerDroite);

	}
}
