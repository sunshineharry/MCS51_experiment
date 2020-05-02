#include "reg51.h"
#include "DAC0832.H"
#include "ADC0808.H"
#define uchar unsigned char


void delay(uchar time)
{
    unsigned char a;
    for(a=time;a>0;a--);
}


void main()
{
    uchar volte = 0x00;
    while (1)
    {
        DAC0832 = volte;
        volte++;
        delay(ADC());
    }
}