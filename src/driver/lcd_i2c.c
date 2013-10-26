#include <mcu.h>
#include <lcd_i2c.h>
#include <intrins.h>


void lcd_i2c_write_byte(byte dat)
{
    uint8_t _bit;
    for(_bit = 0; _bit < 8; _bit++) {
        if((dat << _bit) & 0x80)
            SET_SDA();
        else
            CLR_SDA();
        CLR_SCL();
        SET_SCL();
    }
    CLR_SCL();
}
