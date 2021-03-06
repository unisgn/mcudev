#ifndef __LED7SEG_H__
#define __LED7SEG_H__
#include <mcu.h>
#define LED7SEG     P0

#define LED7SEG_CHAR_CODE_WIDTH     16

#define LED7SEG_DISP(char_code_index) do { LED7SEG = led7seg_char_code[char_code_index] ;} while(0)
/*
          A
        ____
    F  |    |  B
       |_G__|
    E  |    |  C
       |____| o  DP
          D
          
    SEG: A   B   C   D   E   F   G   DP
    BIT: 0   1   2   3   4   5   6   7
*/

extern uchar code led7seg_char_code[LED7SEG_CHAR_CODE_WIDTH] = {
0x3F,       // "0"
0x06,
0x5B,
0x4F,
0x66,
0x6D,
0x7D,
0x07,
0x7F,
0x6F,       // "9"
0x77,       // "A"
0x7C,       // "b"
0x39,       // "C"
0x5E,       // "d"
0x79,       // "E"
0x71,       // "F"
};

#endif
