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

void instructions::OP_4xkk(chip8Core &core, uint8_t x, uint8_t kk) {
    if (core.v[x] != kk) {
        core.pc += 2;
    }
}

void instructions::OP_5xy0(chip8Core &core, uint8_t x, uint8_t y) {
    if (core.v[x] == core.v[y]) {
        core.pc += 2;
    }
}

void instructions::OP_6xkk(chip8Core &core, uint8_t x, uint8_t kk) {
    core.v[x] = kk;
}

void instructions::OP_7xkk(chip8Core &core, uint8_t x, uint8_t kk) {
    core.v[x] += kk;
}

void instructions::OP_8xy0(chip8Core &core, uint8_t x, uint8_t y) {
    core.v[x] = core.v[y];
}

void instructions::OP_8xy1(chip8Core &core, uint8_t x, uint8_t y) {
    core.v[x] = core.v[x] | core.v[y];
}

void instructions::OP_8xy2(chip8Core &core, uint8_t x, uint8_t y) {
    core.v[x] = core.v[x] & core.v[y];
}

void instructions::OP_8xy3(chip8Core &core, uint8_t x, uint8_t y) {
    core.v[x] ^= core.v[y];
}

void instructions::OP_8xy4(chip8Core &core, uint8_t x, uint8_t y) {
    uint16_t sum = core.v[x] + core.v[y];

    if (sum > 255U) {
        core.v[0xF] = 1;
    } else {
        core.v[0xF] = 0;
    }

    core.v[x] = sum & 0xFFu;
}

void instructions::OP_8xy5(chip8Core &core, uint8_t x, uint8_t y) {
    if (core.v[x] > core.v[y]) {
        core.v[0xF] = 1;
    } else {
        core.v[0xF] = 0;
    }

    core.v[x] -= core.v[y];
}