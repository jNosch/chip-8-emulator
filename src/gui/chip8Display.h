//
// Created by RageZ on 14/11/2025.
//

#ifndef CHI_8_PROJECT_CHIP8DISPLAY_H
#define CHI_8_PROJECT_CHIP8DISPLAY_H


#include <cstdint>

class chip8Display {
public:
    chip8Display(int scale = 10);
    ~chip8Display();


    bool initialize();
    void render(const uint8_t* videoBuffer);
    void clear();
    bool windowClose() const;

    static const int WIDTH = 64;
    static const int HEIGHT = 32;

private:
int scale;
//add the SDL2 stuff
};


#endif //CHI_8_PROJECT_CHIP8DISPLAY_H
