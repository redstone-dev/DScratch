#include <nds.h>
#include <stdio.h>
#include <stdbool.h>

#define SCREEN_TOP 0
#define SCREEN_BOTTOM 1

// u16 k_pressed;
// u16 k_held;
// u16 k_released;

void Setup() {
    // all setup code goes here
    NF_Set2D(SCREEN_BOTTOM, 0);
    NF_SetRootFolder("DSCRATCH_ROOT");
    iprintf("dscratch\n");
}

void MainLoop() {
    while(1) {
        scanKeys();
        // k_pressed = keysDown();
        // k_held = keysHeld();
        // k_released = keysUp();

        if (keysDown() & KEY_START) break;

        swiWaitForVBlank();
    }
}

int ConfirmExit() {
    iprintf("Press START  to confirm exit");
    iprintf("Press B      to restart");
    while (1) {
        scanKeys();

        if (keysDown() & KEY_START) break;

        if (keysDown() & KEY_B) return 1;

        swiWaitForVBlank();
    }
    return 0;
}

void main(void) {
    Setup();
    MainLoop();
    switch (ConfirmExit()) {
        case 0:
            exit(0);
        case 1:
            main(void);
        default:
            ConfirmExit();
    }
}