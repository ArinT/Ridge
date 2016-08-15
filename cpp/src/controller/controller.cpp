#include "sdl.h"
#include "game_state.h"
#include "controller.h"

Controller::Controller(SDLWrapper*& sdl_ptr, GameState*& game_state_ptr) {
    sdl = sdl_ptr;
    game_state = game_state_ptr;
}

Controller::~Controller() {
    sdl = NULL;
    game_state = NULL;
}

bool Controller::quit_event(SDL_Event &e) {
    return e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE || (e.key.keysym.sym == SDLK_c && e.key.keysym.mod == KMOD_LCTRL);
}

bool Controller::handle_events() {
    SDL_Event e;
    bool exit = false;
    while( SDL_PollEvent( &e ) != 0 ) {
        if(quit_event(e)) {
            SDL_Log("Program quit after %i ticks", e.quit.timestamp);
            exit = true;
        }
		const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
		if( currentKeyStates[ SDL_SCANCODE_UP ] ) {
            game_state->cursor_up();
		} else if( currentKeyStates[ SDL_SCANCODE_DOWN ] ) {
            game_state->cursor_down();
		} else if( currentKeyStates[ SDL_SCANCODE_LEFT ] ) {
            game_state->cursor_left();
		} else if( currentKeyStates[ SDL_SCANCODE_RIGHT ] ) {
            game_state->cursor_right();
		} else if ( currentKeyStates[ SDL_SCANCODE_Z ] ) {
            game_state->confirm();
        } else if ( currentKeyStates[ SDL_SCANCODE_X ] ) {
            game_state->confirm();
        }
    }
    return exit;
}
