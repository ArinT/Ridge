#ifndef RIDGE_VIEW_SDL_H
#define RIDGE_VIEW_SDL_H
#include <SDL2/SDL.h>
#include <exception>
#include <string>
#include "window.h"
#include "init_error.h"

class SDLWrapper {
    public:
        SDLWrapper(const int width, const int height, Uint32 flags = 0) throw(InitError);
        virtual ~SDLWrapper();
        Window* main_window;
        SDL_Renderer * get_renderer();
        void update_view();
    private:
        int window_width;
        int window_height;
};
#endif

