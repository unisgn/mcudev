#include <mcu.h>
#include <soft_i2c.h>

bool soft_i2c_nack;

void soft_i2c_start(void)
{
    SET_SCL();
    SET_SDA();
    sys_delay_5us(1);
    CLR_SDA();
    sys_delay_5us(1);
    CLR_SCL();
}

void soft_i2c_stop(void)
{
    SET_SCL();
    CLR_SDA();
    sys_delay_5us(1);
    SET_SDA();
    sys_delay_5us(1);
}

void soft_i2c_write_byte(byte dat)
{
    uint8_t _bit;
    for(_bit = 0; _bit < 8; _bit++) {
        if((dat << _bit) & 0x80)
            SET_SDA();
        else
            CLR_SDA();
        SET_SCL();
        sys_delay_5us(1);
        CLR_SCL();
    }
    sys_delay_5us(1);
    SET_SDA();
    sys_delay_5us(1);
    SET_SCL();
    sys_delay_5us(1);
    soft_i2c_nack = (SDA == 1) ? 1 : 0;
    CLR_SCL();
}

byte soft_i2c_read_byte(void)
{
    uint8_t _bit;
    byte ret = 0;
    SET_SDA();
    for(_bit = 0; _bit < 8; _bit++) {
        CLR_SCL();
        sys_delay_5us(1);
        SET_SCL();
        ret <<= 1;
        if(SDA == 1)
            ret++;
    }
    CLR_SCL();
    return ret;
}

// void soft_i2c_write_ack(void)
// {
    // CLR_SDA();
    // SET_SCL();
    // sys_delay_5us(1);
    // CLR_SCL();
// }
void soft_i2c_write_nack(void)
{
    SET_SDA();
    SET_SCL();
    sys_delay_5us(1);
    CLR_SCL();
}