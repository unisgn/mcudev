#include <soft_spi_2.h>



byte soft_spi_2_rw(byte dat)
{
    uchar _bit = 0;
    while((_bit++) < 8) {
        MOSI_2 = dat & 0x80;
        dat <<= 1;
        SCK_2 = 1;
        dat |= MISO_2;
        SCK_2 = 0;
    }
    return dat;
}
