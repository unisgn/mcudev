#ifndef __NRF24L01_2_H__
#define __NRF24L01_2_H__
#include <mcu.h>


sbit CE_2     = P0^2;
sbit IRQ_2    = P0^3;

#define TX_ADDR_WIDTH 3
#define RX_ADDR_WIDTH 3
#define TX_PLOAD_WIDTH 32
#define RX_PLOAD_WIDTH 32

extern void nrf24l01_2_init(void);
extern byte nrf24l01_2_get_irq_status(void);
extern void nrf24l01_2_clear_irq(void);
extern void nrf24l01_2_set_ptx_mode(void);
extern void nrf24l01_2_set_prx_mode(uchar* rx_addr);
extern void nrf24l01_2_tx_packet(uchar* tx_addr, uchar* tx_buf);
extern void nrf24l01_2_rx_packet(uchar* rx_buf);
#endif
