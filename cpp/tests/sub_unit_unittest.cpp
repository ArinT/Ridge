#include "greaser_unit.h"
#include "base_unit.h"
#include "gtest/gtest.h"
#include "constants.h"

class SubUnitTest : public testing::Test {
    protected:
        virtual void SetUp() {
            g = new GreaserUnit(1, 1, Constants::Team::Sharks);
        }
        virtual void TearDown() {
            delete g;
        }
        Unit* g;
};

TEST_F(SubUnitTest, BasicConstructorGreaser) {
    EXPECT_EQ(6, g->get_movement_range());
}

