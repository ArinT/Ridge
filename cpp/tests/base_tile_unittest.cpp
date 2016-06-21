#include "base_tile.h"
#include "gtest/gtest.h"

class BaseTileTest : public testing::Test {
    protected:
        virtual void SetUp() {
            tile = new Tile(3, "path/to/img/", true, 1, 1);
        }
        virtual void TearDown() {
            delete tile;
        }
        Tile* tile;
};

TEST_F(BaseTileTest, BasicConstructor) {
    EXPECT_EQ(3, tile->get_defense());
    EXPECT_EQ(1, tile->get_x());
    EXPECT_EQ(1, tile->get_y());
    EXPECT_EQ("path/to/img/", tile->get_img_path());
    EXPECT_EQ(false, tile->is_occupied());  
    EXPECT_EQ(false, tile->is_marked());  
    EXPECT_EQ(false, tile->is_attack_marked());
    EXPECT_EQ(NULL, tile->get_unit()); 
}

TEST_F(BaseTileTest, AddUnit) {
    Unit* unit = new Unit(6, 10, 5, 6, 7, 8, 1, 1);
    tile->add_unit(unit);
    EXPECT_EQ(unit, tile->get_unit());
    delete unit;
}
