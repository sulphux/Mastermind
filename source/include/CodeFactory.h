#pragma once

#include "Code.h"

class CodeFactory {
public:
	static CodePtr createRandomCode(const int size);
	static CodePtr createCodeFromString(const std::string& codeStr);
private:
	static constexpr int _NUMBER_BASE = 10;
};