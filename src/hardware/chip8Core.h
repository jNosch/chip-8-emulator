//
// Created by RageZ on 14/11/2025.
//

#ifndef CHI_8_PROJECT_CHIP8CORE_H
#define CHI_8_PROJECT_CHIP8CORE_H

#include "../opcode/OpcodeTable.h"
#include <cstdint>
#include <random>

class Chip8Core {

public:
    Chip8Core();
    //ungrouped functions
    void initialize();
    void loadFontset();
    bool loadRom(std::string rom_path);
    uint8_t getRandom();
    void cycle();

    //font related values
    static const unsigned  int FONTSET_START_ADDRESS = 0x50; //memory position for fontset
    static const unsigned int FONTSET_SIZE = 80; //Memory size 80 for the fonts (16chars time 5 bytes)


    //ROM related variables
    static const int MAX_ROM_SIZE = 4096 - 0x200;
    static const int ROM_START_ADDRESS = 0x200;

    //video
    uint8_t video[64 * 32];
    bool drawFlag;
    void clearScreen();

    //input
    uint8_t keypad[16];

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



private:
    OpcodeTable table;

    static const int RAM_SIZE = 4096;
    static const int STACK_SIZE = 16;
    static const int NUM_REGISTERS = 16;
    static const uint16_t PROGRAM_START = 0x200;

    std::default_random_engine randomNumberGenerator;
    std::uniform_int_distribution<uint8_t> randByte;

};


#endif //CHI_8_PROJECT_CHIP8CORE_H
