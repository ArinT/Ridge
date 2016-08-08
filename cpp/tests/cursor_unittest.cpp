#include "gtest/gtest.h"
#include <tuple>
#include "cursor.h"

class CursorTest : public testing::Test {
};

TEST_F(CursorTest, SuccessfulMoveUp) {
    Cursor* cursor = new Cursor(5, 5, 32, 18);
    EXPECT_TRUE(cursor->move_up());
    std::tuple<int, int> pos = cursor->get_position();
    EXPECT_EQ(5, std::get<0>(pos));
    EXPECT_EQ(4, std::get<1>(pos));
    delete cursor;
}

TEST_F(CursorTest, SuccessfulMoveDown) {
    Cursor* cursor = new Cursor(5, 5, 32, 18);
    EXPECT_TRUE(cursor->move_down());
    std::tuple<int, int> pos = cursor->get_position();
    EXPECT_EQ(5, std::get<0>(pos));
    EXPECT_EQ(6, std::get<1>(pos));
    delete cursor;
}

TEST_F(CursorTest, SuccessfulMoveRight) {
    Cursor* cursor = new Cursor(5, 5, 32, 18);
    EXPECT_TRUE(cursor->move_right());
    std::tuple<int, int> pos = cursor->get_position();
    EXPECT_EQ(6, std::get<0>(pos));
    EXPECT_EQ(5, std::get<1>(pos));
    delete cursor;
}

TEST_F(CursorTest, SuccessfulMoveLeft) {
    Cursor* cursor = new Cursor(5, 5, 32, 18);
    EXPECT_TRUE(cursor->move_right());
    std::tuple<int, int> pos = cursor->get_position();
    EXPECT_EQ(6, std::get<0>(pos));
    EXPECT_EQ(5, std::get<1>(pos));
    delete cursor;
}

TEST_F(CursorTest, FailureMoveUp) {
    Cursor* cursor = new Cursor(0, 0, 32, 18);
    EXPECT_FALSE(cursor->move_up());
    std::tuple<int, int> pos = cursor->get_position();
    EXPECT_EQ(0, std::get<0>(pos));
    EXPECT_EQ(0, std::get<1>(pos));
    delete cursor;
}

TEST_F(CursorTest, FailureMoveDown) {
    Cursor* cursor = new Cursor(31, 17, 32, 18);
    EXPECT_FALSE(cursor->move_down());
    std::tuple<int, int> pos = cursor->get_position();
    EXPECT_EQ(31, std::get<0>(pos));
    EXPECT_EQ(17, std::get<1>(pos));
    delete cursor;
}

TEST_F(CursorTest, FailureMoveRight) {
    Cursor* cursor = new Cursor(31, 17, 32, 18);
    EXPECT_FALSE(cursor->move_right());
    std::tuple<int, int> pos = cursor->get_position();
    EXPECT_EQ(31, std::get<0>(pos));
    EXPECT_EQ(17, std::get<1>(pos));
    delete cursor;
}

TEST_F(CursorTest, FailureMoveLeft) {
    Cursor* cursor = new Cursor(0, 0, 32, 18);
    EXPECT_FALSE(cursor->move_left());
    std::tuple<int, int> pos = cursor->get_position();
    EXPECT_EQ(0, std::get<0>(pos));
    EXPECT_EQ(0, std::get<1>(pos));
    delete cursor;
}
