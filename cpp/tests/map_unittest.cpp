#include "gtest/gtest.h"
#include <string>
#include <vector>
#include <set>

#define TEST_MAP_FRIENDS \
    friend class MapTest_BasicConstructor_Test;

#include "map.h"
#include "sub_tile.h"
#include "greaser_unit.h"
#include "constants.h"

class MapTest : public testing::Test {
    protected:
        virtual void SetUp() {
            map = new Map(32, 18);
        }
        virtual void TearDown() {
            delete map;
        }
        bool all_tiles_adjacent(vector<Tile*> tiles) {
            for (int i = 1; i < int(tiles.size()); i++) {
                if (tiles[i-1]->manhattan_distance(tiles[i]) != 1) {
                    return false;
                }
            }
            return true;
        }
        Map* map;
};
class NodeTest : public testing::Test {};

TEST_F(MapTest, BasicConstructor) {
    EXPECT_EQ(32, map->tile_matrix.size());
    EXPECT_EQ(18, map->tile_matrix[0].size());
    EXPECT_EQ(Constants::Team::Sharks, map->get_turn());
}

TEST_F(MapTest, LayTile) {
    map->lay_tile('S', 1, 3);
    Tile* t  = map->get_tile(1, 3);
    EXPECT_EQ(t->get_defense(), 0);
    EXPECT_EQ(t->get_img_path(), "data/pixel_art/tcr.png");
}

TEST_F(MapTest, GenerateFromAscii) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Tile* t = map->get_tile(0, 0);
    EXPECT_EQ(t->get_img_path(), "data/pixel_art/rd.png"); 
    Tile* s = map->get_tile(2, 15);
    EXPECT_EQ(s->get_img_path(), "data/pixel_art/gs.png");
    Tile* r = map->get_tile(15, 2);
    EXPECT_EQ(r->get_img_path(), "data/pixel_art/rd.png"); 
    s = NULL;
    t = NULL;
    r = NULL;
}

TEST_F(MapTest, AddUnitSuccess) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Unit* g = new GreaserUnit(1, 1, Constants::Team::Sharks);
    map->add_unit(g);
    EXPECT_EQ(g, map->unit_at(1, 1));
}

TEST_F(MapTest, RemoveUnitSuccess) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Unit* g = new GreaserUnit(1, 1, Constants::Team::Sharks);
    map->add_unit(g);
    EXPECT_EQ(g, map->unit_at(1, 1));
    map->remove_unit(g);
    EXPECT_EQ(NULL, map->unit_at(1, 1));
}

TEST_F(MapTest, IsOccupiedPositive) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Unit* g = new GreaserUnit(1, 1, Constants::Team::Sharks);
    map->add_unit(g);
    EXPECT_TRUE(map->is_occupied(1, 1));
}

TEST_F(MapTest, IsOccupiedNegativeNonInitializedTile) {
    EXPECT_FALSE(map->is_occupied(1, 1));
}

TEST_F(MapTest, IsOccupiedNegative) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    EXPECT_FALSE(map->is_occupied(1, 1));
}

TEST_F(MapTest, IsEnemyOccupiedPositive) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Unit* g = new GreaserUnit(1, 1, Constants::Team::Sharks);
    map->add_unit(g);
    EXPECT_TRUE(map->is_enemy_occupied(1, 1, Constants::Team::Jets));
}

TEST_F(MapTest, IsEnemyOccupiedNegative) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Unit* g = new GreaserUnit(1, 1, Constants::Team::Jets);
    map->add_unit(g);
    EXPECT_FALSE(map->is_enemy_occupied(1, 1, Constants::Team::Jets));
}

TEST_F(MapTest, OutOfBoundsPositiveHigh) {
    EXPECT_TRUE(map->out_of_bounds(43, 10));
}

TEST_F(MapTest, OutOfBoundsPositiveLow) {
    EXPECT_TRUE(map->out_of_bounds(22, -1));
}

TEST_F(MapTest, OutOfBoundsNegative) {
    EXPECT_FALSE(map->out_of_bounds(22, 10));
}

TEST_F(MapTest, CanGoToPositive) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    EXPECT_TRUE(map->can_go_to(1, 1));
}

TEST_F(MapTest, CanGoToNegativeOutOfBounds) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    EXPECT_FALSE(map->can_go_to(1, -1));
}

TEST_F(MapTest, CanGoToNegativeOccupied) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Unit* g = new GreaserUnit(1, 1, Constants::Team::Jets);
    map->add_unit(g);
    EXPECT_FALSE(map->can_go_to(1, 1));
}

