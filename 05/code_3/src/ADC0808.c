#include "REG51.H"
#define uchar unsigned char

void delay5ms(void)
{
    unsigned char a,b;
    for(b=19;b>0;b--)
        for(a=13;a>0;a--);
}

sbit start = P3^0;
sbit EOC = P3^1;
sbit OE = P3^2;
uchar ADC()
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
