#ifndef __NRF24L01_H__
#define __NRF24L01_H__
#include <mcu.h>

sbit CE     = P1^2;
sbit IRQ    = P1^3;

#define TX_ADDR_SIZE 3
#define RX_ADDR_SIZE 3
#define TX_PLOAD_SIZE 4
#define RX_PLOAD_SIZE 4

extern uchar tx_addr[TX_ADDR_SIZE];
extern uchar rx_addr[RX_ADDR_SIZE];
extern uchar tx_buf[TX_PLOAD_SIZE];
extern uchar rx_buf[RX_PLOAD_SIZE];

extern void nrf24l01_init(void);
extern void nrf24l01_set_ptx_mode(void);
extern void nrf24l01_set_prx_mode(void);
extern void nrf24l01_tx_packet();
extern void nrf24l01_rx_packet();
#endif
