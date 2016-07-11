#ifndef RIDGE_VIEW_SDL_H
#define RIDGE_VIEW_SDL_H
#include <SDL2/SDL.h>
#include <exception>
#include <string>

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
        SDL_Window* main_window;
        SDL_Renderer* main_renderer;
    private:
        int window_width;
        int window_height;
};
#endif

