#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <iostream>

#include "sdl.h"
#include "game_model_view.h"

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

GameModelView* game_model_view;

void init() {
    game_model_view = new GameModelView();
}

int main(int argc, char **argv) {
    try {
        SDLWrapper* sdl = new SDLWrapper(
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_INIT_VIDEO|SDL_INIT_TIMER
        );
        bool exit = false;
        SDL_Event e;
        init();
        while(!exit) {
            while( SDL_PollEvent( &e ) != 0 ) {
                if( e.type == SDL_QUIT ) {
                    exit = true;
                }
                sdl->main_window->handle_event(&e);

            }
            //SDL_SetRenderTarget(sdl->get_renderer(), NULL);
            SDL_SetRenderDrawColor( sdl->get_renderer(), 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( sdl->get_renderer() );
            // Render model
            
            SDL_RenderPresent(sdl->get_renderer());
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

