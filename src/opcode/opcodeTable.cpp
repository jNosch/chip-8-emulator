//
// Created by RageZ on 16/01/2026.
//

#include "opcodeTable.h"
#include "instructions.h"

opcodeTable::opcodeTable() {

    table[0x0] = [this](chip8Core& core, uint16_t opcode) { Table0(core, opcode); };
    table[0x1] = [](chip8Core& core, uint16_t opcode) {instructions::OP_1nnn(core, opcode); };
    table[0x2] = [](chip8Core& core, uint16_t opcode) {instructions::OP_2nnn(core, opcode); };
    table[0x3] = [](chip8Core& core, uint16_t opcode) {instructions::OP_3xkk(core, opcode); };
    table[0x4] = [](chip8Core& core, uint16_t opcode) {instructions::OP_4xkk(core, opcode); };
    table[0x5] = [](chip8Core& core, uint16_t opcode) {instructions::OP_5xy0(core, opcode); };
    table[0x6] = [](chip8Core& core, uint16_t opcode) {instructions::OP_6xkk(core, opcode); };
    table[0x7] = [](chip8Core& core, uint16_t opcode) {instructions::OP_7xkk(core, opcode);};
    table[0x8] = [this](chip8Core& core, uint16_t opcode) {Table8(core, opcode);};
    table[0x9] = [](chip8Core& core, uint16_t opcode) {instructions::OP_9xy0(core, opcode); };
    table[0xA] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Annn(core, opcode); };
    table[0xB] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Bnnn(core, opcode); };
    table[0xC] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Cxkk(core, opcode); };
    table[0xD] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Dxyn(core, opcode); };
    table[0xE] = [this](chip8Core& core, uint16_t opcode) {TableE(core, opcode); };
    table[0xF] = [this](chip8Core& core, uint16_t opcode) {TableF(core, opcode); };

    for (auto& func : table0) {
        func = [this] (chip8Core& core, uint16_t opcode) { OP_NULL(core, opcode); };
    }
    table0[0x0] = [](chip8Core& core, uint16_t opcode) {instructions::OP_00E0(core); };
    table0[0xE] = [](chip8Core& core, uint16_t opcode) {instructions::OP_00EE(core); };


    for (auto& func : table8) {
        func = [this](chip8Core& core, uint16_t opcode) {OP_NULL(core, opcode); };
    }
    table8[0x0] = [](chip8Core& core, uint16_t opcode) {instructions::OP_8xy0(core, opcode); };
    table8[0x1] = [](chip8Core& core, uint16_t opcode) {instructions::OP_8xy1(core, opcode); };
    table8[0x2] = [](chip8Core& core, uint16_t opcode) {instructions::OP_8xy2(core, opcode); };
    table8[0x3] = [](chip8Core& core, uint16_t opcode) {instructions::OP_8xy3(core, opcode); };
    table8[0x4] = [](chip8Core& core, uint16_t opcode) {instructions::OP_8xy4(core, opcode); };
    table8[0x5] = [](chip8Core& core, uint16_t opcode) {instructions::OP_8xy5(core, opcode); };
    table8[0x6] = [](chip8Core& core, uint16_t opcode) {instructions::OP_8xy6(core, opcode); };
    table8[0x7] = [](chip8Core& core, uint16_t opcode) {instructions::OP_8xy7(core, opcode); };
    table8[0xE] = [](chip8Core& core, uint16_t opcode) {instructions::OP_8xyE(core, opcode); };

    for (auto& func : tableE) {
        func = [this](chip8Core& core, uint16_t opcode) {OP_NULL(core, opcode); };
    }
    tableE[0xE] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Ex9E(core, opcode); };
    tableE[0x1] = [](chip8Core& core, uint16_t opcode) {instructions::OP_ExA1(core, opcode); };

    for (auto& func : tableF) {
        func = [this] (chip8Core& core, uint16_t opcode) {OP_NULL(core, opcode); };
    }
    tableF[0x07] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Fx07(core, opcode); };
    tableF[0x0A] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Fx0A(core, opcode); };
    tableF[0x15] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Fx15(core, opcode); };
    tableF[0x18] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Fx18(core, opcode); };
    tableF[0x1E] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Fx1E(core, opcode); };
    tableF[0x29] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Fx29(core, opcode); };
    tableF[0x33] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Fx33(core, opcode); };
    tableF[0x55] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Fx55(core, opcode); };
    tableF[0x65] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Fx65(core, opcode); };
}

void opcodeTable::execute(chip8Core& core, uint16_t opcode) {
    uint8_t firstNibble = (opcode & 0xF000) >> 12;
    table[firstNibble](core, opcode);
}

void opcodeTable::Table0(chip8Core& core, uint16_t opcode) {
    uint8_t lastNibble = opcode & 0x000F;
    table0[lastNibble] (core, opcode);
}

void opcodeTable::Table8(chip8Core& core, uint16_t opcode) {
    uint8_t lastNibble = opcode & 0x000F;
    table8[lastNibble] (core, opcode);
}

void opcodeTable::TableE(chip8Core& core, uint16_t opcode) {
    uint8_t lastByte = opcode & 0x00FF;
    tableE[lastByte](core, opcode);
}

void opcodeTable::TableF(chip8Core& core, uint16_t opcode) {
    uint8_t lastByte = opcode & 0x00FF;
    tableF[lastByte](core, opcode);
}

void opcodeTable::OP_NULL(chip8Core &core, uint16_t opcode) {
    //implement some type of error logging                                      !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

