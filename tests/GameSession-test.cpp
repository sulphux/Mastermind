#include "gtest/gtest.h"
#include "static/GameSession.h"

TEST(blaTest, test1) {
    //arrange
    //act
    //assert
    EXPECT_EQ (GameSession::bla (0),  0);
    EXPECT_EQ (GameSession::bla (10), 20);
    EXPECT_EQ (GameSession::bla (50), 100);
}