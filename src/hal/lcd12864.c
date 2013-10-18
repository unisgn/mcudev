#include <mcu.h>
#include <lcd12864.h>
#include <lcd_i2c.h>
#include <intrins.h>



static void lcd_wcmd(byte cmd)
{
    CLR_CS();
    SET_CMD_MODE();
    lcd_i2c_write_byte(cmd);
    SET_CS();
}

static void lcd_wdat(byte dat)
{
    CLR_CS();
    SET_DAT_MODE();
    lcd_i2c_write_byte(dat);
    SET_CS();
}

static void lcd_fill_screen(uint8_t dat)
{
    uint8_t i, j;
    for(i = 0; i < 8; i++) {
        lcd_wcmd(0x40);
        lcd_wcmd(0xB0 + i);
        lcd_wcmd(0x10);
        lcd_wcmd(0x00);
        for(j = 0; j < 128; j++)
            lcd_wdat(dat);
    }
}

void lcd_init(void)
{
    SET_RST();
    sys_delay_1ms(20);
    CLR_RST();
    sys_delay_1ms(20);
    SET_RST();
    sys_delay_1ms(20);
    CLR_CS();

    lcd_wcmd(0xE2);          //Software Reset
    lcd_wcmd(0xA6);    
    lcd_wcmd(0xA3);          //Set Bias     0xA3 1/7bias,  0xA2 1/9 bias
    lcd_wcmd(0xA0);          //Segment Direction Select       bit0=0,normal ,=1,reverse
    lcd_wcmd(0xC8);          //Common Direction Select        bit3=0,normal ,=1,revese
    lcd_wcmd(0xA4);  
    lcd_wcmd(0xF8);  
    lcd_wcmd(0x00);  
    lcd_wcmd(0x23);          //Set internal rb/ra	0x24
    lcd_wcmd(0x81);          //Set Contrast     
    lcd_wcmd(0x19);          //0x19

    lcd_wcmd(0x2F);          //Power Control Set 
    lcd_wcmd(0x2F);    
    lcd_wcmd(0x2F);

    sys_delay_1ms(40);
    lcd_wcmd(0x40);
    lcd_wcmd(0xAF);

    lcd_clr_screen();
}

void lcd_clr_screen(void)
{
    // fill with 0xFF to clear white;
    lcd_fill_screen(0xFF);
    // fill with 0x00 to clear black;
    lcd_fill_screen(0x00);
}

void lcd_disp_char(uint8_t X, uint8_t Y, uint8_t _size, uchar* strptr)
{
    uint8_t i, j, n = 0;
    for(i = 0; i < (_size >> 3); i++) {
        lcd_wcmd(0xB0 + i + (_size >> 3) * Y);
        lcd_wcmd(0x10 + 7 - X);
        for(j = 0; j < _size; j++)
            lcd_wdat(strptr[n++]);
    }
}