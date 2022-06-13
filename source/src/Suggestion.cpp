#include <string>
#include <iostream>
#include "Suggestion.h"

std::string Suggestion::toString() const
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

int Suggestion::getAtPositionAmount() const {
	return this->_atPosition;
}

int Suggestion::getNotAtPositionAmount() const {
	return this->_notAtPosition;
}

std::ostream& operator<<(std::ostream& os, const Suggestion& st)
{
	os << "| AtPos: " << std::to_string(st._atPosition) << ' ';
	os << "| NotAtPos: " << std::to_string(st._notAtPosition) << " |";
	return os;
}