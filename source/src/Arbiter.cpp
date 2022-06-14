#include "Arbiter.h"
#include "Code.h"
#include "Suggestion.h"

void Arbiter::rememberCodeToGuess(const CodePtr newCodeToGuess) {
	_codeToGuess = newCodeToGuess;
}

Suggestion Arbiter::makeNewSuggestionFromNewCode(const CodePtr codeUserGuessed) {
	Suggestion newSuggestion{};
	for(size_t i = 0; i<codeUserGuessed->getSize(); ++i) {
		for(size_t j = 0; j<_codeToGuess->getSize(); ++j) {
			if (codeUserGuessed->getDigitAt(i) == _codeToGuess->getDigitAt(j)) {
				if (i == j) {
					newSuggestion.incrementAtPosition();
					break;
				}
				newSuggestion.incrementNotAtPosition();
				break;
			}
		}
	}
	return newSuggestion;
}

CodePtr Arbiter::unrevealSolution() const
{
	return _codeToGuess;
}
