#include <stc90c51.h>
#include <speaker.h>

static void _delay()
{
	uint8_t n = 200;
	while(n--);
}

void sys_beep(void)
{
	uint16_t i = 300;
	while(i--) {
		SPK = ~SPK;
		_delay();
	}
}