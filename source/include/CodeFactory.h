#pragma once

#include "Code.h"

class CodeFactory {
public:
	static Code* createRandomCode(const int size);
	static Code* createCodeFromString(const std::string codeStr);
};