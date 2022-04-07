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
    int switch_lights = 0;
    int lights_on = 0; 
    int sleep = 0;  

    while(1){
        char letter = uart_read(); 
        if (letter == '\n'){
            switch_lights = 0; 
        } else{
            switch_lights = 1; 
        }

        if (lights_on == 1){
            if (switch_lights == 1){
                gpio_lights_off(); 
            }
            else {
                gpio_lights_on(); 
            }
        }
        else{
            if (switch_lights == 1){
                gpio_lights_on(); 
            }
            else {
                gpio_lights_off(); 
            }        
        }
        sleep = 10000;
		while(--sleep);
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

int main(){
    uart_init(); 
    gpio_init();
    

    //oppg2_3(); 
    oppg2_4();

    /*int sleep = 0;

	while(1){
        iprintf("Rett terminal?");
		//Bpushed = checkBbtn(); 
		if (!(GPIO0->IN & (1 << 23))){
			gpio_lights_on(); 
            uart_send('B'); 
		}

		//Apushed = checkAbtn(); 
		if (!(GPIO0->IN & (1 << 14))){
			gpio_lights_off();  
            uart_send('A'); 
		}

		sleep = 10000;
		while(--sleep);
	}
	return 0; 
    */
}