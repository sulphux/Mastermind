#pragma once

#include "Code.h"
#include "Suggestion.h"

class Arbiter {
public:
	Arbiter() { _codeToGuess = nullptr; };
	void rememberCodeToGuess(const Code* _codeToGuess);
	Suggestion makeNewSuggestionFromNewCode(const Code* codeUserGuessed);
	Code* unrevealSolution() const;
private:
	Code* _codeToGuess = nullptr;
};