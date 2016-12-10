#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

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
        delete (*it).second;
    }
    for (
        map<string, TTF_Font*>::iterator it=font_map.begin();
        it!=font_map.end();
        ++it
    ) {
        TTF_CloseFont((*it).second);
    }
}

BaseTexture* TextureManager::fetch_texture(string path) {
    try {
        return texture_map.at(path);
    } catch (const std::out_of_range& oor) {
        BaseTexture* t = new BaseTexture(renderer, path);
        texture_map.insert(pair<string, BaseTexture*>(path, t));
        return t;
    }
}

TTF_Font* TextureManager::fetch_font(string path) {
    try {
        return font_map.at(path);
    } catch (const std::out_of_range& oor) {
        TTF_Font* t = TTF_OpenFont(path.c_str(), 28);
        font_map.insert(pair<string, TTF_Font*>(path, t));
        return t;
    }
}
