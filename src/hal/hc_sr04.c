#include <hc_sr04.h>
#include <mcu.h>
static void trig_signal(void)
{
    TRIG = 1;
    sys_delay_5us(3);
    TRIG = 0;
}

uint16_t hc_sr04_measure_distance(void)
{

}
