#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <set>

#include <stdio.h>

#include "constants.h"
#include "map.h"
#include "base_tile.h"
#include "base_unit.h"
#include "sub_tile.h"
#include "utils.h"

#include "texture_manager.h"

using std::vector;
using std::list;
using std::string;
using std::set;

Map::Map(int col, int row) {
    columns = col;
    rows = row;
    current_turn = Constants::Team::Sharks;
    initialize_tile_matrix();
}

Map::~Map() {
    destroy_unit_list();
    destroy_tile_matrix();
}

void Map::destroy_unit_list() {
    typedef list<Unit*>::const_iterator iterator;
    for (iterator it = unit_list.begin(), end = unit_list.end(); it != end; ++it) {
        delete *it;
    }
}

void Map::destroy_tile_matrix() {
    for (int i = 0; i < int(tile_matrix.size()) ; i++) {
        vector<Tile*> i_column = tile_matrix[i];
        for ( int j = 0; j < int(i_column.size()); j++ ) {
            delete i_column[j];
        }
    }
}

void Map::initialize_tile_matrix() {
    for (int i = 0; i < columns; i++) {
        vector<Tile*> new_column = {};
        for (int j = 0; j < rows; j++) {
            Tile* t = NULL;
            new_column.push_back(t); 
        }
        tile_matrix.push_back(new_column); 
    }
}

bool Map::add_unit(Unit* unit) {
    int x = unit->get_x();
    int y = unit->get_y();
    if (tile_matrix[x][y] == NULL || tile_matrix[x][y]->is_occupied()) {
        return false;
    }
    else {
        tile_matrix[x][y]->add_unit(unit);
        unit_list.push_back(unit);
        return true;
    }
}

bool Map::remove_unit(Unit* unit) {
    int x = unit->get_x();
    int y = unit->get_y();
    unit_list.remove(unit);
    tile_matrix[x][y]->remove_unit();
    delete unit;
    return true;
}

Tile* Map::get_tile(int x, int y) {
    return tile_matrix[x][y];
}

Unit* Map::unit_at(int x, int y) {
    return tile_matrix[x][y]->get_unit();
}


bool Map::is_occupied(int x, int y) {
    return tile_matrix[x][y] != NULL && tile_matrix[x][y]->is_occupied();
}

bool Map::is_enemy_occupied(int x, int y, Constants::Team team) {
    return is_occupied(x, y) && unit_at(x, y)->get_team() != team;
}

bool Map::is_accessible(int x, int y) {
    return tile_matrix[x][y]->is_accessible();
}

bool Map::can_go_to(int x, int y) {
    return (
        !out_of_bounds(x, y) &&
        is_accessible(x, y) &&
        !is_occupied(x, y)
    );
}

bool Map::out_of_bounds(int x, int y) {
    return x < 0 || x >= columns || y < 0 || y >= rows; 
}

bool Map::can_go_through(int x, int y, Constants::Team team) {
    return ( 
        !out_of_bounds(x, y) && 
        is_accessible(x, y) &&
        !is_enemy_occupied(x, y, team));
}

vector<Tile*> Map::a_star(Tile* start, Tile* end, Constants::Team team) {
    return a_star(start, end, team, Constants::max_movement);
}

vector<Tile*> Map::a_star(Tile* start, Tile* end, Constants::Team team, int limit) {
    int dist = start->manhattan_distance(end);
    set<Node*> open_set;
    set<Node*> closed_set;
    open_set.insert(new Node(start, NULL, dist));
    Node* current_node = NULL;
    while (!open_set.empty()) {
        current_node = Node::get_min(open_set);
        if (current_node->tile == end) {
            vector<Tile*> path = current_node->retrace_path();
            open_set.erase(open_set.find(current_node));
            delete current_node;
            Node::destroy_node_set(closed_set);
            Node::destroy_node_set(open_set);
            return path;
        }
        open_set.erase(open_set.find(current_node));
        closed_set.insert(current_node);
        vector<Tile*> neighbor_tiles = get_neighboring_tiles(current_node->tile, team);
        vector<Node*> neighbor_nodes = Node::make_nodes(neighbor_tiles, current_node, end);
        for (int i = 0; i < int(neighbor_nodes.size()); i++) {
            Node* neighbor = neighbor_nodes[i];
            if (
                !neighbor->tile_in_set(open_set) &&
                !neighbor->tile_in_set(closed_set) &&
                neighbor->score <= limit
            ) {
                    open_set.insert(neighbor); 
            } else {
                delete neighbor;
            }
            
        }
    }
    Node::destroy_node_set(closed_set);
    return vector<Tile*>();
}

void Map::generate_from_ascii(string filename) {
    string line;
    std::ifstream infile(filename);
    for (int i = 0; i < rows; i++) {
        std::getline(infile, line);
        for (int j = 0; j < columns; j++) {
            lay_tile(line[j], j, i);
        }
    }
    infile.close();
}

