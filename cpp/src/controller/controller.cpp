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
		const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
		if( currentKeyStates[ SDL_SCANCODE_UP ] ) {
            game_state->get_cursor()->move_up();
		} else if( currentKeyStates[ SDL_SCANCODE_DOWN ] ) {
            game_state->get_cursor()->move_down();
		} else if( currentKeyStates[ SDL_SCANCODE_LEFT ] ) {
            game_state->get_cursor()->move_left();
		} else if( currentKeyStates[ SDL_SCANCODE_RIGHT ] ) {
            game_state->get_cursor()->move_right();
		}
    }
    return exit;
}
