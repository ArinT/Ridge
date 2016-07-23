#include "sub_tile.h"
#include "gtest/gtest.h"

class SubTileTest : public testing::Test {
    protected:
        virtual void SetUp() {
            concrete_tile = new ConcreteTile(1, 1);
            special_tile = new SpecialTile(1, 1, 1);
        }
        virtual void TearDown() {
            delete concrete_tile;
            delete special_tile;
        }
        Tile* concrete_tile;
        Tile* special_tile;
};

TEST_F(SubTileTest, BasicConstructorConcrete) {
    EXPECT_EQ(1, concrete_tile->get_defense());
    EXPECT_EQ(1, concrete_tile->get_x());
    EXPECT_EQ(1, concrete_tile->get_y());
    EXPECT_EQ("data/pixel_art/cr.png", concrete_tile->get_img_path());
    EXPECT_EQ(false, concrete_tile->is_occupied());  
    EXPECT_EQ(false, concrete_tile->is_marked());  
    EXPECT_EQ(false, concrete_tile->is_attack_marked());
    EXPECT_EQ(NULL, concrete_tile->get_unit()); 
}

TEST_F(SubTileTest, BasicConstructorSpecial) {
    EXPECT_EQ(0, special_tile->get_defense());
    EXPECT_EQ(1, special_tile->get_x());
    EXPECT_EQ(1, special_tile->get_y());
    EXPECT_EQ("data/pixel_art/rtl.png", special_tile->get_img_path());
    EXPECT_EQ(false, special_tile->is_occupied());  
    EXPECT_EQ(false, special_tile->is_marked());  
    EXPECT_EQ(false, special_tile->is_attack_marked());
    EXPECT_EQ(NULL, special_tile->get_unit()); 
}
