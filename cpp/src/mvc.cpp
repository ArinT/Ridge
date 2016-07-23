#include "game_state.h"
#include "sdl.h"
#include "controller.h"
#include "mvc.h"

RidgeMVC::RidgeMVC(int width, int height) {
    sdl = new SDLWrapper(
        width,
        height,
        SDL_INIT_VIDEO|SDL_INIT_TIMER
    );
    game_state = new GameState();
    controller = new Controller(sdl, game_state);
}

RidgeMVC::~RidgeMVC() {
    delete game_state;
    delete controller;
    delete sdl;
}

bool RidgeMVC::handle_events() {
    return controller->handle_events();
}

void RidgeMVC::update_view() {
    sdl->clear_view();
    game_state->draw(sdl->get_texture_manager());
    sdl->update_view();
}
