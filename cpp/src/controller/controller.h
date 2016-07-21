#ifndef RIDGE_CONTROLLER_CONTROLLER_H
#define RIDGE_CONTROLLER_CONTROLLER_H
#include "sdl.h"
#include "game_state.h"

class Controller {
    public:
        Controller(SDLWrapper* sdl, GameState* game_state);
        ~Controller();
        bool handle_events();
    private:
        GameState* game_state;
        SDLWrapper* sdl;
};

#endif
