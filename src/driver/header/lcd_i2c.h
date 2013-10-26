#ifndef __SOFT_I2C_H__
#define __SOFT_I2C_H__
#include <mcu.h>

sbit SCL = P2^6;
sbit SDA = P2^7;

#define SET_SCL() do { SCL = 1; } while(0)
#define CLR_SCL() do { SCL = 0; } while(0)
#define SET_SDA() do { SDA = 1; } while(0)
#define CLR_SDA() do { SDA = 0; } while(0)

void lcd_i2c_write_byte(byte dat);
#endif