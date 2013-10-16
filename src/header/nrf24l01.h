#ifndef __NRF24L01_H__
#define __NRF24L01_H__
#include <mcu.h>

#define MAX_RT  0x10
#define TX_DS   0x20
#define RX_DR   0x40

sbit CE     = P1^2;
sbit IRQ    = P1^3;

#define TX_ADDR_WIDTH 3
#define RX_ADDR_WIDTH 3
#define TX_PLOAD_WIDTH 32
#define RX_PLOAD_WIDTH 32

extern void nrf24l01_init(void);
extern byte nrf24l01_get_irq_status(void);
extern void nrf24l01_clear_irq(void);
extern void nrf24l01_set_ptx_mode(void);
extern void nrf24l01_set_prx_mode(uchar* rx_addr);
extern void nrf24l01_tx_packet(uchar* tx_addr, uchar* tx_buf);
extern void nrf24l01_rx_packet(uchar* rx_buf);
extern void nrf24l01_test(void);
#endif
