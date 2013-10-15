#ifndef __PCF8591_H__
#define __PCF8591_H__
#include <mcu.h>
#define I2C_WRITE 	    0x90
#define I2C_READ	    0x91
#define CTRL_BASE       0x40

byte pcf8591_read_analog(uint8_t ch);

#endif