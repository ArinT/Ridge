#include <map>
#include <string>
#include <SDL2/SDL2.h>
#include <stdexcept>

#include "texture_manager.h"
#include "base_texture.h"

using std::map;
using std::string;
using std::pair;

TextureManager::TextureManager(SDL_Renderer* renderer) :
    renderer(renderer) { }

TextureManager::~TextureManager() {
    for (
        map<string, BaseTexture*>::iterator it=texture_map.begin();
        it!=texture_map.end(); 
        ++it
    ) { 
        delete *it;
    }
}

BaseTexture* TextureManager::fetch_texture(string path) {
    try {
        return texture_map.at(path);
    } catch (const std::out_of_range& oor) {
        BaseTexture* t = new BaseTexture(renderer, path);
        texture_map.insert(path, t);
        return t;
    }
}