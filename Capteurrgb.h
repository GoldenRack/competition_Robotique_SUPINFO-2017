#include <Wire.h>
#include <Adafruit_TCS34725.h>

int getcolor(int control)
{
	Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

	uint16_t clear, rouge, vert, bleu;

	digitalWrite(control, LOW);      

    delay(60);   
  
    tcs.getRawData(&rouge, &vert, &bleu, &clear);

    digitalWrite(control, HIGH);

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
    else if((147 <= int(clear) <= 157) && (80 <= int(rouge) <= 90) && (61 <= int(vert) <= 71) && (60 <= int(bleu) <= 70))
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
