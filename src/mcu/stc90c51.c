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
void sys_delay_50us(uchar n)
{
	uint8_t i = 50;
	while(n--)
		while(i--);
		
}
//void sys_delay_50ms(uint8_t n)
//{
//	uint8_t i = n, j = 250, k = 200;
//	while(i--)
//		while(j--)
//			while(k--);
//}

//void sys_init(void)
//{
//	uart_init();
//}
