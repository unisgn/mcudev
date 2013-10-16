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
    byte stat, next_frame;
    CSN = 0;
    stat = soft_spi_rw(reg);
    for(next_frame = 0; next_frame < bufSize; next_frame++)
        bufPtr[next_frame] = soft_spi_rw(0);
    CSN = 1;
    return stat;
}

static byte nrf_write_buf(uint8_t reg, byte* bufPtr, uint8_t bufSize)
{
    byte stat, next_frame = 0;
    stat = soft_spi_rw(reg);
    CSN = 0;
    while((next_frame++) < bufSize)
        soft_spi_rw(*bufPtr++);
    CSN = 1;
    return stat;
}

static void nrf_config(void)
{
    CE = 0;
    nrf_write_reg(WRITE_REG + EN_AA, 0x01);			// enable auto acknowledgement data pipe 0
	nrf_write_reg(WRITE_REG + EN_RXADDR, 0x01);		// enable data pipe 0
	nrf_write_reg(WRITE_REG + SETUP_AW, 0x01);		// setup 3 bytes address length
	nrf_write_reg(WRITE_REG + SETUP_RETR, 0x1A);	// setup auto retransmit delay 500us, retransmit count 10
	nrf_write_reg(WRITE_REG + RF_CH, 0x28);			// setup RF channel to 2440MHz
	nrf_write_reg(WRITE_REG + RF_SETUP, 0x06);		// setup RF output power=0dBm, data rate=1Mbps
	// TX_ADDR, RX_ADDR, PAYLOAD will be configed on demand;
    CE = 1;
    sys_delay_5us(30);
}

void nrf24l01_init(void)
{
    sys_delay_1ms(100);
    CE = 0;
    CSN = 1;
    SCK = 0;
    
    nrf_config();
}

void nrf24l01_set_ptx_mode(void)
{
    CE = 0;
	nrf_write_buf(WRITE_REG + TX_ADDR, tx_addr, TX_ADDR_SIZE);
	nrf_write_buf(WRITE_REG + RX_ADDR_P0, rx_addr, RX_ADDR_SIZE);
	nrf_write_buf(WR_TX_PLOAD, tx_buf, TX_PLOAD_SIZE);

	nrf_write_reg(WRITE_REG + CONFIG, 0x0E);
    CE = 1;
    sys_delay_5us(30);
}

void nrf24l01_set_prx_mode(void)
{
    CE = 0;
	nrf_write_buf(WRITE_REG + RX_ADDR_P0, rx_addr, RX_ADDR_SIZE);
	nrf_write_reg(WRITE_REG + CONFIG, 0x0F);
    CE = 1;
    sys_delay_5us(30);
}

