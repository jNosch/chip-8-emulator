//
// Created by RageZ on 13/01/2026.
//

#include <stdexcept>
#include "chip8Emulator.h"

chip8Emulator::chip8Emulator() : running(false)
{}
void chip8Emulator::loadRom(const std::string &rom_path) {
        if (!core.loadRom(rom_path)) {
            throw std::runtime_error("failed to load rom" + rom_path);
        }
}
void chip8Emulator::run() {
    running = true;

    while(running) {
        core.cycle();


        //add the visual initialization here
    }
}


void chip8Emulator::stop() {

    running = false;
}