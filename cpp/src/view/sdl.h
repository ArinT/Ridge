#ifndef RIDGE_VIEW_SDL_H
#define RIDGE_VIEW_SDL_H
#include <SDL2/SDL.h>
#include <exception>
#include <string>
#include "window.h"

class InitError: public std::exception {
    public:
        InitError();
        InitError(const std::string&);
        virtual ~InitError() throw();
        virtual const char* what() const throw();
    private:
        std::string msg;
};

class SDLWrapper {
    public:
        SDLWrapper(const int width, const int height, Uint32 flags = 0) throw(InitError);
        virtual ~SDLWrapper();
        Window* main_window;
        SDL_Renderer * get_renderer();
    private:
        int window_width;
        int window_height;
};
#endif

