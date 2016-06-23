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
        Tile get_tile(int x, int y);
        bool add_unit(Unit* unit);
        bool remove_unit(Unit* unit);
        Map(int col, int row);
        ~Map();
        Constants::Team get_turn() { return current_turn; };
};
