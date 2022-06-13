#include <iostream>
#include <vector>

#include "gtest/gtest.h"

#include "Code.h"
#include "CodeFactory.h"
#include "Suggestion.h"
#include "Arbiter.h"

class ArbiterTest : public ::testing::Test {
protected:
    Arbiter* arbiter;
    const std::string CODE_TO_TEST_STR = "2531";
    const std::string CODE_TO_TEST_STR_REVERSED = "1352";

    ArbiterTest() {
        arbiter = new Arbiter();
    }
    ~ArbiterTest() {
        if(arbiter != nullptr)
            delete arbiter;
    }
    virtual void SetUp()
    {
        arbiter->rememberCodeToGuess(CodeFactory::createCodeFromString(CODE_TO_TEST_STR));
    }
    virtual void TearDown() {}

    virtual void scenario(std::string guessedCodeStr, int expectedAtPosition, int expectedNotAtPosition) {
        Suggestion* suggestion = arbiter->makeNewSuggestionFromNewCode(CodeFactory::createCodeFromString(guessedCodeStr));

        EXPECT_EQ(expectedAtPosition, suggestion->getAtPositionAmount());
        EXPECT_EQ(expectedNotAtPosition, suggestion->getNotAtPositionAmount());

        delete suggestion;
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