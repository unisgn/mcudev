#include "main.h"

void main(void)
{
    byte nrf24l01_addr[3] = {0x01, 0x01, 0x01};
    byte nrf24l01_2_addr[3] = {0x01, 0x01, 0x02};
    uchar tx_buf[32] = "hello, nrf; msg from nrf2;......";
    printf("initializing system...\n");
    sys_init(); 
    printf("system initialized;\n");
    printf("initializing nrf24l01...\n");
    nrf24l01_init();
    printf("nrf24l01 initialized;\n");
    printf("initializing nrf24l01_2...\n");
    nrf24l01_2_init();
    printf("nrf24l01_2 initialized;\n");
    while(1) {
        printf("set nrf24l01 to prx mode;\n");
        nrf24l01_set_prx_mode(nrf24l01_addr);
        printf("set nrf24l01_2 to ptx mode;\n");
        nrf24l01_2_set_ptx_mode();
        printf("nrf2 is going to send a msg1: hello, nrf; msg from nrf2;\n ");
        nrf24l01_2_tx_packet(nrf24l01_addr, tx_buf);
        while(IRQ_2);
        if(nrf24l01_2_get_irq_status() & TX_DS) {
            printf("msg1 sent;\n");
            nrf24l01_2_clear_irq();
        }
        else if(nrf24l01_2_get_irq_status() & MAX_RT) {
            printf("cann't send msg1, max retry reached;\n");
            if(IRQ)
                printf("nrf received msg1;\n");
            else
                printf("nrf no msg received yet.\n");
            nrf24l01_2_clear_irq();
            sys_delay_1s(5);
            break;
        } else {
            printf("msg1 sent failed, reason unknown;\n");
            sys_delay_1s(5);
            break;
        }
        
        sys_delay_1s(5);
    }
}