//
// Created by RageZ on 14/11/2025.
//

#include "Chip8Display.h"



Chip8Display::Chip8Display(int scale)
        : scale(scale), window(nullptr), renderer(nullptr), texture(nullptr) {
}

Chip8Display::~Chip8Display() {
    if (texture) SDL_DestroyTexture(texture);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);

    SDL_Quit();
}

bool Chip8Display::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return false;

    window = SDL_CreateWindow(
            "CHIP-8",
            WIDTH * scale,
            HEIGHT * scale,
            SDL_WINDOW_RESIZABLE
    );

    if (!window) return false;

    renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) return false;

    texture = SDL_CreateTexture(renderer,
                                SDL_PIXELFORMAT_ARGB8888,
                                SDL_TEXTUREACCESS_STREAMING,
                                WIDTH,
                                HEIGHT
                                );
    if (!texture) return false;

    return true;
}

void Chip8Display::render(const uint8_t *videoBuffer) {
    uint32_t  pixels[WIDTH * HEIGHT];

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        pixels[i] = videoBuffer[i]
                ? 0xFFFFFFFF
                : 0xFF000000;
    }
    SDL_UpdateTexture(
            texture,
            nullptr,
            pixels,
            WIDTH * sizeof(uint32_t)
            );

    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}


void Chip8Display::clear() {
    SDL_RenderClear(renderer);
}

bool Chip8Display::windowClose() const {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            return true;
        }
    }

    return false;
}

