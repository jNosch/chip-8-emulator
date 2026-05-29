//
// Created by RageZ on 13/01/2026.
//

#ifndef CHI_8_PROJECT_CHIP8EMULATOR_H
#define CHI_8_PROJECT_CHIP8EMULATOR_H

#include <string>
#include "../hardware/Chip8Core.h"
#include "../gui/Chip8Display.h"


class Chip8Emulator {
public:
    Chip8Emulator();
    void loadRom(const std::string& rom_path);
    void run();
    void stop();

private:
    Chip8Core core;
    Chip8Display display;
    bool running;


};


#endif //CHI_8_PROJECT_CHIP8EMULATOR_H
