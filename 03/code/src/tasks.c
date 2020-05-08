#include "8051.h"
#include "interrupt_func.h"
#define uchar unsigned char
void update(void);

uchar ctrl_led  = 0xFE;

// 当按键按下两次后，计数器 TIM_1 产生中断
void press_twice() interrupt(TIM1_VECTOR)     
{
    TIM_0_continue();               // 打开定时器 TIM_0
}


// 当定时器 TIM_0 产生中断，即50ms 时间到
uchar i = 0;
void shine_led() interrupt(TIM0_VECTOR)        
{
    TIM_0_continue();               // 定时器 TIM_0 手动重装
    i++;
    if(i==20)                       // i=20时，即 1s 定时时间到
    {
        i = 0;                      // 清空标志位
        update();                   // 更新 LED 灯及其他逻辑
    }
}

void update(void)
{
    P1 = ctrl_led;                  // 点亮 LED
    if (ctrl_led == 0xFF)           // 当一个循环结束后
    {
        ctrl_led = 0xFE;            // 恢复初值
        TIM_0_pause();              // 关闭定时器 TIM_0
        TIM_1_rrestart();           // 重装计数器
    }  
    else
    {
        ctrl_led = ctrl_led << 1;
        ctrl_led = ctrl_led | 0x01; // 产生下个时刻 LED 的控制信号
    } 
}