#include <iostream>
#include <vector>

#include "gtest/gtest.h"

#include "Code.h"
#include "CodeFactory.h"
#include "Suggestion.h"
#include "Arbiter.h"

class ArbiterTest : public ::testing::Test {
protected:
    Arbiter* _arbiter;
    const std::string CODE_TO_TEST_STR = "2531";
    const std::string CODE_TO_TEST_STR_REVERSED = "1352";

    ArbiterTest() {
        _arbiter = new Arbiter();
        _arbiter->rememberCodeToGuess(CodeFactory::createCodeFromString(CODE_TO_TEST_STR));
    }
    ~ArbiterTest() {
        if(_arbiter != nullptr)
            delete _arbiter;
    }
    virtual void SetUp()
    {

    }
    virtual void TearDown() {}

    virtual void scenario(std::string guessedCodeStr, int expectedAtPosition, int expectedNotAtPosition) {
        Suggestion suggestion = _arbiter->makeNewSuggestionFromNewCode(CodeFactory::createCodeFromString(guessedCodeStr));

        EXPECT_EQ(expectedAtPosition, suggestion.getAtPositionAmount());
        EXPECT_EQ(expectedNotAtPosition, suggestion.getNotAtPositionAmount());
    }
};

TEST_F(ArbiterTest, guessingTestsOneOnOne) {
    scenario("1634", 1, 1);
}

TEST_F(ArbiterTest, guessingTestsWinner) {
    scenario(CODE_TO_TEST_STR, 4, 0);
}

TEST_F(ArbiterTest, guessingTestsAllNotAtPosision) {
    scenario(CODE_TO_TEST_STR_REVERSED, 0, 4);
}