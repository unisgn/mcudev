#include "led7seg_ls138.h"
#include <ls138.h>
#include <led7seg.h>

static void display_digit(uint8_t digit, uint8_t number)
{
	ls138_encode(7 - digit);
	LED7SEG = led7seg_char_code[number];
	sys_delay_50us(1);
}

static uint32_t power(uint8_t number, uint8_t pow)
{
	return (!pow) ? 1 : number * power(number, pow - 1);
}
static uint8_t get_digit_of_number(uint32_t number, uint8_t digit)
{
	return (uint8_t)((number%power(10, digit + 1))/power(10, digit));
}
void display_number(uint32_t number)
{
	uint8_t i;
	for(i = 0; i < 8; i++) 
		display_digit(i, get_digit_of_number(number, i));
}
