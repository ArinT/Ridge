#include <SDL2/SDL.h>
#include <exception>
#include <string>

#include "window.h"
#include "sdl.h"

SDL_Renderer* SDLWrapper::get_renderer() {
    return main_window->renderer;
}

SDLWrapper::SDLWrapper(const int width, const int height, Uint32 flags) throw(InitError) {
    window_width = width;
    window_height = height;
    main_window = NULL;
    if (
        SDL_Init(flags) != 0 ||
        !SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1") 
    ) {
        throw InitError();
    }
    main_window = new Window(window_width, window_height);
    if (!main_window->init_window() || !main_window->init_renderer())
        throw InitError();
    SDL_SetRenderDrawColor(get_renderer(), 0xFF, 0xFF, 0xFF, 0xFF);
}

SDLWrapper::~SDLWrapper() {
    delete main_window;
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

