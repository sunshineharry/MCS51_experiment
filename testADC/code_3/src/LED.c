#include "LED.h"

void LED_show(uchar LED_number,uchar num)
{
    uchar tmp = 0;
    tmp = LED_number<<5;
    P2 = tmp;
    P1 = num_encode[num];
}