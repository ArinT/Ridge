#ifndef RIDGE_MODELS_MAP_H
#define RIDGE_MODELS_MAP_H

#include <vector>
#include <list>
#include <string>
#include <set>

#include "base_unit.h"
#include "base_tile.h"
#include "constants.h"

#include "texture_manager.h"

#ifndef TEST_MAP_FRIENDS
#define TEST_MAP_FRIENDS
#endif

using std::vector;
using std::list;
using std::string;
using std::set;

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
        bool draw(TextureManager* texture_manager);
        Tile* get_tile(int x, int y);
        bool add_unit(Unit* unit);
        bool remove_unit(Unit* unit);
        Unit* unit_at(int x, int y);
        bool is_occupied(int x, int y);
        bool is_enemy_occupied(int x, int y, Constants::Team team);
        bool is_accessible(int x, int y);
        bool can_go_to(int x, int y);
        bool can_go_through(int x, int y, Constants::Team team);
        bool out_of_bounds(int x, int y);
        void lay_tile(char c, int x, int y);
        vector<Tile*> a_star(Tile* start, Tile* goal, Constants::Team team);
        vector<Tile*> a_star(Tile* start, Tile* goal, Constants::Team team, int limit);
        vector<Tile*> get_neighboring_tiles(Tile* tile, Constants::Team team); 
        void generate_from_ascii(string filename);
        Map(int col, int row);
        ~Map();
        Constants::Team get_turn() { return current_turn; };
        int get_columns() { return columns; };
        int get_rows() { return rows; };
};

class Node {
    public:
        Tile* tile;
        Node* parent;
        int score;
        Node(Tile* tile, Node* parent, int score);
        ~Node();
        void destroy_path();
        vector<Tile*> retrace_path(); 
        static Node* get_min(std::set<Node*> s);
        static void destroy_node_set(set<Node*> s);
        static vector<Node*> make_nodes(vector<Tile*> tiles, Node* parent, Tile* goal);
        bool tile_in_set(set<Node*> s);
};
#endif
