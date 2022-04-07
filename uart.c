#include "uart.h"

void uart_init(){
    GPIO1->PIN_CNF[8] = 1;  //TX
	GPIO0->PIN_CNF[6] = 0; //RX 

    UART->PSELRTS = (1<<31);
    UART->PSELTXD = 0x06;
    UART->PSELCTS = (1<<31);
    UART->PSELRXD = 0x28;

    
    UART->BAUDRATE = 0x00275000; //9600
    UART->ENABLE = 4; 
    UART->TASKS_STARTTX = 1;
}

void uart_send(char letter){
    UART->TASKS_STARTTX = 1;
    UART->TXD = letter;

    while(!(UART->EVENTS_TXDRDY)){
    }

    UART->EVENTS_TXDRDY = 0;
    UART->TASKS_STOPTX = 1;
}


char uart_read(){
    //UART->EVENTS_RXDRDY = 0;
    UART->TASKS_STARTRX = 1;
    if(UART->EVENTS_RXDRDY){
        UART->EVENTS_RXDRDY = 0;
        char letter = UART->RXD;
        return letter;
    }else{
        return '\0';
    }
}

//void uart_send_str(char ** str)