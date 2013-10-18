#include <ls138.h>
void ls138_encode(uint8_t num)
{
    if(num < 8) {
        LS138A = (num & (1 << 0)) ? 1 : 0;
        LS138B = (num & (1 << 1)) ? 1 : 0;
        LS138C = (num & (1 << 2)) ? 1 : 0;
    }
}

// uint8_t ls138_decode(void)
// {
    // return ((uint8_t)LS138A + ((uint8_t)LS138B) << 1 + ((uint8_t)LS138C) << 2);
// }
