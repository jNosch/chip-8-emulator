//
// Created by Janos on 13.01.2026.
//

#ifndef CHI_8_PROJECT_INSTRUCTIONS_H
#define CHI_8_PROJECT_INSTRUCTIONS_H
#include "chip8Core.h"


class instructions {
    void OP_00E0(chip8Core& core); //clear screen
    void OP_00EE(chip8Core& core); //return from subroutine
    void OP_1nnn(chip8Core& core); //Jump to location nnn
};


#endif //CHI_8_PROJECT_INSTRUCTIONS_H