TEST_F(MapTest, CanGoToNegativeInaccessible) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    EXPECT_FALSE(map->can_go_to(7, 7));
}

TEST_F(MapTest, CanGoThroughPositive) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Unit* g = new GreaserUnit(1, 1, Constants::Team::Jets);
    map->add_unit(g);
    EXPECT_TRUE(map->can_go_through(1, 1, Constants::Team::Jets));
}
TEST_F(MapTest, CanGoThroughNegative) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Unit* g = new GreaserUnit(1, 1, Constants::Team::Jets);
    map->add_unit(g);
    EXPECT_FALSE(map->can_go_through(1, 1, Constants::Team::Sharks));
}

TEST_F(NodeTest, Basic) {
    Tile* t1 = new ConcreteTile(1, 1);
    Node* n1 = new Node(t1, NULL, 1);
    std::vector<Tile*> path = n1->retrace_path();
    EXPECT_EQ(path[0], t1);
    delete n1;
    delete t1;
}

TEST_F(NodeTest, Advanced) {
    Tile* t1 = new ConcreteTile(1, 1);
    Tile* t2 = new ConcreteTile(1, 1);
    Tile* t3 = new ConcreteTile(1, 1);
    Node* n1 = new Node(t1, NULL, 1);
    Node* n2 = new Node(t2, n1, 1);
    Node* n3 = new Node(t3, n2, 1);
    std::vector<Tile*> path = n3->retrace_path();
    EXPECT_EQ(path[0], t1);
    EXPECT_EQ(path[1], t2);
    EXPECT_EQ(path[2], t3);
    n3->destroy_path();
    delete t1; delete t2; delete t3;
}

TEST_F(NodeTest, TileInSetPositive) {
    Tile* t1 = new ConcreteTile(1, 1);
    Tile* t2 = new ConcreteTile(1, 1);
    Node* n1 = new Node(t1, NULL, 1);
    Node* n2 = new Node(t2, n1, 1);
    std::set<Node*> s;
    s.insert(n1);
    s.insert(n2);
    EXPECT_TRUE(n1->tile_in_set(s));
    n2->destroy_path();
    delete t1; delete t2;
} 

TEST_F(NodeTest, TileInSetNegative) {
    Tile* t1 = new ConcreteTile(1, 1);
    Tile* t2 = new ConcreteTile(1, 1);
    Tile* t3 = new ConcreteTile(1, 1);
    Node* n1 = new Node(t1, NULL, 1);
    Node* n2 = new Node(t2, n1, 1);
    Node* n3 = new Node(t3, n2, 1);
    std::set<Node*> s;
    s.insert(n1);
    s.insert(n2);
    EXPECT_FALSE(n3->tile_in_set(s));
    n3->destroy_path();
    delete t1; delete t2; delete t3;
}

TEST_F(MapTest, GetMin) {
    Node* n1 = new Node(NULL, NULL, 3);
    Node* n2 = new Node(NULL, n1, 1);
    Node* n3 = new Node(NULL, n2, 2);
    std::set<Node*> s;
    s.insert(n1);
    s.insert(n2);
    s.insert(n3);
    EXPECT_EQ(Node::get_min(s), n2);
    n3->destroy_path();
}

TEST_F(MapTest, GetNeighboringTilesBasic) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Tile* t1 = map->get_tile(2,2);
    std::vector<Tile*> neighbors = map->get_neighboring_tiles(t1, Constants::Team::Sharks);
    EXPECT_EQ(neighbors[0], map->get_tile(3,2));
    EXPECT_EQ(neighbors[1], map->get_tile(1,2));
    EXPECT_EQ(neighbors[2], map->get_tile(2,3));
    EXPECT_EQ(neighbors[3], map->get_tile(2,1));
}

TEST_F(MapTest, GetNeighboringTilesSomeInaccessible) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Tile* t1 = map->get_tile(12, 11);
    std::vector<Tile*> neighbors = map->get_neighboring_tiles(t1, Constants::Team::Sharks);
    EXPECT_EQ(neighbors[0], map->get_tile(13,11));
    EXPECT_EQ(neighbors[1], map->get_tile(12,10));
}

TEST_F(MapTest, GetNeighboringTilesSomeBlocked) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Tile* t1 = map->get_tile(2,2);
    Unit* g1 = new GreaserUnit(1, 2, Constants::Team::Jets);
    Unit* g2 = new GreaserUnit(2, 1, Constants::Team::Jets);
    map->add_unit(g1);
    map->add_unit(g2);
    std::vector<Tile*> neighbors = map->get_neighboring_tiles(t1, Constants::Team::Sharks);
    EXPECT_EQ(neighbors[0], map->get_tile(3,2));
    EXPECT_EQ(neighbors[1], map->get_tile(2,3));
}

