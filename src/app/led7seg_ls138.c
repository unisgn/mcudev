#include <mcu.h>
#include <ls138.h>
#include <led7seg.h>
#include "led7seg_ls138.h"

#define NUM_SYS_RADIX 10
#define LED_ARRAY_QTY 8

static void display_digit(uint8_t digit_index, uint8_t digit)
{
    if(digit < NUM_SYS_RADIX) {
        ls138_encode(LED_ARRAY_QTY - 1 - digit_index);
        LED7SEG_DISP(digit);
        sys_delay_5us(10);
    }
}

static uint32_t power(uint8_t number, uint8_t pow)
{
    return (uint32_t) (!pow) ? 1 : (uint32_t) (number * power(number, pow - 1));
}

static uint8_t get_digit(uint32_t number, uint8_t digit_index)
{
    return (uint8_t) ((number % power(NUM_SYS_RADIX, digit_index + 1)) / power(NUM_SYS_RADIX, digit_index));
}

void display_number(uint32_t number)
{
    uint8_t i;
    for(i = 0; i < LED_ARRAY_QTY; i++)
        display_digit(i, get_digit(number, i));

}
