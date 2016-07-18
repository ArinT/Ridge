#ifndef RIDGE_VIEW_TEXTURE_MANAGER_H
#define RIDGE_VIEW_TEXTURE_MANAGER_H
#include <SDL2/SDL2.h>
#include <map>
#include <string>

#include "base_texture.h"

using std::map;
using std::string;

class TextureManager {
    public:
        BaseTexture* fetch_texture(string path);
        TextureManager(SDL_Renderer* renderer);
        ~TextureManager();
    private:
        map<string, BaseTexture*> texture_map;
        SDL_Renderer* renderer;
}
#endif
