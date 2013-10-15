#include <mcu.h>

char putchar(char c)
{
	SBUF = c;
	while(!TI);
	TI = 0;
	return c;
}
