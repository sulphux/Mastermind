#include <string>
#include "Suggestion.h"

std::string Suggestion::toString()
{
	std::string result;
	result = "A: " + std::to_string(this->_atPosition) + " P: " + std::to_string(this->_notAtPosition);
	return result;
}

void Suggestion::incrementAtPosition() {
	this->_atPosition++;
}

void Suggestion::incrementNotAtPosition() {
	this->_notAtPosition++;
}

int Suggestion::getAtPositionAmount() {
	return this->_atPosition;
}

int Suggestion::getNotAtPositionAmount() {
	return this->_notAtPosition;
}