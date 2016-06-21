#include "base_unit.h"
#include "gtest/gtest.h"

TEST(BaseUnitTest, BasicConstructor) {
    Unit* unit = new Unit(6, 10, 5, 6, 7, 8, 1, 1);
    EXPECT_EQ(6, unit->get_movement_range());
    EXPECT_EQ(10, unit->get_hp());
    EXPECT_EQ(10, unit->get_max_hp());
    EXPECT_EQ(5, unit->get_strength());
    EXPECT_EQ(6, unit->get_finesse());
    EXPECT_EQ(7, unit->get_wit());
    EXPECT_EQ(8, unit->get_style());
    EXPECT_EQ(1, unit->get_x());
    EXPECT_EQ(1, unit->get_y());
    
    delete unit;
    
}
