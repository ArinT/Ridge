#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <iostream>

#include "sdl.h"
#include "mvc.h"

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

RidgeMVC* ridge;

void init() {
    ridge = new RidgeMVC(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void tear_down() {
    delete ridge;
}

int main(int argc, char **argv) {
    try {
        bool exit = false;
        init();
        while(!exit) {
            exit = ridge->handle_events();
            ridge->update_view();
        }
    } catch (const InitError& err) {
        std::cerr
            << "Error while initializing SDL:  "
            << err.what() << std::endl;
    }
    tear_down();

    return 0;
}

