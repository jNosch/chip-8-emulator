//
// Created by Janos on 13.01.2026.
//

#ifndef CHI_8_PROJECT_INSTRUCTIONS_H
#define CHI_8_PROJECT_INSTRUCTIONS_H
#include "../hardware/Chip8Core.h"

class Chip8Core;

class Instructions {
public:
    static void OP_00E0(Chip8Core& core); //clear screen
    static void OP_00EE(Chip8Core& core); //return from subroutine
    static void OP_1nnn(Chip8Core& core, uint16_t opcode); //Jump to location nnn
    static void OP_2nnn(Chip8Core& core, uint16_t opcode); //Call subroutine at nnn
    static void OP_3xkk(Chip8Core& core, uint16_t opcode);//Skip next instruction if Vx = kk
    static void OP_4xkk(Chip8Core& core, uint16_t opcode); //Skip next instruction if Vx
    static void OP_5xy0(Chip8Core& core, uint16_t opcode); //Skip next instruction if Vx = Vy
    static void OP_6xkk(Chip8Core& core, uint16_t opcode); //Set Vx = kk
    static void OP_7xkk(Chip8Core& core, uint16_t opcode); //Set Vx = Vx + kk
    static void OP_8xy0(Chip8Core& core, uint16_t opcode); //Set Vx = Vy
    static void OP_8xy1(Chip8Core& core, uint16_t opcode); //Set Vx = Vx OR Vy
    static void OP_8xy2(Chip8Core& core, uint16_t opcode); // Set Vx = Vx AND Vy
    static void OP_8xy3(Chip8Core& core, uint16_t opcode); //Set Vx = Vx XOR Vy
    static void OP_8xy4(Chip8Core& core, uint16_t opcode); //Set Vx = Vx + Vy, set VF = carry.
    static void OP_8xy5(Chip8Core& core, uint16_t opcode); //Set Vx  = Vx - Vy, set Vf = NOT borrow
    static void OP_8xy6(Chip8Core& core, uint16_t opcode); //Set Vx = Vx SHR 1.
    static void OP_8xy7(Chip8Core& core, uint16_t opcode); //Set Vx = Vy - Vx, set VF = NOT borrow
    static void OP_8xyE(Chip8Core& core, uint16_t opcode); //Set Vx = Vx SHL 1.
    static void OP_9xy0(Chip8Core& core, uint16_t opcode); //Skip next instruction if Vx != Vy.
    static void OP_Annn(Chip8Core& core, uint16_t opcode); //Set I = nnn
    static void OP_Bnnn(Chip8Core& core, uint16_t opcode); //Jump to location nnn + V0
    static void OP_Cxkk(Chip8Core& core, uint16_t opcode); //Set Vx = random byte AND kk
    static void OP_Dxyn(Chip8Core& core, uint16_t opcode); //Display the n-yte sprite starting at memory loation I at (Vx, Vy), set VF = collision
    static void OP_Ex9E(Chip8Core& core, uint16_t opcode); //Skip next instruction if key with the value of Vx is pressed
    static void OP_ExA1(Chip8Core& core, uint16_t opcode); //Skip next instruction if key with the value of Vx is pressed
    static void OP_Fx07(Chip8Core& core, uint16_t opcode); //Set Vx = delay timer value
    static void OP_Fx0A(Chip8Core& core, uint16_t opcode);//Wait for a key press, store the value of the key in Vx
    static void OP_Fx15(Chip8Core& core, uint16_t opcode); //Set delay timer = Vx
    static void OP_Fx18(Chip8Core& core, uint16_t opcode);//Set sound timer = Vx
    static void OP_Fx1E(Chip8Core& core, uint16_t opcode); //Set I = I + Vx
    static void OP_Fx29(Chip8Core& core, uint16_t opcode); //Set I = Location of sprite for digit Vx
    static void OP_Fx33(Chip8Core& core, uint16_t opcode); //Store BCD representation of Vx in memory Locations I, I+1, and I+2
    static void OP_Fx55(Chip8Core& core, uint16_t opcode); //Store registers V0 through Vx in memory starting at location I
    static void OP_Fx65(Chip8Core& core, uint16_t opcode); //Read registers V0 through Vx from memory starting at location I
};


#endif //CHI_8_PROJECT_INSTRUCTIONS_H