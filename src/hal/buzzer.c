/* 
 * @file speaker.c
 * @desc: user buzzer to provide a system wide function: sys_beep, 
 */
#include <mcu.h>
#include <buzzer.h>
/* 
 * @function: sys_beep 
 */
void sys_beep(void)
{
    // bigger i makes beep last longer;
    uint16_t i = 300;
    while(i--) {
        BUZZER = ~BUZZER;
        //the delay determines the freq of pulse and so as to determines the
                // magnitude of the beep.
        sys_delay_5us(40);
    }
}
