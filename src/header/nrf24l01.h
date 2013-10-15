#ifndef __NRF24L01_H__
#define __NRF24L01_H__
#include <mcu.h>

sbit CE     = P1^2;
sbit IRQ    = P1^3;

#define TX_ADDR_SIZE 3
#define RX_ADDR_SIZE 3
#define TX_PLOAD_SIZE 4
#define RX_PLOAD_SIZE 4


void nrf24l01_init(void);
void nrf24l01_set_ptx_mode(void);
void nrf24l01_set_prx_mode(void);
void nrf24l01_tx_packet();
void nrf24l01_rx_packet();
#endif