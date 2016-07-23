#ifndef RIDGE_TILES_BASE_H
#define RIDGE_TILES_BASE_H
#include <string>

#include "base_unit.h"

#include "texture_manager.h"
#include "base_texture.h"

class Tile {
    public:
        Tile(
            int defense, 
            std::string img_path, 
            bool accessible, 
            int x, 
            int y
        );
        ~Tile();
        int manhattan_distance(Tile* dest);
        bool remove_unit();
        bool add_unit(Unit *unit);
        int get_defense() { return defense; } 
        int get_x() { return x; } 
        int get_y() { return y; }
        std::string get_img_path() { return img_path; }
        bool is_accessible() { return accessible; }
        bool is_occupied(); 
        bool is_marked() { return marked; }
        bool is_attack_marked() { return attack_marked; }
        void draw(TextureManager* texture_manager);
        Unit* get_unit() { return unit; } 
    protected:
        BaseTexture* texture;
        int defense;
        std::string img_path;
        bool accessible;
        int x;
        int y;
        Unit *unit;
        bool marked;
        bool attack_marked;
};
#endif
