#include <REGX52.H>

unsigned char code prawo[] = {0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0xA7, 0xFF, 0xEF, 0xBF, 0x86};
unsigned char code lewo[] = {0xC0, 0xCF};

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
	unsigned char granica = 11;
	unsigned char zmiennaAA = 0;
	while(1)
	{
		P3 = prawo[zmiennaAA];
		if(zmiennaAA >= 10) P1 = lewo[1];
		else P1 = lewo[0];
		Delay();
		if(P3 == 0x80)
		{
			if(zmiennaAA < granica) zmiennaAA = zmiennaAA + 1;
			else zmiennaAA = 0;
		}
		else if(P3 == 0x00)
		{
			if(zmiennaAA > 0) zmiennaAA = zmiennaAA - 1;
			else zmiennaAA = granica;
		}
	}	
}