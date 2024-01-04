#include "sdl.h"

SDL::SDL(const int width, const int height) {
  screen_width = width;
  screen_height = height;
  frame_buffer.resize(screen_width * screen_height, 0);
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not initialize! SDL_ERROR: " << SDL_GetError()
              << '\n';
  } else {
    window = SDL_CreateWindow("Ray Tracing", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, screen_width,
                              screen_height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
      std::cout << "Window could not be created! SDL_ERROR: " << SDL_GetError()
                << '\n';
    } else {
      renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
      if (renderer == nullptr) {
        std::cout << "Renderer could not be created! SDL_ERROR: "
                  << SDL_GetError() << '\n';
      } else {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                                    SDL_TEXTUREACCESS_STREAMING, width, height);
        if (texture == nullptr) {
          std::cout << "Texture could not be created! SDL_ERROR: "
                    << SDL_GetError() << '\n';
        }
      }
    }
  }
}

SDL::~SDL() {
  if (texture) {
    SDL_DestroyTexture(texture);
    texture = nullptr;
  }
  if (renderer) {
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
  }
  if (window) {
    SDL_DestroyWindow(window);
    window = nullptr;
  }
  SDL_Quit();
}

bool SDL::quit() {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      return true;
    }
  }
  return false;
}

void SDL::render() {
  SDL_UpdateTexture(texture, nullptr, frame_buffer.data(),
                    screen_width * sizeof(uint32_t));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, nullptr, nullptr);
  SDL_RenderPresent(renderer);
}
