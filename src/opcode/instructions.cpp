//
// Created by Janos on 13.01.2026.
//

#include "Instructions.h"

void Instructions::OP_00E0(Chip8Core &core) {
    core.clearScreen();
}

void Instructions::OP_00EE(Chip8Core &core) {
    --core.sp;
    core.pc = core.stack[core.sp];
}

void Instructions::OP_1nnn(Chip8Core &core, uint16_t opcode) {
    uint16_t nnn = opcode & 0x0FFF;
    core.pc = nnn;
}

void Instructions::OP_2nnn(Chip8Core &core, uint16_t opcode) {
    uint16_t nnn = opcode & 0x0FFF;

    core.stack[core.sp] = core.pc;
    ++core.sp;
    core.pc = nnn;
}

void Instructions::OP_3xkk(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t kk = opcode & 0x00FF;

    if (core.v[x] == kk) {
        core.pc += 2;
    }
}

void Instructions::OP_4xkk(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t kk = opcode & 0x00FF;

    if (core.v[x] != kk) {
        core.pc += 2;
    }
}

void Instructions::OP_5xy0(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    if (core.v[x] == core.v[y]) {
        core.pc += 2;
    }
}

void Instructions::OP_6xkk(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >>8;
    uint8_t kk = opcode & 0x00FF;

    core.v[x] = kk;
}

void Instructions::OP_7xkk(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t kk = opcode & 0x00FF;

    core.v[x] += kk;
}

void Instructions::OP_8xy0(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    core.v[x] = core.v[y];
}

void Instructions::OP_8xy1(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    core.v[x] = core.v[x] | core.v[y];
}

void Instructions::OP_8xy2(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    core.v[x] = core.v[x] & core.v[y];
}

void Instructions::OP_8xy3(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    core.v[x] ^= core.v[y];
}

void Instructions::OP_8xy4(Chip8Core &core, uint16_t opcode) {
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

void Instructions::OP_8xy5(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    if (core.v[x] > core.v[y]) {
        core.v[0xF] = 1;
    } else {
        core.v[0xF] = 0;
    }

    core.v[x] -= core.v[y];
}

void Instructions::OP_8xy6(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    core.v[0xF] = (core.v[x] & 0x1u);
    core.v[x] >>= 1;
}

void Instructions::OP_8xy7(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    if (core.v[y] > core.v[x]) {
        core.v[0xF] = 1;
    } else {
        core.v[0xF] = 0;
    }
    core.v[x] = core.v[y] - core.v[x];
}

void Instructions::OP_8xyE(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    core.v[0xF] = (core.v[x] & 0x80u) >> 7;

    core.v[x] <<= 1;
}

void Instructions::OP_9xy0(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;

    if (core.v[x] != core.v[y]) {
        core.pc += 2;
    }
}

void Instructions::OP_Annn(Chip8Core &core, uint16_t opcode) {
    uint16_t nnn = (opcode & 0x0FFF);

    core.I = nnn;
}

void Instructions::OP_Bnnn(Chip8Core &core, uint16_t opcode) {
    uint16_t nnn = (opcode & 0x0FFF);

    core.pc = core.v[0] + nnn;
}

void Instructions::OP_Cxkk(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t kk = opcode & 0x00FF;

    core.v[x] = core.getRandom() & kk;
}
void Instructions::OP_Dxyn(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00FF) >> 4;
    uint8_t height = opcode & 0x000F;

    //no display implementation yet so variables are missing                        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    uint8_t posX = core.v[x] % VIDEO_WIDTH;
    uint8_t posY = core.v[y] % VIDEO_HEIGHT;

    core.v[0xF] = 0;

    for (unsigned int row = 0; row < height; ++row) {
        uint8_t spriteByte = core.memory[core.I + row];

        for (unsigned column = 0; column < 8; ++column) {
            uint8_t spritePixel = spriteByte & (0x80 >> column);
            uint8_t* screenPixel = &video[(posY + row) * VIDEO_WIDTH + (posX + column)];

            if (spritePixel)
                if (*screenPixel == 0xFFFFFFFF) {
                    core.v[0xF] = 1;
                }

            *screenPixel ^= 0xFFFFFFFF;
        }
    }
}

void Instructions::OP_Ex9E(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    uint8_t key = core.v[x];

    if (core.keypad[key]) {
        core.pc += 2;
    }
}

void Instructions::OP_ExA1(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    uint8_t key = core.v[x];

    if (!core.keypad[key]) {
        core.pc += 2;
    }
}

void Instructions::OP_Fx07(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    core.v[x] = core.delay;
}

void Instructions::OP_Fx0A(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >>8;

    if (core.keypad[0]) {
        core.v[x] = 0;
    } else if (core.keypad[1]) {
        core.v[x] = 1;
    } else if (core.keypad[2]) {
        core.v[x] = 2;
    } else if (core.keypad[3]) {
        core.v[x] = 3;
    } else if (core.keypad[4]) {
        core.v[x] = 4;
    } else if (core.keypad[5]) {
        core.v[x] = 5;
    } else if (core.keypad[6]) {
        core.v[x] = 6;
    } else if (core.keypad[7]) {
        core.v[x] = 7;
    } else if (core.keypad[8]) {
        core.v[x] = 8;
    } else if (core.keypad[9]) {
        core.v[x] = 9;
    } else if (core.keypad[10]) {
        core.v[x] = 10;
    } else if (core.keypad[11]) {
        core.v[x] = 11;
    } else if (core.keypad[12]) {
        core.v[x] = 12;
    } else if (core.keypad[13]) {
        core.v[x] = 13;
    } else if (core.keypad[14]) {
        core.v[x] = 14;
    } else if (core.keypad[15]) {
        core.v[x] = 15;
    } else {
        core.pc -= 2;
    }
}

void Instructions::OP_Fx15(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    core.delay = core.v[x];
}

void Instructions::OP_Fx18(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    core.sound = core.v[x];
}

void Instructions::OP_Fx1E(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    core.I += core.v[x];
}

void Instructions::OP_Fx29(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t fontDigit = core.v[x];

    core.I = core.FONTSET_START_ADDRESS + (5 * fontDigit);
}

void Instructions::OP_Fx33(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t number = core.v[x];

    core.memory[core.I + 2] = number % 10;
    number /= 10;

    core.memory[core.I + 1] = number % 10;
    number /= 10;

    core.memory[core.I] = number % 10;
}

void Instructions::OP_Fx55(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >>8;

    for (uint8_t i = 0; i <= x; i++) {
        core.memory[core.I + i] = core .v[i];
    }
}

void Instructions::OP_Fx65(Chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    for (uint8_t i = 0; i <= x; i++) {
        core.v[i] = core.memory[core.I + i];
    }
}







