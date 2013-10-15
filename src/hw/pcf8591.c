#include <pcf8591.h>
#include <soft_i2c.h>


byte pcf8591_read_analog(uint8_t ch)
{
	byte ret;
	soft_i2c_start();
	soft_i2c_write_byte(I2C_WRITE);
	if(soft_i2c_nack)
		return 0;
		
	soft_i2c_write_byte(CTRL_BASE | ch);
	if(soft_i2c_nack)
		return 0;
		
	soft_i2c_start();
	soft_i2c_write_byte(I2C_READ);
	if(soft_i2c_nack)
		return 0;
		
	ret = soft_i2c_read_byte();
	soft_i2c_write_nack();
	soft_i2c_stop();
	
	return ret;    
}