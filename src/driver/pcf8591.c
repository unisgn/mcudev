/**
 * @file pcf8591.c
 * @author
 * @date
 * @version
 * @brief 8-bit ADC PCF8591 driver, I2C commucation protocol, use soft_i2c
 * simulation driver.
 */
#include <pcf8591.h>
#include <soft_i2c.h>

/**
 * @function pcf8591_read_analog
 * @param ch, the given channel number of device
 * @return the 8-bit analog value
 * @brief read the analog value of a given channel ch
 */
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
