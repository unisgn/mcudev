#ifndef __SPEAKER_H__
#define __SPEAKER_H__
#include <reg52.h>

sbit SPK = P1^2;

void sys_beep(void);
#endif