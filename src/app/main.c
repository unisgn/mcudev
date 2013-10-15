#include <stc90c51.h>
#include "lcd_disp.h"
#include "led7seg_ls138.h"
#include "adc.h"

void main(void)
{
	lcd_disp();
    while(1) {
		display_number(read_adc(0));
	}
}