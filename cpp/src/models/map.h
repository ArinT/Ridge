#ifndef RIDGE_MODELS_MAP_H
#define RIDGE_MODELS_MAP_H

#include <vector>
#include <list>

#include "base_unit.h"
#include "base_tile.h"
#include "constants.h"

#ifndef TEST_MAP_FRIENDS
#define TEST_MAP_FRIENDS
#endif

using std::vector;
using std::list;

class Map {
    TEST_MAP_FRIENDS;
    private:
        int rows;
        int columns;
        list<Unit*> unit_list;
        vector<vector<Tile*>> tile_matrix;
        Constants::Team current_turn;
        void initialize_tile_matrix();
        void destroy_unit_list();
        void destroy_tile_matrix(); 
    public:
        Tile* get_tile(int x, int y);
        Unit* get_unit(int x, int y);
        bool add_unit(Unit* unit);
        bool remove_unit(Unit* unit);
        Unit* unit_at(int x, int y);
        bool is_occupied(int x, int y);
        bool is_enemy_occupied(int x, int y, Constants::Team team);
        bool is_accessible(int x, int y);
        bool can_go_to(int x, int y);
        bool can_go_through(int x, int y, Constants::Team team);
        bool out_of_bounds(int x, int y);
        Map(int col, int row);
        ~Map();
        Constants::Team get_turn() { return current_turn; };
};

#endif
