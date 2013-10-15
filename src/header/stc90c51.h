
#ifndef __STC90C51_H__
#define __STC90C51_H__
#include <reg51.h>
#include <types.h>

void sys_init(void);
void sys_delay_5us(uint8_t n);
void sys_delay_1ms(uint8_t n);
void sys_delay_1s(uint8_t n);

#endif