#pragma once

#include "Code.h"
#include "Suggestion.h"
#include "Arbiter.h"

#include <vector>
#include <string>

class GameSession {
public:
	GameSession();
	void startNewGame();
	void finishGame();
	void showPlayerGuesses();
	std::string getGuessCodeFromPlayer();
	void judgeNewCodeAndStore(const std::string codeStr);
	bool isGameFinished();
	bool isPlayerWinner() const;
	int getSizeOfStoredGuesses() const;
	void printSolution() const;
private:
	struct ProcessedGuess {
		ProcessedGuess(Code* c, Suggestion s) : code(c), suggestion(s) {}
		Code* code;
		Suggestion suggestion;
	};

	typedef std::vector<ProcessedGuess> codePtrVector;

	Arbiter arbiter;
	const int maxAttempts = 3;
	const size_t codeSize = 4;
	const int elements = 8;

	int currentAttempt = 0;
	bool gameIsFinished = false;
	bool codeIsSolved = false;
	codePtrVector guessAttempts;

	bool checkInputStringCorrectness(const size_t size, const int maxElement, const std::string& str, std::string& feedbackMessage);
	bool checkIfGuessIsWinningTheGame(const ProcessedGuess& processedGuess);
};