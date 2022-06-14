#include <iostream>
#include <string>
#include <vector>
#include <cstdarg>
#include <memory>

#include "Code.h"



int Code::getDigitAt(const size_t n) const
{
	try
	{
		return _codeData.at(n);
	}
	catch (const std::out_of_range& d)
	{
		return -1;
	}
	return -1;
}

std::ostream& operator<<(std::ostream& os, const Code& ct)
{
	for (const auto val : ct._codeData) {
		os << "| " << val << ' ';
	}
	os << "|";
	return os;
}