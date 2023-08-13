#include <nds.h>
#include <stdio.h>

void main(void) {
    iprintf("dscratch");

    while(1) {
        swiWaitForVBlank();
    }
}