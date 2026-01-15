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

void instructions::OP_1nnn(chip8Core &core, uint16_t opcode) {
    uint16_t nnn = opcode & 0x0FFF;
    core.pc = nnn;
}

void instructions::OP_2nnn(chip8Core &core, uint16_t opcode) {
    uint16_t nnn = opcode & 0x0FFF;

    core.stack[core.sp] = core.pc;
    ++core.sp;
    core.pc = nnn;
}

void instructions::OP_3xkk(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t kk = opcode & 0x00FF;

    if (core.v[x] == kk) {
        core.pc += 2;
    }
}

void instructions::OP_4xkk(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t kk = opcode & 0x00FF;

    if (core.v[x] != kk) {
        core.pc += 2;
    }
}

void instructions::OP_5xy0(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x0FFF) >> 4;

    if (core.v[x] == core.v[y]) {
        core.pc += 2;
    }
}

void instructions::OP_6xkk(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >>8;
    uint8_t kk = opcode & 0x00FF;

    core.v[x] = kk;
}

void instructions::OP_7xkk(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t kk = opcode & 0x00FF;

    core.v[x] += kk;
}

void instructions::OP_8xy0(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    core.v[x] = core.v[y];
}

void instructions::OP_8xy1(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    core.v[x] = core.v[x] | core.v[y];
}

void instructions::OP_8xy2(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    core.v[x] = core.v[x] & core.v[y];
}

void instructions::OP_8xy3(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    core.v[x] ^= core.v[y];
}

void instructions::OP_8xy4(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    uint16_t sum = core.v[x] + core.v[y];

    if (sum > 255U) {
        core.v[0xF] = 1;
    } else {
        core.v[0xF] = 0;
    }

    core.v[x] = sum & 0xFFu;
}

void instructions::OP_8xy5(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    if (core.v[x] > core.v[y]) {
        core.v[0xF] = 1;
    } else {
        core.v[0xF] = 0;
    }

    core.v[x] -= core.v[y];
}

void instructions::OP_8xy6(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    core.v[0xF] = (core.v[x] & 0x1u);
    core.v[x] >>= 1;
}

void instructions::OP_8xy7(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    if (core.v[y] > core.v[x]) {
        core.v[0xF] = 1;
    } else {
        core.v[0xF] = 0;
    }
    core.v[x] = core.v[y] - core.v[x];
}

//unsure how bit manipulation works here nor the bit map or the 7u left shift               !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void instructions::OP_8xyE(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    core.v[0xF] = (core.v[x] & 0x80u) >> 7u;

    core.v[x] <<= 1;
}

void instructions::OP_9xy0(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    if (core.v[x] != core.v[y]) {
        core.pc += 2;
    }
}

void instructions::OP_Annn(chip8Core &core, uint16_t opcode) {
    uint16_t nnn = (opcode & 0x0FFF);

    core.I = nnn;
}

void instructions::OP_Bnnn(chip8Core &core, uint16_t opcode) {
    uint16_t nnn = (opcode & 0x0FFF);

    core.pc = core.v[0] + nnn;
}

void instructions::OP_Cxkk(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t kk = opcode & 0x00FF;

    core.v[x] = core.getRandom() & kk;
}
//quite complex do it later                                                         !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void instructions::OP_Dxyn(chip8Core &core, uint16_t opcode) {

}

void instructions::OP_Ex9E(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    uint8_t key = core.v[x];

    if (core.keypad[key]) {
        core.pc += 2;
    }
}

void instructions::OP_ExA1(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    uint8_t key = core.v[x];

    if (!core.keypad[key]) {
        core.pc += 2;
    }
}

void instructions::OP_Fx07(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    core.v[x] = core.delay;
}
//complex do this one later aswell                                              !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void instructions::OP_Fx0A(chip8Core &core, uint16_t opcode) {

}

void instructions::OP_Fx15(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    core.delay = core.v[x];
}

void instructions::OP_Fx18(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    core.sound = core.v[x];
}

void instructions::OP_Fx1E(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    core.I += core.v[x];
}







