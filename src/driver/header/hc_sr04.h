#ifndef __HC_SR04_H__
#define __HC_SR04_H__
#include <mcu.h>

sbit TRIG = P1^1
sbit ECHO = P1^2

uint16_t measure_distance(void);

#endif