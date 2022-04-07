#include <stdint.h>
#include "gpio.h"

#define UART ((NRF_UART_REG*)0x40002000) 

void uart_init();
void uart_send(char letter);
char uart_read();

typedef struct {
    volatile uint32_t TASKS_STARTRX;
    volatile uint32_t TASKS_STOPRX;
    volatile uint32_t TASKS_STARTTX;
    volatile uint32_t TASKS_STOPTX;
    volatile uint32_t RESERVD_1[3];
    volatile uint32_t TASKS_SUSPEND;
    volatile uint32_t RESERVD_2[56];
    volatile uint32_t EVENTS_CTS;
    volatile uint32_t EVENTS_NCTS;
    volatile uint32_t EVENTS_RXDRDY;
    volatile uint32_t RESERVD_3[4];
    volatile uint32_t EVENTS_TXDRDY;
    volatile uint32_t RESERVD_4[1];
    volatile uint32_t EVENTS_ERROR;
    volatile uint32_t RESERVD_5[7];
    volatile uint32_t EVENTS_RXTO;
    volatile uint32_t RESERVD_6[46];
    volatile uint32_t SHORTS;
    volatile uint32_t RESERVD_7[64];
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR;
    volatile uint32_t RESERVD_8[93];
    volatile uint32_t ERRORSRC;
    volatile uint32_t RESERVD_9[31];
    volatile uint32_t ENABLE;
    volatile uint32_t RESERVD_10[1];
    volatile uint32_t PSELRTS;
    volatile uint32_t PSELRXD;
    volatile uint32_t PSELCTS;
    volatile uint32_t PSELTXD;
    volatile uint32_t RXD;
    volatile uint32_t TXD;
    volatile uint32_t RESERVD_11[1];
    volatile uint32_t BAUDRATE;
    volatile uint32_t RESERVD_12[17];
    volatile uint32_t CONFIG;
}NRF_UART_REG;


