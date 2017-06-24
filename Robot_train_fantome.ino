void Ftrain(Servo servoar,SonarTriggerArriere,SonarEchoArriere,SonarEchoDroite,SonarTriggerDroite,clear,rouge,bleu,tcs,controle)

{
	int lecheMur = 100

	if (getSonarDistance(  SonarTriggerDroite, SonarEchoDroite)<lecheMur)

		{
		unsigned char color ;
		float distance ;
		color = getcolor(clear,rouge,bleu,tcs,controle);
		if  (color = 3)/// couleur gris train fantom
		{	
			moteur.stop(3);
			//déploiement bras
			distance = getSonarDistance(  SonarTriggerArriere, SonarEchoArriere);
			servoarm.write(90);
			while(distance<190)
				{

				distance = getSonarDistance(SonarTriggerArriere, SonarEchoArriere)
				moteur.Start(3,200)



			  
				 // statement
				}
				moteur.stop(3);
				servo2.write(0);
				moteur.Start(3,200)

			

		}
		else:
			moteur.avancer(3,200)

		}
		else if (getSonarDistance(  SonarTriggerDroite, SonarEchoDroite)>lecheMur)
		{
			motor.reculer(3,200)
			delay(200) 
			motor.avancer(2.200)
			Ftrain(Servo servoar,SonarTriggerArriere,SonarEchoArriere,SonarEchoDroite,SonarTriggerDroite)

		}











