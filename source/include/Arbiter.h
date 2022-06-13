#pragma once

#include "Code.h"
#include "Suggestion.h"

class Arbiter {
public:
	Arbiter() { _codeToGuess = nullptr; };
	void rememberCodeToGuess(const CodePtr _codeToGuess);
	Suggestion makeNewSuggestionFromNewCode(const CodePtr codeUserGuessed);
	CodePtr unrevealSolution() const;
private:
	CodePtr _codeToGuess = nullptr;
};