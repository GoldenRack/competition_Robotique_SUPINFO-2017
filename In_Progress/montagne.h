void montagne(int control, Moteur moteur)

while(1){
	delay(100);
	if(getcolor(control) == 4)
	{
		continue;
	}
	else
	{
		break;
	}

}

rotate(1, 1, 18000,moteur)
delay(10);
motorstart(128,moteur)
while(1){
	delay(100);
	if(getcolor(control) != 4)
	{
		continue;
	}
	else
	{
		break;
	}    
}
delay(4500)
rotate(1, 1, 18000,moteur)
delay(10);
motorstart(128,moteur)
