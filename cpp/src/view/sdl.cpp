#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <exception>
#include <string>

#include "sdl.h"

SDLWrapper::SDLWrapper(const int width, const int height, Uint32 flags) throw(InitError) {
    window_width = width;
    window_height = height;
    main_window = NULL;
    main_renderer = NULL;
    if (
        SDL_Init(flags) != 0 ||
        !SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1") 
    ) {
        throw InitError();
    }
    main_window = SDL_CreateWindow(
        "Ridge", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        window_width, 
        window_height, 
        SDL_WINDOW_SHOWN
    );
    if (main_window == NULL) {
        throw InitError();
    }
    main_renderer = SDL_CreateRenderer(
        main_window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    if (main_renderer == NULL) {
        throw InitError();
    }
    SDL_SetRenderDrawColor(main_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

SDLWrapper::~SDLWrapper() {
    SDL_DestroyRenderer(main_renderer);
    SDL_DestroyWindow(main_window);
    main_window = NULL;
    main_renderer = NULL;
    SDL_Quit();
}

InitError::InitError():
  exception(), msg(SDL_GetError()) {}
InitError::InitError(const std::string& m):
  exception(), msg(m) {}
InitError::~InitError() throw() {}
const char* InitError::what() const throw() {
    return msg.c_str();
}

