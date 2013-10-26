#ifndef __BUZZER_H__
#define __BUZZER_H__
#include <mcu.h>

sbit BUZZER = P1^2;

void sys_beep(void);
#endif
