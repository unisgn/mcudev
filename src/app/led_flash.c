#include <types.h>
#include <intrins.h>    
void led_flash(void)
{
    uint8_t led = 0xFE;
    while(1) {
        LED = led;
        sys_delay_1s(1);
        led = _crol_(led , 1);
    }
}