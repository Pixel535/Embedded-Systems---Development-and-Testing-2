#include <REGX52.H>

unsigned char code decimal[] = {0xFF, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16};

void main(void)
{
	unsigned char granica = 6;
	unsigned char zmiennaAA = 0;
	unsigned char czy_SW1_zmienione = 0;
	while(1)
	{
		if(P3 == 0xFF && czy_SW1_zmienione == 1)
		{
			zmiennaAA = zmiennaAA + 1;
			czy_SW1_zmienione = 0;
		}
		else if(P3 == 0xFB)
		{
			czy_SW1_zmienione = 1;
		}
		if(zmiennaAA < granica)
		{
			if(zmiennaAA % 2 != 0 || zmiennaAA == 0) P2 = decimal[zmiennaAA];
		}
		else zmiennaAA = 0;
	}
	
}