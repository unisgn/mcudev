#ifndef __LCD12864_H__
#define __LCD12864_H__
#include <stc90c51.h>
#define LCD_CHAR_FWIDTH 16
#define LCD_CHAR_HWIDTH (LCD_CHAR_FWIDTH >> 1)



#define SET_RST() do { RST = 1; } while(0)
#define CLR_RST() do { RST = 0; } while(0)
#define SET_CS() do { CS = 1; } while(0)
#define CLR_CS() do { CS = 0; } while(0)
#define SET_CMD_MODE() do { RS = 0; } while(0)
#define SET_DAT_MODE() do { RS = 1; } while(0)

void lcd_init(void);
void lcd_clr_screen(void);
void lcd_disp_char(uint8_t X, uint8_t Y, uint8_t _size, uchar* strptr);
#endif