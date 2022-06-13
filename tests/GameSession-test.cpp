#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "GameSession.h"


class GameSessionTest : public ::testing::Test {
protected:
    GameSession* gameSession;
    virtual void SetUp()
    {
        gameSession = new GameSession();
    }
    virtual void TearDown() {
        delete gameSession;
    }
};

TEST_F(GameSessionTest, test1) {
    
}