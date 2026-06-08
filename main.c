#include "hal.h"
#include "stdint.h"

int main(void){
    uint32_t count = 0;

    gpio_config(0, 1);
    gpio_config(1, 1);
    gpio_config(2, 1);

    while(1){
        for(volatile int i = 0; i < 10000000; i++);
        gpio_write(7, count++ & 7);
    }
    
}