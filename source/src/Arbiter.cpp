#include "Code.h"
#include "Suggestion.h"
#include "Arbiter.h"

void Arbiter::rememberCodeToGuess(Code* codeToGuess) {
	this->codeToGuess = codeToGuess;
}

Suggestion* Arbiter::makeNewSuggestionFromNewCode(Code* codeUserGuessed) {
	Suggestion* newSuggestion = new Suggestion();
	for(int i = 0; i<codeUserGuessed->getSize(); ++i) {
		bool isPresent = false;
		bool isOnPosition = false;

		for(int j = 0; j<codeToGuess->getSize(); ++j) {
			if (codeUserGuessed->getDigitAt(i) == codeToGuess->getDigitAt(j)) {
				if (i == j) {
					newSuggestion->incrementAtPosition();
					break;
				}
				newSuggestion->incrementNotAtPosition();
				break;
			}
		}
	}
	return newSuggestion;
}
