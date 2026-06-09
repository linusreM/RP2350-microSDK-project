#include "hal.h"
#include "stdint.h"
#include "usb_cdc.h"
#include "string.h"

int main(void){
    uint32_t count = 0;
    uint8_t print_string[] = "Hello, world!\r\n";

    gpio_config(0, 1);
    gpio_config(1, 1);
    gpio_config(2, 1);
    usb_cdc_init();

    while(1){
        for(volatile int i = 0; i < 10000000; i++);
        gpio_write(7, count++ & 7);
        usb_cdc_transmit(print_string, strlen(print_string));
    }
    
}