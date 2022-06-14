#pragma once

#include <string>

class Suggestion {
public:
	Suggestion(int atPosition, int presentButNotAtPosition) : _atPosition(atPosition), _notAtPosition(presentButNotAtPosition) {}
	Suggestion() = default;
	void incrementAtPosition();
	void incrementNotAtPosition();
	[[nodiscard]] int getAtPositionAmount() const;
	[[nodiscard]] int getNotAtPositionAmount() const;

	friend std::ostream& operator<<(std::ostream& os, const Suggestion& st);
private:
	int _atPosition;
	int _notAtPosition;
};