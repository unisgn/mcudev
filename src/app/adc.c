#include <mcu.h>
#include "adc.h"

uint8_t read_adc(uint8_t ch)
{
	uint8_t ret;
	soft_i2c_start();
	soft_i2c_write_byte(ADC_WRITE);
	if(soft_i2c_nack)
		return 0;
		
	soft_i2c_write_byte(ADC_CH_BASE | ch);
	if(soft_i2c_nack)
		return 0;
		
	soft_i2c_start();
	soft_i2c_write_byte(ADC_READ);
	if(soft_i2c_nack)
		return 0;
		
	ret = soft_i2c_read_byte();
	soft_i2c_write_nack();
	soft_i2c_stop();
	
	return ret;
}