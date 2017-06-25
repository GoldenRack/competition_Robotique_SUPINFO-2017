int getcolor(int control,int rougeM,int vertM,int bleuM,int clearM)
{
	Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

	uint16_t clear, rouge, vert, bleu;

	digitalWrite(control, LOW);      

    delay(60);   
  
    tcs.getRawData(&rouge, &vert, &bleu, &clear);

    

    if ((93 <= int(clear) <= 103) && (79 <= int(rouge) <= 89) && (45 <= int(vert) <= 55) && (50 <= int(bleu) <= 65))
    {
    	return 1;
    }
    else if((99 <= int(clear) <= 109) && (47 <= int(rouge) <= 57) && (50 <= int(vert) <= 60) && (48 <= int(bleu) <= 58))
    {      
      return 2;  
    } 
    else if((150 <= int(clear) <= 160) && (89 <= int(rouge) <= 99) && (68 <= int(vert) <= 78) && (68 <= int(bleu) <= 78))
    {      
      return 3;  
    }
    else if((clearM - 5 <= int(clear) <= clearM + 5) && (rougeM -5 <= int(rouge) <= rougeM +5) && (vertM -5 <= int(vert) <= vertM +5) && (bleuM - 5 <= int(bleu) <= bleuM +5))
    {      
      return 4;  
    }
    else if((200 <= int(clear) <= 210) && (112 <= int(rouge) <= 122) && (85 <= int(vert) <= 95) && (60 <= int(bleu) <= 70))
    {      
      return 5;  
    }
    else if((185 <= int(clear) <= 195) && (101 <= int(rouge) <= 111) && (87 <= int(vert) <= 97) && (64 <= int(bleu) <= 74))
    {      
      return 6;  
    }
}

void peur(int control )
{
	digitalWrite(control, LOW);      
    delay(100);  
  
  

   digitalWrite(control, HIGH); 
   delay(100);
}

void photoQueen(int control)
{
	digitalWrite(control, LOW);      

  delay(1000);   
  
  

  digitalWrite(control, HIGH);

  delay(10);

  digitalWrite(control, LOW);

  delay(100);

  digitalWrite(control, HIGH);

  delay(10);
}

int colorMontagne(int control)
{
  Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

  uint16_t clear, rouge, vert, bleu;

  digitalWrite(control, LOW);      

  delay(60);   
  
  tcs.getRawData(&rouge, &vert, &bleu, &clear);

  int rougeM, vertM, bleuM, clearM;

  rougeM = int rouge;
  vertM = int vert;
  bleuM = int bleu;
  clearM = int clear;

  return rougeM, vertM, bleuM, clearM;

}
