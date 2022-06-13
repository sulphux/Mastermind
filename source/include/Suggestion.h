#pragma once

#include <string>

class Suggestion {
public:
	Suggestion(int atPosition, int presentButNotAtPosition) : _atPosition(atPosition), _notAtPosition(presentButNotAtPosition) {}
	Suggestion(){
		_atPosition = 0;
		_notAtPosition = 0;
	}
	std::string toString();
	void incrementAtPosition();
	void incrementNotAtPosition();
	int getAtPositionAmount();
	int getNotAtPositionAmount();
private:
	int _atPosition;
	int _notAtPosition;
};