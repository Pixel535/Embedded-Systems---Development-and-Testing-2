#include <REGX52.H>

unsigned char code decimal[] = {0xFF, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06};

void Delay(void)
{
   unsigned char i;
   unsigned char j;
   for(i=0;i<150;i++)
   {
      for(j=0;j<200;j++)
      { ; }
   }
} 


void main(void)
{
	unsigned char granica = 6;
	unsigned char zmiennaAA = 0;
	while(1)
	{
		if(zmiennaAA % 2 != 0 || zmiennaAA == 0) {P2 = decimal[zmiennaAA]; Delay();};
		if(zmiennaAA < granica) zmiennaAA = zmiennaAA + 1;
		else zmiennaAA = 0;
	}
	
}