/**
 * @file buzzer.c
 * @author
 * @date Oct 20, 2013
 * @version 0.1
 * @brief use buzzer to provide a system wide function: sys_beep
 */
#include <mcu.h>
#include <buzzer.h>

/**
 * @function sys_beep
 * @param none
 * @return none
 * @brief drive the buzzer with 2500Hz 1/2 duty pulse,
 * last for about 60ms
 */
void sys_beep(void)
{
    uint16_t count = 300;    // bigger count makes beep last longer;
    while(count--) {
        BUZZER = ~BUZZER;
        sys_delay_5us(40);
    }
}
