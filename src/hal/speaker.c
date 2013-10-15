#include <stc90c51.h>
#include <speaker.h>

void sys_beep(void)
{
	uint16_t i = 300;
	while(i--) {
		SPK = ~SPK;
		sys_delay_5us(40);
	}
}