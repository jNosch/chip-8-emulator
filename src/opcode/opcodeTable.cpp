//
// Created by RageZ on 16/01/2026.
//

#include "opcodeTable.h"
class opcodeTable::opcodeTable() {

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
    table[0xC] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Cnnn(core, opcode); };
    table[0xD] = [](chip8Core& core, uint16_t opcode) {instructions::OP_Dnnn(core, opcode); };
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

    }
}