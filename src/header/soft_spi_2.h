#ifndef __SOFT_SPI_2_H__
#define __SOFT_SPI_2_H__
#include <mcu.h>

sbit CSN_2    = P0^4;
sbit SCK_2    = P0^5;
sbit MISO_2   = P0^6;
sbit MOSI_2   = P0^7;
//#define SET_CE()    do { CE = 1; } while(0)
//#define CLR_CE()    do { CE = 0; } while(0)
//#define SET_CSN()   do { CSN = 1; } while(0)
//#define CLR_CSN()   do { CSN = 0; } while(0)
//#define SET_SCK()   do { SCK = 1; } while(0)
//#define CLR_SCK()   do { SCK = 0; } while(0)
//#define SET_MISO()  do { MISO = 1; } while(0)
//#define CLR_MISO()  do { MISO = 0; } while(0)
//#define SET_MOSI()  do { MOSI = 1; } while(0)
//#define CLR_MOSI()  do { MOSI = 0; } while(0)

byte soft_spi_2_rw(byte dat);

#endif