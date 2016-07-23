#include <SDL2/SDL.h>
#include <exception>
#include <string>

#include "window.h"
#include "sdl.h"
#include "texture_manager.h"

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
    texture_manager = new TextureManager(get_renderer());
}

SDLWrapper::~SDLWrapper() {
    delete main_window;
    delete texture_manager;
    SDL_Quit();
}

void SDLWrapper::clear_view() {
    SDL_SetRenderDrawColor(get_renderer(), 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear(get_renderer());
}

void SDLWrapper::update_view() {
    SDL_RenderPresent(get_renderer());
}


