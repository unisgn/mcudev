#ifndef __MCU_H__
#define __MCU_H__
#include <reg51.h>
#include <types.h>

void uart_init(void);
void sys_delay_5us(uint8_t n);
void sys_delay_1ms(uint8_t n);
void sys_delay_1s(uint8_t n);

#endif
