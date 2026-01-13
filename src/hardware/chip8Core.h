//
// Created by RageZ on 14/11/2025.
//

#ifndef CHI_8_PROJECT_CHIP8CORE_H
#define CHI_8_PROJECT_CHIP8CORE_H

#include <cstdint>
class chip8Core {

public:
    chip8Core();
    void initialize();
    void prepareROM(const char *filename);

private:

    static const int RAM_SIZE = 4096;
    static const int STACK_SIZE = 16;
    static const int NUM_REGISTERS = 16;
    static const uint16_t PROGRAM_START = 0x200;

    uint8_t v[16];
    uint16_t I;
    uint16_t pc;
    uint8_t sp;


    // Timers
    uint8_t delay;
    uint8_t sound;

    // Memory and stack
    uint8_t memory[4096];
    uint16_t stack[16];



};


#endif //CHI_8_PROJECT_CHIP8CORE_H
