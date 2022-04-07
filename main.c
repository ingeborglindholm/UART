#include "uart.h"
#include "gpio.h"

#include <stdio.h>

int checkAbtn(){
	return (!(GPIO0->IN & (1 << 14))); 
}
 
int checkBbtn(){
	return (!(GPIO0->IN & (1 << 23))); 
}


int oppg2_4(){

    while(1){
    char letter = uart_read(); 
        if (letter == '\0'){
            continue;
        }
        else{
            if (GPIO0->OUT & (1<<21)){
                gpio_lights_off(); 
            }
            else{
                gpio_lights_on(); 
            }
        }

    }
    return 0; 
}

int oppg2_3(){
    //int Bpushed; 
	int Apushed; 
	
	int sleep = 0;

	while(1){
        
		//Bpushed = checkBbtn(); 
		if (!(GPIO0->IN & (1 << 23))){
			gpio_lights_on(); 
            uart_send('B'); 
		}

		Apushed = checkAbtn(); 
		if (Apushed == 1){
			gpio_lights_off();  
            uart_send('A'); 
		}

		sleep = 10000;
		while(--sleep);
	}
	return 0;    
}

ssize_t _write(int fd, const void *buf, size_t count){
    char * letter = (char *)(buf);
    for(int i = 0; i < count; i++){
        uart_send(*letter);
        letter++;
    }
    return count;
}
int main(){
    uart_init(); 
    gpio_init();
    
    iprintf("The average grade in TTK%d was in %d and %d: %c\n\r",4235,2019,2018,'C');
    iprintf("Hei");
    //oppg2_3(); 
    //oppg2_4();
}