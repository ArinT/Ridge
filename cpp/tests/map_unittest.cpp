#include "gtest/gtest.h"
#include <string>

#define TEST_MAP_FRIENDS \
    friend class MapTest_BasicConstructor_Test;

#include "map.h"
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

TEST_F(MapTest, BasicConstructor) {
    EXPECT_EQ(32, map->tile_matrix.size());
    EXPECT_EQ(18, map->tile_matrix[0].size());
    EXPECT_EQ(Constants::Team::Sharks, map->get_turn());
}

TEST_F(MapTest, GenerateFromAscii) {
    map->generate_from_ascii("/home/arin/Desktop/Ridge/cpp/data/maps/TheBlock.txt");
    Tile* t = map->get_tile(0,0);
    EXPECT_EQ(t->get_img_path(), "pixel_art/rd.png"); 
    Tile* s = map->get_tile(15,2);
    EXPECT_EQ(s->get_img_path(), "pixel_art/gs.png");
    s = NULL;
    t = NULL;
}

TEST_F(MapTest, AddUnit) {
    
}

TEST_F(MapTest, RemoveUnit) {
    
}

TEST_F(MapTest, IsOccupied) {

}