void Map::lay_tile(char c, int x, int y) {
    switch (c) {
        case 'R':
            tile_matrix[x][y] = new RoadTile(x, y, 0); break;
        case 'T':
            tile_matrix[x][y] = new RoadTile(x, y, 1); break;
        case 'C':
            tile_matrix[x][y] = new ConcreteTile(x, y); break;
        case 'G':
            tile_matrix[x][y] = new GrassTile(x, y); break;
        case 'W':
            tile_matrix[x][y] = new WallTile(x, y, 0); break;
        case 'S':
            tile_matrix[x][y] = new SceneryTile(x, y); break;
        case '1':
            tile_matrix[x][y] = new WallTile(x ,y, 1); break;
        case '2':
            tile_matrix[x][y] = new WallTile(x, y, 2); break;
        case '3':
            tile_matrix[x][y] = new WallTile(x, y, 3); break;
        case '4':
            tile_matrix[x][y] = new WallTile(x, y, 4); break;
        case 'V':
            tile_matrix[x][y] = new WallTile(x, y, 5); break;
        case 'D':
            tile_matrix[x][y] = new WallTile(x, y, 6); break;
        case 'F':
            tile_matrix[x][y] = new WallTile(x, y, 7); break;
        case 'A':
            tile_matrix[x][y] = new SpecialTile(x, y, 0); break;
        case 'Y':
            tile_matrix[x][y] = new SpecialTile(x, y, 1); break;
        case 'U':
            tile_matrix[x][y] = new SpecialTile(x, y, 2); break;
        case 'I':
            tile_matrix[x][y] = new SpecialTile(x, y, 3); break;
        case 'O':
            tile_matrix[x][y] = new SpecialTile(x, y, 4); break;
        case 'P':
            tile_matrix[x][y] = new SpecialTile(x, y, 5); break;
        case 'L':
            tile_matrix[x][y] = new SpecialTile(x, y, 6); break;
        case 'K':
            tile_matrix[x][y] = new SpecialTile(x, y, 7); break;
        case 'J':
            tile_matrix[x][y] = new SpecialTile(x, y, 8); break;
        default:
            tile_matrix[x][y] = new WallTile(x, y, 0); break;
    }
}

Node::Node(Tile* tile, Node* parent, int score)
    : tile(tile), parent(parent), score(score) { }
vector<Tile*> Node::retrace_path() {
    if (parent == NULL) {
        vector<Tile*> path = {tile};
        return path; 
    }
    vector<Tile*> path = this->parent->retrace_path();
    path.push_back(tile);
    return path; 
}

Node::~Node() {
    tile = NULL;
    parent = NULL;
}

void Node::destroy_path() {
    if (parent != NULL) {
        parent->destroy_path();
    }
    delete this;
}


Node* Node::get_min(set<Node*> s) {
    typedef set<Node*>::const_iterator iterator;
    Node* min_node = NULL;
    for (iterator it = s.begin(), end = s.end(); it != end; ++it) {
        Node* current = *it;
        if (min_node == NULL || min_node->score > current->score) {
            min_node = current;
        }
    }
    return min_node;
}

vector<Node*> Node::make_nodes(vector<Tile*> tiles, Node* parent,  Tile* goal) {
    vector<Node*> nodes = {};
    for (int i = 0; i < int(tiles.size()); i++) {
        nodes.push_back(new Node(tiles[i], parent, tiles[i]->manhattan_distance(goal)));
    }
    return nodes;
}

bool Node::tile_in_set(set<Node*> s) {
    for (set<Node*>::const_iterator it=s.begin(); it!=s.end(); ++it) {
        if (this->tile == (*it)->tile) {
            return true;
        }
    }
    return false;
}

void Node::destroy_node_set(set<Node*> s) {
    for (set<Node*>::const_iterator it=s.begin(); it!=s.end(); ++it) {
        Node* n = *it;
        delete n;
    }
}


vector<Tile*> Map::get_neighboring_tiles(Tile* tile, Constants::Team team) {
    vector<Tile*> neighbors = {};
    int x = tile->get_x();
    int y = tile->get_y();
    
    if (can_go_through(x + 1, y, team)) {
        neighbors.push_back(get_tile(x + 1, y));
    }
    if (can_go_through(x - 1, y, team)) {
        neighbors.push_back(get_tile(x - 1, y));
    }
    if (can_go_through(x, y + 1, team)) {
        neighbors.push_back(get_tile(x, y + 1));
    }
    if (can_go_through(x, y - 1, team)) {
        neighbors.push_back(get_tile(x, y - 1));
    }
    return neighbors;
}

bool Map::draw(TextureManager* texture_manager) {
    for (int i = 0; i < int(tile_matrix.size()) ; i++) {
        vector<Tile*> i_column = tile_matrix[i];
        for ( int j = 0; j < int(i_column.size()); j++ ) {
            Tile* t  = i_column[j];
            t->draw(texture_manager);
        }
    }
    return true;
}
