#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "GameSession.h"
#include "CodeFactory.h"
#include "Code.h"
#include "Arbiter.h"

struct ProcessedGuess {
	ProcessedGuess(Code* c, Suggestion s) : code(c), suggestion(s) {}
	Code* code;
	Suggestion suggestion;
};

typedef std::vector<ProcessedGuess> codePtrVector;

codePtrVector guessAttempts;

int main()
{
	srand((int)time(0)); // it should be always on top of main

	Arbiter arbiter;
	arbiter.rememberCodeToGuess(CodeFactory::createCodeFromString("1234"));

	std::cout << "Guess the code!" << std::endl;

	while (1 == 1) {
		std::cout << "your last guesses:" << std::endl;
		auto it = guessAttempts.cbegin();
		for (; it != guessAttempts.cend(); ++it) {
			std::cout << *((*it).code) << " " << (*it).suggestion << std::endl;
		}
		std::cout << "write your next guess:" << std::endl;

		std::string guessStr;
		std::cin >> guessStr;
		/// TODO: check if correct
		/// assuming this is
		Code* newCode = CodeFactory::createCodeFromString(guessStr);
		Suggestion suggestion = arbiter.makeNewSuggestionFromNewCode(newCode);
		
		/// TODO: check if player wins
		guessAttempts.push_back(ProcessedGuess(newCode, suggestion));
	}


	return 0;
}
