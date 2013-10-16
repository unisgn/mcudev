#include <nrf24l01_2.h>
#include <soft_spi_2.h>
#include <nrf24l01_reg.h>



static byte nrf_read_reg(uint8_t reg)
{
    byte stat;
    CSN_2 = 0;
    soft_spi_2_rw(reg);
    stat = soft_spi_2_rw(0);
    CSN_2 = 1;
    return stat;
}

static byte nrf_write_reg(uint8_t reg, byte dat)
{
    byte stat;
    CSN_2 = 0;
    stat = soft_spi_2_rw(reg);
    soft_spi_2_rw(dat);
    CSN_2 = 1;
    
    return stat;
}

static byte nrf_read_buf(uint8_t reg, byte* bufPtr, uint8_t bufSize)
{
    byte stat, next_frame;
    CSN_2 = 0;
    stat = soft_spi_2_rw(reg);
    for(next_frame = 0; next_frame < bufSize; next_frame++)
        bufPtr[next_frame] = soft_spi_2_rw(0);
    CSN_2 = 1;
    return stat;
}

static byte nrf_write_buf(uint8_t reg, byte* bufPtr, uint8_t bufSize)
{
    byte stat, next_frame;
    CSN_2 = 0;
    stat = soft_spi_2_rw(reg);
    for(next_frame = 0; next_frame < bufSize; next_frame++)
        soft_spi_2_rw(bufPtr[next_frame]);
    CSN_2 = 1;
    return stat;
}

static void nrf_config(void)
{

    nrf_write_reg(W_REGISTER + EN_AA, 0x01);		// enable auto acknowledgement data pipe 0
    nrf_write_reg(W_REGISTER + EN_RXADDR, 0x01);		// enable data pipe 0
    nrf_write_reg(W_REGISTER + SETUP_AW, 0x01);		// setup 3 bytes address length
    nrf_write_reg(W_REGISTER + SETUP_RETR, 0x1A);	// setup auto retransmit delay 500us, retransmit count 10
    nrf_write_reg(W_REGISTER + RF_CH, 0x28);		// setup RF channel to 2440MHz
    nrf_write_reg(W_REGISTER + RF_SETUP, 0x06);		// setup RF output power=0dBm, data rate=1Mbps
    nrf_write_reg(W_REGISTER + RX_PW_P0, TX_PLOAD_WIDTH);
	// TX_ADDR, RX_ADDR, PAYLOAD will be configed on demand;
}

void nrf24l01_2_init(void)
{
    CE_2 = 0;
    CSN_2 = 1;
    SCK_2 = 0;
    nrf_config();
}

void nrf24l01_2_set_ptx_mode(void)
{
    CE_2 = 0;
    nrf_write_reg(W_REGISTER + CONFIG, 0x0E);    
    sys_delay_1ms(5);    
    CE_2 = 1;
    sys_delay_5us(4);
}

void nrf24l01_2_set_prx_mode(uchar* rx_addr)
{
    CE_2 = 0;
    nrf_write_buf(W_REGISTER + RX_ADDR_P0, rx_addr, RX_ADDR_WIDTH);
    nrf_write_reg(W_REGISTER + CONFIG, 0x0F);
    sys_delay_1ms(5);
    CE_2 = 1;
    sys_delay_5us(4);
}

byte nrf24l01_2_get_irq_status(void)
{
    return nrf_read_reg(STATUS);
}

void nrf24l01_2_clear_irq(void)
{
    byte stat;
    CE_2 = 0;
    stat = nrf_read_reg(STATUS);
    stat |= 0x70;
    nrf_write_reg(W_REGISTER + STATUS, stat);
    CE_2 = 1;
}

void nrf24l01_2_tx_packet(byte* tx_addr, byte* tx_buf)
{
	CE_2 = 0;
    
    nrf_write_buf(W_REGISTER + TX_ADDR, tx_addr, TX_ADDR_WIDTH);
	nrf_write_buf(W_REGISTER + RX_ADDR_P0, tx_addr, TX_ADDR_WIDTH);  
    nrf_write_buf(W_TX_PAYLOAD, tx_buf, TX_PLOAD_WIDTH);

    CE_2 = 1;
}


void nrf24l01_2_rx_packet(byte* rx_buf)
{
    CE_2 = 0;
    nrf_read_buf(R_RX_PAYLOAD, rx_buf, RX_PLOAD_WIDTH);
    CE_2 = 1;
}
