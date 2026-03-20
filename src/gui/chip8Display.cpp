//
// Created by RageZ on 14/11/2025.
//

#include "Chip8Display.h"


Chip8Display::Chip8Display(int scale): scale(scale), window(nullptr), renderer(nullptr), texture(nullptr) {


    Chip8Display::~Chip8Display(); {
        if (texture) SDL_DestroyTexture(texture);
        if (renderer) SDL_DestroyRenderer(renderer);
        if (window) SDL_DestroyWindow(window);

        SDL_Quit();
    }
}