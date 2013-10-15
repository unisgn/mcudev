#include <stc90c51.h>
#include <intrins.h>
//static void uart_init(void)
//{
//	SCON = 0x50;
//	TMOD |= 0x20;
//	TH1 = 0xFD;		// xtal = 11059200Hz, baudrate = 9600bps;
//	TR1 = 1;
//}

void sys_delay_5us(uint8_t n)
{
	while(n--) {
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
	}
}
void sys_delay_1ms(uint8_t n)
{
	uint8_t i;
	while(n--)
		for(i = 0; i < 200; i++) {
			_nop_();
			_nop_();
			_nop_();
			_nop_();
			_nop_();
		}
		
}

void sys_delay_1s(uint8_t n)
{
	uint8_t i, j;
	while(n--) {
		for(i = 0; i < 250; i++)
			for(j = 0; j < 250; j++) {
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				_nop_();
			}
	}
}


/* void sys_init(void)
{
	uart_init();
} */

