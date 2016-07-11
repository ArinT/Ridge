#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <iostream>

#include "sdl.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char **argv) {
    try {
        SDLWrapper* sdl = new SDLWrapper(
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_INIT_VIDEO|SDL_INIT_TIMER
        );
        bool exit = false;
        SDL_Event e;
        while(!exit) {
            while( SDL_PollEvent( &e ) != 0 ) {
                if( e.type == SDL_QUIT ) {
                    exit = true;
                }
            }
            SDL_SetRenderTarget(sdl->main_renderer, NULL);
            SDL_RenderPresent(sdl->main_renderer);
        }
        delete sdl;
    
        return 0;
    } catch (const InitError& err) {
        std::cerr
            << "Error while initializing SDL:  "
            << err.what() << std::endl;
    }

    return 1;
}

