/**
 * @file soft_spi.c
 * @author
 * @date
 * @version
 * @brief soft spi simulation driver
 */
#include <soft_spi.h>

/**
 * @function soft_spi_rw
 * @brief write a byte of data to slave device, meanwhile read a byte from slave
 * device.
 */
byte soft_spi_rw(byte dat)
{
    uchar _bit = 8;
    while(_bit--) {
        MOSI = dat & 0x80;
        dat <<= 1;
        SCK = 1;
        dat |= MISO;
        SCK = 0;
    }
    return dat;
}
