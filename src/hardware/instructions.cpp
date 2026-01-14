//
// Created by Janos on 13.01.2026.
//

#include "instructions.h"

void instructions::OP_00E0(chip8Core &core) {
    core.clearScreen();
}

void instructions::OP_00EE(chip8Core &core) {
    --core.sp;
    core.pc = core.stack[core.sp];
}

void instructions::OP_1nnn(chip8Core &core, uint16_t nnn) {
    core.pc = nnn;
}

void instructions::OP_2nnn(chip8Core &core, uint16_t nnn) {
    core.stack[core.sp] = core.pc;
    ++core.sp;
    core.pc = nnn;
}

void instructions::OP_3xkk(chip8Core &core, uint8_t x, uint8_t kk) {
    if (core.v[x] == kk) {
        core.pc += 2;
    }
}