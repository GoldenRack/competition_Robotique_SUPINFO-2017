void montagne(int control, Moteur moteur)

int rougeM, vertM, bleuM, clearM = colorMontagne(control);

while(1){
	delay(100);
	if(getcolor(control,rougeM, vertM, bleuM, clearM) == 4)
	{
		continue;
	}
	else
	{
		break;
	}

}

rotate(1, 1,0,< moteur)
delay(10);
motorstart(128,moteur)
while(1){
	delay(100);
	if(getcolor(control,rougeM, vertM, bleuM, clearM) != 4)
	{
		continue;
	}
	else
	{
		break;
	}    
}
delay(4500)
rotate(1, 1, 0,moteur)
delay(10);
motorstart(128,moteur)
