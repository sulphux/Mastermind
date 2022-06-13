#include <iostream>
#include <vector>
#include <array>

#include "gtest/gtest.h"
#include "Code.h"
#include "CodeFactory.h"


TEST(Code, stringToCodeTest) {
	const size_t ARRAY_SIZE = 6;

	std::array<int, ARRAY_SIZE> expected = { 6, 5, 4, 1, 2, 3 };

	CodePtr code = CodeFactory::createCodeFromString("654123");

	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		EXPECT_EQ(expected[i], code->getDigitAt(i));
	}
}