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
    running = true;

    while(running) {
        core.cycle();


        //add the visual initialization here
    }
}


void Chip8Emulator::stop() {

    running = false;
}