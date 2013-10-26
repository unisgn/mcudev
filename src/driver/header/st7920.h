#ifndef __ST7920_H__
#define __ST7920_H__
#include <mcu.h>
#include <soft_i2c.h>

sbit RST = P0^1;
sbit RS = P2^5;

#define SET_WRITE_MODE() do { RS = 1; } while(0)
#define SET_READ_MODE() do { RS = 0; } while(0)
#define SET_CMD_MODE() do { CS = 1; } while(0)
#define SET_DAT_MODE() do { CS = 0; } while(0)

void st7920_wcmd(uint8_t cmd);
void st7920_wdat(uint8_t dat);
#endif
