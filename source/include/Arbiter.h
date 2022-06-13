#pragma once

#include "Code.h"
#include "Suggestion.h"

class Arbiter {
public:
	Arbiter() { codeToGuess = nullptr; };
	void rememberCodeToGuess(Code* codeToGuess);
	Suggestion makeNewSuggestionFromNewCode(Code* codeUserGuessed);
private:
	Code* codeToGuess = nullptr;
};