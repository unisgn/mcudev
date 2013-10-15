#ifndef __LED7SEG_H__
#define __LED7SEG_H__
#include <stc90c51.h>
#define LED7SEG P0

uchar code led7seg_char_code[10] = {
0x3f,		// "0"
0x06,
0x5b,
0x4f,
0x66,
0x6d,
0x7d,
0x07,
0x7f,
0x6f		// "9"
};

#endif