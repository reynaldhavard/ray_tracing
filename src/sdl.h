#pragma once

#include <SDL2/SDL.h>

#include <iostream>
#include <vector>

class SDL
{
public:
    std::vector<uint32_t> frame_buffer;
    SDL(const int width, const int height);
    ~SDL();
    bool quit();
    void render();

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;
    int screen_width;
    int screen_height;
};



