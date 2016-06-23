#include <vector>
#include <list>

#include "constants.h"
#include "map.h"
#include "base_tile.h"

using std::vector;

Map::Map(int col, int row) {
    columns = col;
    rows = row;
    current_turn = Constants::Team::Sharks;
    initialize_tile_matrix();
}
void Map::initialize_tile_matrix() {
    for (int i=0; i<rows; i++) {
        vector<Tile*> new_row = {};
        for (int j=0; j<columns; j++) {
            Tile* t = NULL;
            new_row.push_back(t);    
        }
        tile_matrix.push_back(new_row); 
    }
}
