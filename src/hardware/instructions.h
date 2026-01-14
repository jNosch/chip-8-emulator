//
// Created by Janos on 13.01.2026.
//

#ifndef CHI_8_PROJECT_INSTRUCTIONS_H
#define CHI_8_PROJECT_INSTRUCTIONS_H
#include "chip8Core.h"

class chip8Core;

class instructions {
    static void OP_00E0(chip8Core& core); //clear screen
    static void OP_00EE(chip8Core& core); //return from subroutine
    static void OP_1nnn(chip8Core& core, uint16_t nnn); //Jump to location nnn
    static void OP_2nnn(chip8Core& core, uint16_t nnn); //Call subroutine at nnn
    static void OP_3xkk(chip8Core& core, uint8_t x, uint16_t kk); //Skip next instruction if Vx = kk
    static void OP_4xkk(chip8Core& core, uint8_t x, uint16_t kk); //Skip next instruction if Vx
    static void OP_5xy0(chip8Core& core, uint8_t x, uint16_t y); //Skip next instruction if Vx = Vy
    static void OP_6xkk(chip8Core& core, uint8_t x, uint16_t kk); //Set Vx = kk
    static void OP_7xkk(chip8Core& core, uint8_t x, uint16_t kk); //Set Vx = Vx + kk
    static void OP_8xy0(chip8Core& core, uint8_t x, uint8_t y); //Set vx = Vy
    static void OP_8xy1(chip8Core& core, uint8_t x, uint8_t y); //Set Vx = Vx OR Vy
    static void OP_8xy2(chip8Core& core,  uint8_t x, uint8_t y); // Set Vx = Vx AND Vy
    static void OP_8xy3(chip8Core& core,  uint8_t x, uint8_t y); //Set Vx = Vx XOR Vy
    static void OP_8xy4(chip8Core& core,  uint8_t x, uint8_t y); //Set Vx = Vx + Vy, set VF = carry.
    static void OP_8xy5(chip8Core& core,  uint8_t x, uint8_t y); //Set Vx  = Vx - Vy, set Vf = NOT borrow
    static void OP_8xy6(chip8Core& core,  uint8_t x, uint8_t y); //Set Vx = Vx SHR 1.
    static void OP_8xy7(chip8Core& core,  uint8_t x, uint8_t y); //Set Vx = Vy - Vx, set VF = NOT borrow
    static void OP_8xyE(chip8Core& core,  uint8_t x, uint8_t y); //Set Vx = Vx SHL 1.
    static void OP_9xy0(chip8Core& core,  uint8_t x, uint8_t y); //Skip next instruction if Vx != Vy.
    static void OP_Annn(chip8Core& core, uint16_t nnn); //Set I = nnn
    static void OP_Bnnn(chip8Core& core, uint16_t nnn); //Jump to location nnn + V0
    static void OP_Cxkk(chip8Core& core, uint8_t x, uint8_t kk); //Set Vx = random byte AND kk
    static void OP_Dxyn(chip8Core& core, uint8_t x, uint8_t y, uint8_t n); //Display the n-yte sprite starting at memory loation 1 at (Vx, Vy), set VF = collision
};


#endif //CHI_8_PROJECT_INSTRUCTIONS_H