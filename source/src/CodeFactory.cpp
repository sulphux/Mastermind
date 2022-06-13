#include <algorithm>
#include <memory>
#include <random>

#include "CodeFactory.h"
#include "Code.h"
#include "Utils.h"

CodePtr CodeFactory::createRandomCode(const int size)
{
	intVector newCodeVector;

	const intVector in{ 1, 2, 3, 4, 5, 6, 7, 8 };
	intVector out;
	size_t nelems = 4;

	std::sample(in.begin(), in.end(), 
		std::back_inserter(out), nelems, 
		std::mt19937{ std::random_device{}() } );

	return make_shared<Code>(newCodeVector);
}


CodePtr CodeFactory::createCodeFromString(const std::string codeStr)
{
	intVector newCodeVector;
	int num = std::stoi(codeStr);
	do {
		newCodeVector.push_back(num % 10);
		num /= 10;
	} while (num > 0);
	std::reverse(newCodeVector.begin(), newCodeVector.end());
	
	return make_shared<Code>(newCodeVector);
}
