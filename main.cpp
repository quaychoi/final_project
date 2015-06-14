#include "mbed.h"



int main() {
    int value = 0;
    register uint16_t myled1_bit_mask=0;
    int counter= 0;
    //myled1_bit_mask = 0x00040000; // 0x040000 = 1<<18 all "0"s with a "1" in bit 18
    myled1_bit_mask = 1<<4;
    LPC_GPIO1->FIODIRH = myled1_bit_mask;
    // loop forever
    while (1) {
        //control LED1 using C/C++ hardware I/O register names
        //from LPC1768 data manual the LED1 pin goes to GPIO1 port bit 18

        if (value==0) {
            LPC_GPIO1->FIOCLRH = myled1_bit_mask; //Write to register that clears bits
        } else {
            LPC_GPIO1->FIOSETH =  myled1_bit_mask;//Write to register that sets bits
        }
        if (counter < 1000000) {
            counter++;
        } else {
            counter = 0;
        }
        if (counter == 1000000) {
                value = ~value;
        }
    }
}
