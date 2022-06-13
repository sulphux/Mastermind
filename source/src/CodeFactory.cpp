#include <algorithm>


#include "CodeFactory.h"
#include "Code.h"
#include "Utils.h"

Code* CodeFactory::createRandomCode(const int size)
{
	intVector newCodeVector;

	for (int i = 0; i < size; ++i) {
		newCodeVector.push_back(rand() % 8);
	}

	Code* newCode = new Code(newCodeVector);
	return newCode;
}


Code* CodeFactory::createCodeFromString(const std::string codeStr)
{
	intVector newCodeVector;
	int num = std::stoi(codeStr);
	do {
		newCodeVector.push_back(num % 10);
		num /= 10;
	} while (num > 0);
	std::reverse(newCodeVector.begin(), newCodeVector.end());
	Code* newCode = new Code(newCodeVector);
	return newCode;
}