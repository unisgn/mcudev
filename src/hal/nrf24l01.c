/**
 * @file: nrf24l01.c
 * @author: yinlan
 * @date: Oct 20, 2013
 * @version: v0.1
 * @brief: driver for 2.4GHz wireless device NRF24l01
 */
#include <nrf24l01.h>
#include <soft_spi.h>
#include <nrf24l01_reg.h>

static byte nrf_read_reg(uint8_t reg)
{
    byte stat;
    CSN = 0;
    soft_spi_rw(reg);
    stat = soft_spi_rw(0);
    CSN = 1;
    return stat;
}

static byte nrf_write_reg(uint8_t reg, byte dat)
{
    byte stat;
    CSN = 0;
    stat = soft_spi_rw(reg);
    soft_spi_rw(dat);
    CSN = 1;
    
    return stat;
}

static byte nrf_read_buf(uint8_t reg, byte* bufPtr, uint8_t bufSize)
{
    byte stat;
    CSN = 0;
    stat = soft_spi_rw(reg);
    while(bufSize--)
        *bufPtr++ = soft_spi_rw(0);
    CSN = 1;
    return stat;
}

static byte nrf_write_buf(uint8_t reg, byte* bufPtr, uint8_t bufSize)
{
    byte stat;
    CSN = 0;
    stat = soft_spi_rw(reg);
    while(bufSize--)
        soft_spi_rw(*bufPtr++);
    CSN = 1;
    return stat;
}

/**
 * @function: nrf_config
 * @brief: setup common configuration
 */
static void nrf_config(void)
{
    nrf_write_reg(W_REGISTER + EN_AA, 0x01);        // enable auto acknowledgement data pipe 0
    nrf_write_reg(W_REGISTER + EN_RXADDR, 0x01);    // enable data pipe 0
    nrf_write_reg(W_REGISTER + SETUP_AW, 0x01);     // setup 3 bytes address length
/*    nrf_write_reg(W_REGISTER + SETUP_RETR, 0x1A); // setup auto retransmit delay 500us, retransmit count 10 */
    nrf_write_reg(W_REGISTER + RF_CH, 0x28);        // setup RF channel to 40
    nrf_write_reg(W_REGISTER + RF_SETUP, 0x07);     // setup RF output power=0dBm, data rate=2Mbps
}

static void nrf_flush_tx(void)
{
    nrf_write_reg(FLUSH_TX, 0);
}

static void nrf_flush_rx(void)
{
    nrf_write_reg(FLUSH_RX, 0);
}    

/**
 * @function: nrf24l01_init
 * @brief: initialize device; 
 * only after init, can now enter either ptx mode or prx mode
 */
void nrf24l01_init(void)
{
    sys_delay_1ms(15);      //delay for power on reset;
    CE = 0;
    CSN = 1;
    SCK = 0;
    nrf_config();
}

/**
 * @function: nrf24l01_set_ptx_mode
 * @param: none
 * @brief: device can function as either a ptx device or prx device,
 * once the ptx mode settled, the device is now ready to tx data packet to a remote target node.
 */
void nrf24l01_set_ptx_mode(void)
{
    CE = 0;
    
    nrf_write_reg(W_REGISTER + CONFIG, 0x0E);    
    
    CE = 1;
    sys_delay_5us(4);
}

/**
 * @function: nrf24l01_set_prx_mode
 * @param: rx_addr, usually the local ip for the prx device
 * @brief:device can function as either a ptx device or prx device,
 * once the prx mode settled, the device is now ready to rx data packet from a remote node.
 */
void nrf24l01_set_prx_mode(uchar* rx_addr)
{
    CE = 0;
    nrf_write_buf(W_REGISTER + RX_ADDR_P0, rx_addr, RX_ADDR_WIDTH);
    nrf_write_reg(W_REGISTER + RX_PW_P0, TX_PLOAD_WIDTH);
    nrf_write_reg(W_REGISTER + CONFIG, 0x0F);
    CE = 1;
    sys_delay_5us(30);
}

byte nrf24l01_get_status(void)
{
    return nrf_read_reg(STATUS);
}

void nrf24l01_clear_irq(void)
{
    byte stat;
    CE = 0;
    stat = nrf_read_reg(STATUS);
    stat |= 0x70;
    nrf_write_reg(W_REGISTER + STATUS, stat);
    CE = 1;
}

/**
 * @function: nrf24l01_tx_packet
 * @param: tx_addr, usually the remote target node ip
 * @param: tx_pld, data packet to be transmitted
 * @return: none
 * @brief: tx a data packet to remote target node
 */
void nrf24l01_tx_packet(byte* tx_addr, byte* tx_pld)
{
    CE = 0;
    nrf_flush_tx(); // flush TX FIFO before tx a new data packet
    nrf_write_buf(W_TX_PAYLOAD, tx_pld, TX_PLOAD_WIDTH);
    nrf_write_buf(W_REGISTER + TX_ADDR, tx_addr, TX_ADDR_WIDTH);
    nrf_write_buf(W_REGISTER + RX_ADDR_P0, tx_addr, TX_ADDR_WIDTH);
    CE = 1;
    sys_delay_5us(30);
}


void nrf24l01_rx_packet(byte* rx_pld)
{
    CE = 0;
    nrf_read_buf(R_RX_PAYLOAD, rx_pld, RX_PLOAD_WIDTH);
    nrf_flush_rx(); // flush RX FIFO after rx a data packet
    CE = 1;
}
