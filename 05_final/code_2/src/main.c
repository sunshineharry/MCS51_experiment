#include "8051.h"
#include "LED_func.h"
#include "ADC_func.h"
#include "interrupt_func.h"




void main()
{
    static uchar num = 0;
    EX1_init();
    while(1)
    {
        
        ADC_choose_INO();   // 选择ADC的INO 作为模拟量输入
                            // 使用Y7控制，地址 E000H
        while (IE1 != 1);   // 当未产生中断，即未转换完成是程序等待
        num = ADC_INO;      // 保存转换出的数据
        LED_show(1,num/100);
        LED_show(2,(num%100)/10);
        LED_show(3,num%10);
    }
}