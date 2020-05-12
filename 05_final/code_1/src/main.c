#include "8051.h"
#include "DAC0832_func.h"


void delay1ms(void)
{
    unsigned char a,b;
    for(b=142;b>0;b--)
        for(a=2;a>0;a--);
}


void main()
{
    uchar volte = 0x00;
    while (1)
    {
        DAC0832 = volte;
        volte++;
        delay1ms();
    }
    
}
