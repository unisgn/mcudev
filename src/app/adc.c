#include <pcf8591.h>
#include "main.h"

#define SAMPLING_SIZE 3

byte adc_read_analog(uint8_t channel)
{
    uint8_t i = (1 << SAMPLING_SIZE);
    uint16_t sample_dat_sum = 0;
    while(i--)
        sample_dat_sum += pcf8591_read_analog(channel);
    return (byte)(sample_dat_sum >> SAMPLING_SIZE);
}