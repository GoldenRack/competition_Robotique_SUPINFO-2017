#include <Wire.h>
#include <Adafruit_TCS34725.h>

int getcolor(uint16_t clear *clear, uint16_t rouge *rouge, uint16_t vert *vert, uint16_t bleu *bleu,tcs)
{
	tcs.setInterrupt(false);      

    delay(60);   
  
    tcs.getRawData(&rouge, &vert, &bleu, &clear);

    tcs.setInterrupt(true);

    if ((268 <= clear <= 277) && (186 <= rouge <= 196) && (84 <= vert <= 94) && (84 <= bleu <= 94))
    {
    	return 1;
    }
    else if((500 <= clear <= 510) && (184 <= rouge <= 194) && (199 <= vert <= 209) && (174 <= bleu <= 184))
    {      
      return 2;  
    } 
    else if((503 <= clear <= 513) && (246 <= rouge <= 256) && (180 <= vert <= 190) && (161 <= bleu <= 171))
    {      
      return 3;  
    }
    else if((429 <= clear <= 439) && (145 <= rouge <= 155) && (141 <= vert <= 151) && (156 <= bleu <= 166))
    {      
      return 4;  
    }
    else if((956 <= clear <= 966) && (470 <= rouge <= 480) && (359 <= vert <= 369) && (196 <= bleu <= 206))
    {      
      return 5;  
    }
}
