#include <string>
#include <iostream>
#include "Suggestion.h"

void Suggestion::incrementAtPosition() {
	_atPosition++;
}

void Suggestion::incrementNotAtPosition() {
	_notAtPosition++;
}

int Suggestion::getAtPositionAmount() const {
	return _atPosition;
}

int Suggestion::getNotAtPositionAmount() const {
	return _notAtPosition;
}

std::ostream& operator<<(std::ostream& os, const Suggestion& st)
{
	os << "| AtPos: " << std::to_string(st._atPosition) << ' ';
	os << "| NotAtPos: " << std::to_string(st._notAtPosition) << " |";
	return os;
}