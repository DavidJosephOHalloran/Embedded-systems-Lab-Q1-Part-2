// Adding the debounce function
// Timer is set to 100ms, after testing different settings this appears to be the best time

#include "mbed.h"

InterruptIn joystick_up(p15);
InterruptIn joystick_down(p12);
InterruptIn joystick_left(p13);
InterruptIn joystick_right(p16);
InterruptIn joystick_center(p14);

Timer debounce_timer;

void joystick_up_h() {
    if (debounce_timer.read_ms() > 100) { 
        printf("Joystick up\n");
        debounce_timer.reset();
    }
}

void joystick_down_h() {
    if (debounce_timer.read_ms() > 100) { 
        printf("Joystick down\n");
        debounce_timer.reset();
    }
}

void joystick_left_h() {
    if (debounce_timer.read_ms() > 100) { 
        printf("Joystick left\n");
        debounce_timer.reset();
    }
}

void joystick_right_h() {
    if (debounce_timer.read_ms() > 100) { 
        printf("Joystick right\n");
        debounce_timer.reset();
    }
}

void joystick_center_h() {
    if (debounce_timer.read_ms() > 100) { 
        printf("Joystick center\n");
        debounce_timer.reset();
    }
}

int main() {
    debounce_timer.start();
    joystick_up.rise(&joystick_up_h);
    joystick_down.rise(&joystick_down_h);
    joystick_left.rise(&joystick_left_h);
    joystick_right.rise(&joystick_right_h);
    joystick_center.rise(&joystick_center_h);
    while(1) {
    
        wait_us(10);
    }
}