//
// Created by RageZ on 14/11/2025.
//

#ifndef CHI_8_PROJECT_CHIP8_H
#define CHI_8_PROJECT_CHIP8_H

#include <cstdint>
class chip8 {

public:
    chip8();
    void initialize();
    void prepareROM(const char *filename);

private:
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

    // Input and display
    uint8_t keypad[16];
    uint8_t display[64 * 32];

};


#endif //CHI_8_PROJECT_CHIP8_H
