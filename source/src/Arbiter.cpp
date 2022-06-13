#include "Arbiter.h"
#include "Code.h"
#include "Suggestion.h"
#include "Arbiter.h"

void Arbiter::rememberCodeToGuess(const Code* newCodeToGuess) {
	codeToGuess = const_cast<Code*>(newCodeToGuess);
}

Suggestion Arbiter::makeNewSuggestionFromNewCode(const Code* codeUserGuessed) {
	Suggestion newSuggestion;
	for(int i = 0; i<codeUserGuessed->getSize(); ++i) {
		for(int j = 0; j<codeToGuess->getSize(); ++j) {
			if (codeUserGuessed->getDigitAt(i) == codeToGuess->getDigitAt(j)) {
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

Code* Arbiter::unrevealSolution() const
{
	return codeToGuess;
}
