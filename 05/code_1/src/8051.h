#ifndef _H_8051
#define _H_8051

#ifdef __SDCC

#include "mcs51/8051.h"
#include "stdint.h"

#define bit __bit
#define sbit __sbit
#define sfr __sfr
#define sfr16 __sfr16
#define sfr32 __sfr32

#define data __data
#define idata __idata
#define pdata __pdata
#define xdata __xdata

#define code __code
#define at(x) __at(x)

#define interrupt(x) __interrupt(x)
#define interrupt_using(x, y) __interrupt(x) __using(y)
#define reentrant __reentrant
#define _nop_() __asm__("nop\n")

/**
 * pin define
*/
#define P00 P0_0
#define P01 P0_1
#define P02 P0_2
#define P03 P0_3
#define P04 P0_4
#define P05 P0_5
#define P06 P0_6
#define P07 P0_7

#define P10 P1_0
#define P11 P1_1
#define P12 P1_2
#define P13 P1_3
#define P14 P1_4
#define P15 P1_5
#define P16 P1_6
#define P17 P1_7

#define P20 P2_0
#define P21 P2_1
#define P22 P2_2
#define P23 P2_3
#define P24 P2_4
#define P25 P2_5
#define P26 P2_6
#define P27 P2_7

#define P30 P3_0
#define P31 P3_1
#define P32 P3_2
#define P33 P3_3
#define P34 P3_4
#define P35 P3_5
#define P36 P3_6
#define P37 P3_7

#else

#include "REG51.H"
#include "STDDEF.H"
#include "INTRINS.H"

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;

typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int32_t;

#ifdef data
#define at(x)
#define interrupt(x)
#define interrupt_using(x, y)
#define reentrant
#else
#define at(x) _at_ x
#define interrupt(x) interrupt x
#define interrupt_using(x, y) interrupt x using y
#endif

/**
 * Pin define
*/

#ifdef data
#define P0 1
#define P1 1
#define P2 1
#define P3 1
#endif

sbit P00 = P0 ^ 0;
sbit P01 = P0 ^ 1;
sbit P02 = P0 ^ 2;
sbit P03 = P0 ^ 3;
sbit P04 = P0 ^ 4;
sbit P05 = P0 ^ 5;
sbit P06 = P0 ^ 6;
sbit P07 = P0 ^ 7;

sbit P10 = P1 ^ 0;
sbit P11 = P1 ^ 1;
sbit P12 = P1 ^ 2;
sbit P13 = P1 ^ 3;
sbit P14 = P1 ^ 4;
sbit P15 = P1 ^ 5;
sbit P16 = P1 ^ 6;
sbit P17 = P1 ^ 7;

sbit P20 = P2 ^ 0;
sbit P21 = P2 ^ 1;
sbit P22 = P2 ^ 2;
sbit P23 = P2 ^ 3;
sbit P24 = P2 ^ 4;
sbit P25 = P2 ^ 5;
sbit P26 = P2 ^ 6;
sbit P27 = P2 ^ 7;

sbit P30 = P3 ^ 0;
sbit P31 = P3 ^ 1;
sbit P32 = P3 ^ 2;
sbit P33 = P3 ^ 3;
sbit P34 = P3 ^ 4;
sbit P35 = P3 ^ 5;
sbit P36 = P3 ^ 6;
sbit P37 = P3 ^ 7;

#endif

#define EXT0_VECTOR 0  /* 0x03 external interrupt 0 */
#define TIM0_VECTOR 1  /* 0x0b timer 0 */
#define EXT1_VECTOR 2  /* 0x13 external interrupt 1 */
#define TIM1_VECTOR 3  /* 0x1b timer 1 */
#define UART0_VECTOR 4 /* 0x23 serial port 0 */

#endif