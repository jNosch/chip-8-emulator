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
    uint8_t y = (opcode & 0x00F0) >> 4;

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

void instructions::OP_8xyE(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    core.v[0xF] = (core.v[x] & 0x80u) >> 7;

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
void instructions::OP_Dxyn(chip8Core &core, uint16_t opcode) {
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

void instructions::OP_Fx0A(chip8Core &core, uint16_t opcode) {
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

void instructions::OP_Fx29(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t fontDigit = core.v[x];

    core.I = core.FONTSET_START_ADDRESS + (5 * fontDigit);
}

void instructions::OP_Fx33(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t number = core.v[x];

    core.memory[core.I + 2] = number % 10;
    number /= 10;

    core.memory[core.I + 1] = number % 10;
    number /= 10;

    core.memory[core.I] = number % 10;
}

void instructions::OP_Fx55(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >>8;

    for (uint8_t i = 0; i <= x; i++) {
        core.memory[core.I + i] = core .v[i];
    }

}

void instructions::OP_Fx65(chip8Core &core, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;

    for (uint8_t i = 0; i <= x; i++) {
        core.v[i] = core.memory[core.I + i];
    }
}







