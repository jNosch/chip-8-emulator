
//
// Created by RageZ on 14/11/2025.
//

#include "chip8.h"





Chip8::Chip8()
{
    initialize();
}

void Chip8::initialize() {
    pc = 0x200; //program counter
    delay = 0; // 8 it timer that counts down at 60Hz
    sound = 0; //counts down aswell, used for sound
    I = 0; //index register --> 16 bit register to hold memory adresses
    sp = 0; //stack pointer



    //clear memory etc
    for (int i = 0; i < 4096; ++i)
        memory[i] = 0;
    for (int i = 0; i < 16; ++i)
    {
        v[i] = 0;
        stack[i] = 0;
        keypad[i] = 0;
    }
    for (int i = 0; i < 64 * 32; ++i)
        display[i] = 0;

    //fontset??
}

void Chip8::prepareROM(const char *filename)
{

}
