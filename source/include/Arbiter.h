#pragma once

#include "Code.h"
#include "Suggestion.h"

class Arbiter {
public:
	Arbiter() = default;
	~Arbiter() = default;
	void rememberCodeToGuess(const CodePtr _codeToGuess);
	Suggestion makeNewSuggestionFromNewCode(const CodePtr codeUserGuessed);
	CodePtr unrevealSolution() const;
private:
	CodePtr _codeToGuess;
};