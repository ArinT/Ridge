#include "sdl.h"
#include "game_state.h"
#include "controller.h"

Controller::Controller(SDLWrapper* sdl, GameState* game_state) {
    sdl = sdl;
    game_state = game_state; 
}

Controller::~Controller() {
    sdl = NULL;
    game_state = NULL;
}

bool Controller::handle_events() {
    SDL_Event e;
    bool exit = false;
    while( SDL_PollEvent( &e ) != 0 ) {
        if( e.type == SDL_QUIT ) {
            exit = true;
        }
    }
    return exit;
}
