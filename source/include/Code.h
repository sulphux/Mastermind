#pragma once

#include <string>
#include <vector>
#include <cstdarg>
#include <ostream>

#include "Utils.h"

class Code {
public:
	Code(intVector _code);
	
	size_t getSize();
	int getDigitAt(const size_t n);

	friend std::ostream& operator<<(std::ostream& os, const Code& ct);
private:
	intVector _codeData;
	size_t _size;
};