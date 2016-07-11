#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <iostream>

#include "sdl.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char **argv) {
    try {
        SDLWrapper sdl(SDL_INIT_VIDEO|SDL_INIT_TIMER);
        while (true) {
        }

        return 0;
    }

    catch (const InitError& err) {
        std::cerr
            << "Error while initializing SDL:  "
            << err.what() << std::endl;
    }

    return 1;
}

