#include "8051.h"
#include "DAC0832_func.h"
#include "LED_func.h"
#include "ADC_func.h"
#include "interrupt_func.h"


void delayms(uchar time)
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=time;a>0;a--);
}


void main()
{
    uchar volte = 0x00;
    uchar time = 0;
    EX1_init();
    while (1)
    {
        ADC_choose_INO(); 
        //while (IE1 != 1);
        // 利用操作DAC延时
        DAC0832 = volte;
        volte++;
        // 延时完成
        time = ADC_INO; 
        delayms(time);
    }
    
}
