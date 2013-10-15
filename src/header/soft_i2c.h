#ifndef __SOFT_I2C_H__
#define __SOFT_I2C_H__
#include <stc90c51.h>
extern bool soft_i2c_nack;


#define SET_SCL() do { SCL = 1; } while(0)
#define CLR_SCL() do { SCL = 0; } while(0)
#define SET_SDA() do { SDA = 1; } while(0)
#define CLR_SDA() do { SDA = 0; } while(0)

void soft_i2c_start(void);
void soft_i2c_stop(void);
void soft_i2c_write_byte(byte dat);
byte soft_i2c_read_byte(void);
void soft_i2c_write_ack(void);
void soft_i2c_write_nack(void);
#endif