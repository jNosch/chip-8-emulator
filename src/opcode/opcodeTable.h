//
// Created by RageZ on 16/01/2026.
//

#ifndef CHI_8_PROJECT_OPCODETABLE_H
#define CHI_8_PROJECT_OPCODETABLE_H


#include <cstdint>
#include <functional>


class chip8Core;

class opcodeTable {
public:
    opcodeTable();
    void execute(chip8Core& core, uint16_t opcode);

private:
    using InstructionFunction = std::function<void(chip8Core&, uint16_t)>;

    InstructionFunction table[16];

    InstructionFunction table0[16];
    InstructionFunction table8[16];
    InstructionFunction tableE[16];
    InstructionFunction tableF[256];

    void Table0(chip8Core& core, uint16_t opcode);
    void Table8(chip8Core& core, uint16_t opcode);
    void TableE(chip8Core& core, uint16_t opcode);
    void TableF(chip8Core& core, uint16_t opcode);

    void OP_NULL(chip8Core& core, uint16_t opcode);
};


#endif //CHI_8_PROJECT_OPCODETABLE_H
