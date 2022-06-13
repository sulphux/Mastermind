#pragma once

#include "Code.h"
#include "Suggestion.h"

class Arbiter {
public:
	Arbiter() { codeToGuess = nullptr; };
	void rememberCodeToGuess(const Code* codeToGuess);
	Suggestion makeNewSuggestionFromNewCode(const Code* codeUserGuessed);
	Code* unrevealSolution() const;
private:
	Code* codeToGuess = nullptr;
};