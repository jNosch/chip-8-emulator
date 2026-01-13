
//
// Created by RageZ on 14/11/2025.
//

#include "chip8Core.h"
#include <fstream>
#include <cstring>
#include <chrono>
#include <random>




chip8Core::chip8Core()
{
    initialize();
}

void chip8Core::initialize() {
    const unsigned int START_ADDRESS_FOR_ROM = 0x200;
    const int MAX_ROM_SIZE = 4096 - 0x200;
    const int ROM_START_ADDRESS = 0x200;

    const unsigned int FONTSET_SIZE = 80; //Array of 80 bytes for the FONT SET
    const unsigned  int FONTSET_START_ADDRESS = 0x50; //memory position for fontset

void chip8Core::initialize(){
    pc = 0x200;  //for program counter and where to start on initialization
    delay = 0; // 8 it timer that counts down at 60Hz
    sound = 0; //counts down aswell, used for sound
    I = 0; //index register --> 16 bit register to hold memory adresses
    sp = 0; //stack pointer

    //clear memory, stack and registers
    memset(memory, 0, sizeof (memory));
    memset(stack, 0, sizeof (stack));
    memset(v, 0, sizeof (v));

    loadFontset();
}



void chip8Core::loadFontset() {

    //font set definition
    uint8_t fontset[FONTSET_SIZE] =
            {
                    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
                    0x20, 0x60, 0x20, 0x20, 0x70, // 1
                    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
                    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
                    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
                    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
                    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
                    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
                    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
                    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
                    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
                    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
                    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
                    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
                    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
                    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
            };

    //load the fonts into memory
    for (unsigned int i = 0; i < FONTSET_SIZE; ++i) {
        memory[FONTSET_START_ADDRESS + i] = fontset[i];
    }
}

    //loading  a ROM file into memory
bool chip8Core::load_rom(std::string rom_path) {
        std::ifstream f(rom_path, std::ios::binary | std::ios::ate);
        //error handling
        if (!file.is_open()) {
            std::cerr << "Failed to open ROM: " << rom_path << std::endl;
            return false;
        }

        //get file size
        std::streamsize size = file.tellg();

        //check if file fits
        if (size > MAX_ROM_SIZE) {
            std::cerr
            <<"ROM to large: " << size << " bytes (max: " << MAX_ROM_SIZE << ")" <<std::endl;
            return false;
        }

        file.seekg(0, std::ios::beg);

        //read into memory
        if (!file.read(reinterpret_cast<char*>(&memory[ROM_START_ADDRESS]), size)) {
            std::cerr << "failed to read ROM data" << std::endl;
            return false;
        }

        file.close();
    }

    chip8Core::ranndomNumberGenerator(std::chrono::system_clock::now().time_since_epoch().count()) {
        randByte = std::uniform_int_distribution<uint8_t>(0, 255U);
}

    std::default_random_engine randomNumberGenerator;
    std::uniform_int_distribution<uint8_t> randByte;


}



