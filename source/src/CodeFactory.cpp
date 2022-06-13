#include <algorithm>
#include <memory>
#include <random>
#include <string>
#include <deque>

#include "CodeFactory.h"
#include "Code.h"


CodePtr CodeFactory::createRandomCode(const int size)
{
	std::vector<int> newCodeVector;

	const std::vector<int> in{ 1, 2, 3, 4, 5, 6, 7, 8 };
	size_t nelems = 4;

	std::sample(in.begin(), in.end(), 
		std::back_inserter(newCodeVector), nelems,
		std::mt19937{ std::random_device{}() } );

	return std::make_shared<Code>(newCodeVector);
}


CodePtr CodeFactory::createCodeFromString(const std::string& codeStr)
{
	std::deque<int> newCodeVector;
	int num = std::stoi(codeStr);
	do {
		newCodeVector.push_front(num % _NUMBER_BASE);
		num /= _NUMBER_BASE;
	} while (num > 0);
	
	return std::make_shared<Code>(std::vector<int>(newCodeVector.begin(), newCodeVector.end()));
}
