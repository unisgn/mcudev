/**
 * @file mcu.c
 * @author
 * @date
 * @version
 * @brief setup mcu specific functions and basic system environment, provide
 * system wide interface.
 */
#include <mcu.h>
#include <intrins.h>


void uart_init(void)
{
    SCON = 0x50;
    TMOD |= 0x20;
    TH1 = 0xFD;		// xtal_freq = 11592000Hz, baudrate = 9600bps;
    TR1 = 1;
}


/**
 *
 * @function sys_init;
 * @brief initialize system, provide basic system running environment;
 * 
 */
/* void sys_init(void) */
/* { */
/*     uart_init(); */
/* } */

/**
 *
 * @function sys_delay_5us;
 * @brief sys_delay provides 3 diffrent level(also magnitude) of delay, which are approx 5us,
 * 1ms, and 1s, use the most approx one to your need;
 */
/* void sys_delay_5us(uint8_t n) */
/* { */
/*     while(n--) { */
/*         _nop_(); */
/*         _nop_(); */
/*         _nop_(); */
/*         _nop_(); */
/*         _nop_(); */
/*     } */
/* } */

/**
 *
 * @function sys_delay_1ms;
 * @brief sys_delay provides 3 diffrent level(also magnitude) of delay, which are approx 5us,
 * 1ms, and 1s, use the most approx one to your need;
 */
/* void sys_delay_1ms(uint8_t n) */
/* { */
/*     uint8_t i; */
/*     while(n--) */
/*         for(i = 0; i < 200; i++) { */
/*             _nop_(); */
/*             _nop_(); */
/*             _nop_(); */
/*             _nop_(); */
/*             _nop_(); */
/*         } */
/* } */

/**
 *
 * @function sys_delay_1s;
 * @brief sys_delay provides 3 diffrent level(also magnitude) of delay, which are approx 5us,
 * 1ms, and 1s, use the most approx one to your need;
 */
/* void sys_delay_1s(uint8_t n) */
/* { */
/*     uint8_t i, j; */
/*     while(n--) { */
/*         for(i = 0; i < 250; i++) */
/*             for(j = 0; j < 250; j++) { */
/*                 _nop_(); */
/*                 _nop_(); */
/*                 _nop_(); */
/*                 _nop_(); */
/*                 _nop_(); */
/*                 _nop_(); */
/*                 _nop_(); */
/*                 _nop_(); */
/*                 _nop_(); */
/*                 _nop_(); */
/*                 _nop_(); */
/*                 _nop_(); */
/*                 _nop_(); */
/*                 _nop_(); */
/*                 _nop_(); */
/*                 _nop_(); */
/*             } */
/*     } */
/* } */




