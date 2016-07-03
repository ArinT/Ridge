#include "gtest/gtest.h"

#define TEST_MAP_FRIENDS \
    friend class MapTest_BasicConstructor_Test;

#include "map.h"
#include "constants.h"

class MapTest : public testing::Test {
};

TEST_F(MapTest, BasicConstructor) {
    Map* map = new Map(3,3);
    EXPECT_EQ(3, map->tile_matrix.size());
    EXPECT_EQ(3, map->tile_matrix[0].size());
    EXPECT_EQ(Constants::Team::Sharks, map->get_turn());
    delete map;
}

TEST_F(MapTest, LayTile) {
} 
