#include <iostream>
#include <string>
#include <vector>
#include <cstdarg>

#include "Code.h"
#include "Utils.h"

Code::Code(int num, ...)
{
	_size = num;
	va_list valist;
	va_start(valist, num);
	for (int i = 0; i < num; ++i) {
		_codeData.push_back(va_arg(valist, int));
	}
	va_end(valist);
}

Code::Code(intVector _code)
{
	_codeData = _code;
	_size = _code.size();
}

size_t Code::getSize()
{
	return _codeData.size();
}

int Code::getDigitAt(const size_t n)
{
	if (n >= 0 && n < _size) {
		return _codeData.at(n);
	}
	return -1;
}

std::ostream& operator<<(std::ostream& os, const Code& ct)
{
	for (auto it = ct._codeData.cbegin(); it != ct._codeData.cend(); ++it) {
		os << "| " << *it << ' ';
	}
	os << "|" << std::endl;
	return os;
}