TEST_F(MapTest, AStarBasicSuccess) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Tile* t1 = map->get_tile(1,2);
    Tile* t2 = map->get_tile(5,2);
    vector<Tile*> path = map->a_star(t1, t2, Constants::Team::Sharks);
    EXPECT_EQ(5, int(path.size()));
    EXPECT_TRUE(all_tiles_adjacent(path));
}

TEST_F(MapTest, AStarBasicFail) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Tile* t1 = map->get_tile(1,2);
    Tile* t2 = map->get_tile(16,2);
    vector<Tile*> path = map->a_star(t1, t2, Constants::Team::Sharks);
    EXPECT_EQ(0, int(path.size()));
}

TEST_F(MapTest, AStarObstructedByWallSuccess) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Tile* t1 = map->get_tile(10,14);
    Tile* t2 = map->get_tile(12,11);
    vector<Tile*> path = map->a_star(t1, t2, Constants::Team::Sharks);
    EXPECT_EQ(8, int(path.size()));
    EXPECT_TRUE(all_tiles_adjacent(path));
}

TEST_F(MapTest, AStarObstructedByEnemySuccess) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Tile* t1 = map->get_tile(0,0);
    Tile* t2 = map->get_tile(4,0);
    GreaserUnit* g1 = new GreaserUnit(1,0, Constants::Team::Jets);
    GreaserUnit* g2 = new GreaserUnit(1,1, Constants::Team::Jets);
    GreaserUnit* g3 = new GreaserUnit(3,1, Constants::Team::Jets);
    GreaserUnit* g4 = new GreaserUnit(3,2, Constants::Team::Jets);
    map->add_unit(g1);
    map->add_unit(g2);
    map->add_unit(g3);
    map->add_unit(g4);
    vector<Tile*> path = map->a_star(t1, t2, Constants::Team::Sharks);
    EXPECT_EQ(9, int(path.size()));
    EXPECT_TRUE(all_tiles_adjacent(path));
}

TEST_F(MapTest, AStarObstructedByEnemyFail) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Tile* t1 = map->get_tile(0,0);
    Tile* t2 = map->get_tile(4,0);
    GreaserUnit* g1 = new GreaserUnit(3,0, Constants::Team::Jets);
    GreaserUnit* g2 = new GreaserUnit(3,1, Constants::Team::Jets);
    GreaserUnit* g3 = new GreaserUnit(3,2, Constants::Team::Jets);
    GreaserUnit* g4 = new GreaserUnit(2,3, Constants::Team::Jets);
    GreaserUnit* g5 = new GreaserUnit(1,3, Constants::Team::Jets);
    GreaserUnit* g6 = new GreaserUnit(0,3, Constants::Team::Jets);
    map->add_unit(g1);
    map->add_unit(g2);
    map->add_unit(g3);
    map->add_unit(g4);
    map->add_unit(g5);
    map->add_unit(g6);
    vector<Tile*> path = map->a_star(t1, t2, Constants::Team::Sharks);
    EXPECT_EQ(0, int(path.size()));
}

TEST_F(MapTest, AStarObstructedByWallFail) {
    map->generate_from_ascii("data/maps/TheBlockDivide.txt");
    Tile* t1 = map->get_tile(13,0);
    Tile* t2 = map->get_tile(15,0);
    vector<Tile*> path = map->a_star(t1, t2, Constants::Team::Sharks);
    EXPECT_EQ(0, int(path.size()));
}

TEST_F(MapTest, AStarVeryLongSuccess) {
    map->generate_from_ascii("data/maps/TheBlock.txt");
    Tile* t1 = map->get_tile(0,0);
    Tile* t2 = map->get_tile(31,17);
    vector<Tile*> path = map->a_star(t1, t2, Constants::Team::Sharks, 100);
    EXPECT_EQ(75, int(path.size()));
    EXPECT_TRUE(all_tiles_adjacent(path));
}

TEST_F(MapTest, AStarVeryLongFail) {
    map->generate_from_ascii("data/maps/TheBlockDivide.txt");
    Tile* t1 = map->get_tile(0,0);
    Tile* t2 = map->get_tile(31,17);
    vector<Tile*> path = map->a_star(t1, t2, Constants::Team::Sharks, 100);
    EXPECT_EQ(0, int(path.size()));
}
