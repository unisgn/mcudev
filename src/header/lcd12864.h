#ifndef __LCD12864_H__
#define __LCD12864_H__
#include <reg51.h>
#include <types.h>

// lcd full width char
#define LCD_CHAR_FWIDTH 16
// lcd half width char
#define LCD_CHAR_HWIDTH (LCD_CHAR_FWIDTH >> 1)

sbit CS = P0^0;
sbit RST = P0^1;
sbit RS = P2^5;


#define SET_RST() do { RST = 1; } while(0)
#define CLR_RST() do { RST = 0; } while(0)
#define SET_CS() do { CS = 1; } while(0)
#define CLR_CS() do { CS = 0; } while(0)
#define SET_CMD_MODE() do { RS = 0; } while(0)
#define SET_DAT_MODE() do { RS = 1; } while(0)
/* initialize the lcd */
void lcd_init(void);
/* clear full screen */
void lcd_clr_screen(void);
/* display string start at (X, Y), with specified char width */
void lcd_disp_char(uint8_t X, uint8_t Y, uint8_t _size, uchar* strptr);
#endif
