#include <soft_spi.h>

byte soft_spi_rw(byte dat)
{
    uchar _bit = 0;
    while((_bit++) < 8) {
        MOSI = dat & 0x80;
        dat <<= 1;
        SCK = 1;
        dat |= MISO;
        SCK = 0;
    }
    return dat;
}
