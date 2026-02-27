//
// Created by RageZ on 16/01/2026.
//

#ifndef CHI_8_PROJECT_OPCODETABLE_H
#define CHI_8_PROJECT_OPCODETABLE_H


#include <cstdint>
#include <functional>


class Chip8Core;

class OpcodeTable {
public:
    OpcodeTable();
    void execute(Chip8Core& core, uint16_t opcode);

private:
    using InstructionFunction = std::function<void(Chip8Core&, uint16_t)>;

    InstructionFunction table[16];

    InstructionFunction table0[16];
    InstructionFunction table8[16];
    InstructionFunction tableE[16];
    InstructionFunction tableF[256];

    void Table0(Chip8Core& core, uint16_t opcode);
    void Table8(Chip8Core& core, uint16_t opcode);
    void TableE(Chip8Core& core, uint16_t opcode);
    void TableF(Chip8Core& core, uint16_t opcode);

    void OP_NULL(Chip8Core& core, uint16_t opcode);
};


#endif //CHI_8_PROJECT_OPCODETABLE_H
