//
// Created by RageZ on 13/01/2026.
//

#ifndef CHI_8_PROJECT_CHIP8EMULATOR_H
#define CHI_8_PROJECT_CHIP8EMULATOR_H

#include <string>
#include "../hardware/chip8Core.h"


class chip8Emulator {
public:
    chip8Emulator();
    void loadRom(const std::string& rom_path);
    void run();
    void stop();

private:
    chip8Core core;
    bool running;

};


#endif //CHI_8_PROJECT_CHIP8EMULATOR_H
