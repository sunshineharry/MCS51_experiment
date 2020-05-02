#include "8051.h"
#define uchar unsigned char
#define start P30
#define EOC P31
#define OE P32

void delay5ms(void)
{
    unsigned char a,b;
    for(b=19;b>0;b--)
        for(a=130;a>0;a--);
}


uchar adc()
{
    uchar val = 0;
    start = 0;
    start = 1;
    delay5ms();
    start = 0;
    while (EOC != 1);
    OE = 1;
    val = P1;
    return val; 
}


void main()
{
    uchar v = 0;
    while (1)
    {
        v = adc();
    }
    
}