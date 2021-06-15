#include <stdio.h>
#include "pico/stdlib.h"
#include <RF24.h>

RF24 radio(14, 15); // CE, CSN

int main(){
    //Initialise I/O
    stdio_init_all(); 

    // initialise GPIO (Green LED connected to pin 25)
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
        
    const uint8_t address[6] = "00001";

    for(int i = 0; i < 10; i++){
        printf("Starting...\n");
        sleep_ms(1000);
    }

    if (!radio.begin()) {
        printf("radio hardware is not responding!!\n");
        return false;
    }

    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_MIN);
    radio.stopListening();

    //Main Loop 
    while(1){
        gpio_put(25, 1); // Set pin 25 to high
        printf("LED ON!\n");
        sleep_ms(1000); // 0.5s delay

        const char text[] = "Hello World";
        radio.write(&text, sizeof(text));
        delay(1000);

        gpio_put(25, 0); // Set pin 25 to low
        printf("LED OFF!\n");
        sleep_ms(1000); // 0.5s delay
    }
}