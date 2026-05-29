//
// Created by RageZ on 13/01/2026.
//

#include <stdexcept>
#include "Chip8Emulator.h"

Chip8Emulator::Chip8Emulator() : running(false)
{}
void Chip8Emulator::loadRom(const std::string &rom_path) {
        if (!core.loadRom(rom_path)) {
            throw std::runtime_error("failed to load rom" + rom_path);
        }
}

void Chip8Emulator::run() {

    if (!display.initialize()) {
        throw std::runtime_error("Display init failed");
    }
    running = true;

    while(running) {

        if (display.windowClose()) {
            stop();
        }

        core.cycle();

        if(core.drawFlag) {
            display.render(core.video);
            core.drawFlag = false;
        }

        SDL_Delay(2);  //implement proper frequency/cpu timing!!!!!!!!!!!!!!!!!
    }
}

void Chip8Emulator::stop() {
    running = false;
}