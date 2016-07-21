#include <SDL2/SDL.h>
#include <exception>
#include <string>

#include "window.h"
#include "sdl.h"

#include "init_error.h"

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

void SDLWrapper::update_view() {
    SDL_SetRenderTarget(get_renderer(), NULL);
    SDL_SetRenderDrawColor(get_renderer(), 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear(get_renderer());
    SDL_RenderPresent(get_renderer());
}


