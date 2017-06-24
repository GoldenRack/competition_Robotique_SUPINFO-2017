void Ftrain(Servo servoarm)
{	
	unsigned char color ;
	float distance ;
	color = getcolor();
	if  (color = 3)/// couleur gris train fantom
	{	
		moteur.stop(3);
		//déploiement bras
		distance = getSonarDistance(  SonarTriggerArriere, SonarEchoArriere);
		servoarm.write(90);
		while(distance<190)
			{

			distance = getSonarDistance(SonarTriggerArriere, SonarEchoArriere)
			moteur.avancer(3,200)



		  
			 // statement
			}
			moteur.stop(3);
			servo2.write(0);
			moteur.avancer(3,200)

		

	}












