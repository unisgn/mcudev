#ifndef __ADC_H__
#define __ADC_H__
#include <mcu.h>
#include <soft_i2c.h>
#define ADC_WRITE 	0x90
#define ADC_READ	0x91
#define ADC_CH_BASE	0x40

uint8_t read_adc(uint8_t ch);

#endif