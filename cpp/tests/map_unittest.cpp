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
    EXPECT_EQ(t->get_img_path(), "pixel_art/tcr.png");
}

TEST_F(MapTest, GenerateFromAscii) {
    map->generate_from_ascii("/home/arin/Desktop/Ridge/cpp/data/maps/TheBlock.txt");
    Tile* t = map->get_tile(0, 0);
    EXPECT_EQ(t->get_img_path(), "pixel_art/rd.png"); 
    Tile* s = map->get_tile(2, 15);
    EXPECT_EQ(s->get_img_path(), "pixel_art/gs.png");
    Tile* r = map->get_tile(15, 2);
    EXPECT_EQ(r->get_img_path(), "pixel_art/rd.png"); 
    s = NULL;
    t = NULL;
    r = NULL;
}

TEST_F(MapTest, AddUnitSuccess) {
    map->generate_from_ascii("/home/arin/Desktop/Ridge/cpp/data/maps/TheBlock.txt");
    Unit* g = new GreaserUnit(1, 1, Constants::Team::Sharks);
    map->add_unit(g);
    EXPECT_EQ(g, map->unit_at(1, 1));
}

TEST_F(MapTest, RemoveUnitSuccess) {
    map->generate_from_ascii("/home/arin/Desktop/Ridge/cpp/data/maps/TheBlock.txt");
    Unit* g = new GreaserUnit(1, 1, Constants::Team::Sharks);
    map->add_unit(g);
    EXPECT_EQ(g, map->unit_at(1, 1));
    map->remove_unit(g);
    EXPECT_EQ(NULL, map->unit_at(1, 1));
}

TEST_F(MapTest, IsOccupiedPositive) {
    map->generate_from_ascii("/home/arin/Desktop/Ridge/cpp/data/maps/TheBlock.txt");
    Unit* g = new GreaserUnit(1, 1, Constants::Team::Sharks);
    map->add_unit(g);
    EXPECT_TRUE(map->is_occupied(1, 1));
}

TEST_F(MapTest, IsOccupiedNegativeNonInitializedTile) {
    EXPECT_FALSE(map->is_occupied(1, 1));
}

TEST_F(MapTest, IsOccupiedNegative) {
    map->generate_from_ascii("/home/arin/Desktop/Ridge/cpp/data/maps/TheBlock.txt");
    EXPECT_FALSE(map->is_occupied(1, 1));
}

TEST_F(MapTest, IsEnemyOccupiedPositive) {
    map->generate_from_ascii("/home/arin/Desktop/Ridge/cpp/data/maps/TheBlock.txt");
    Unit* g = new GreaserUnit(1, 1, Constants::Team::Sharks);
    map->add_unit(g);
    EXPECT_TRUE(map->is_enemy_occupied(1, 1, Constants::Team::Jets));
}

TEST_F(MapTest, IsEnemyOccupiedNegative) {
    map->generate_from_ascii("/home/arin/Desktop/Ridge/cpp/data/maps/TheBlock.txt");
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
    map->generate_from_ascii("/home/arin/Desktop/Ridge/cpp/data/maps/TheBlock.txt");
    EXPECT_TRUE(map->can_go_to(1, 1));
}

TEST_F(MapTest, CanGoToNegativeOutOfBounds) {
    map->generate_from_ascii("/home/arin/Desktop/Ridge/cpp/data/maps/TheBlock.txt");
    EXPECT_FALSE(map->can_go_to(1, -1));
}

TEST_F(MapTest, CanGoToNegativeOccupied) {
    map->generate_from_ascii("/home/arin/Desktop/Ridge/cpp/data/maps/TheBlock.txt");
    Unit* g = new GreaserUnit(1, 1, Constants::Team::Jets);
    map->add_unit(g);
    EXPECT_FALSE(map->can_go_to(1, 1));
}

TEST_F(MapTest, CanGoToNegativeInaccessible) {
    map->generate_from_ascii("/home/arin/Desktop/Ridge/cpp/data/maps/TheBlock.txt");
    EXPECT_FALSE(map->can_go_to(7, 7));
}

TEST_F(MapTest, CanGoThroughPositive) {
    map->generate_from_ascii("/home/arin/Desktop/Ridge/cpp/data/maps/TheBlock.txt");
    Unit* g = new GreaserUnit(1, 1, Constants::Team::Jets);
    map->add_unit(g);
    EXPECT_TRUE(map->can_go_through(1, 1, Constants::Team::Jets));
}
TEST_F(MapTest, CanGoThroughNegative) {
    map->generate_from_ascii("/home/arin/Desktop/Ridge/cpp/data/maps/TheBlock.txt");
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
    delete n3;
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
    delete n1; delete n2; delete n3;
}
