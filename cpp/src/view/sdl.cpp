#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <exception>
#include <string>

#include "sdl.h"

SDLWrapper::SDLWrapper(Uint32 flags) throw(InitError) {
    if (SDL_Init(flags) != 0)
        throw InitError();
}

SDLWrapper::~SDLWrapper() {
    SDL_Quit();
}

InitError::InitError():
  exception(), msg(SDL_GetError()) {}
InitError::InitError(const std::string& m):
  exception(), msg(m) {}
InitError::~InitError() throw() {}
const char* InitError::what() const throw() {
    return msg.c_str();
}

