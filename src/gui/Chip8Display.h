//
// Created by RageZ on 14/11/2025.
//

#ifndef CHI_8_PROJECT_CHIP8DISPLAY_H
#define CHI_8_PROJECT_CHIP8DISPLAY_H


#include <cstdint>
#include <SDL3/SDL.h>

class Chip8Display {
public:
    Chip8Display(int scale = 10);
    ~Chip8Display();


    bool initialize();
    void render(const uint8_t* videoBuffer);
    void clear();
    bool windowClose() const;

    static const int WIDTH = 64;
    static const int HEIGHT = 32;

private:
int scale;


SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* texture;
};


#endif //CHI_8_PROJECT_CHIP8DISPLAY_H
