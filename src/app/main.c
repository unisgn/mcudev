#include <mcu.h>
#include "main.h"

void main(void)
{
    while(1) {
        display_number(adc_read_analog(2));
    }
}