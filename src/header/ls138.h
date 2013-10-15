#ifndef __LS138_H__
#define __LS138_H__
#include <stc90c51.h>

sbit LS138A = P2^2;
sbit LS138B = P2^3;
sbit LS138C = P2^4;

void ls138_encode(uint8_t num);
uint8_t ls138_decode(void);
#endif