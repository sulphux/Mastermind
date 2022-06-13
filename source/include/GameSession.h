#pragma once

#include "Code.h"
#include "Suggestion.h"
#include "Arbiter.h"

#include <vector>
#include <string>

class GameSession {
public:
	GameSession() = default;
	void run();

private:
	struct ProcessedGuess {
		ProcessedGuess(CodePtr c, Suggestion s) : code(c), suggestion(s) {}
		CodePtr code;
		Suggestion suggestion;
	};

	typedef std::vector<ProcessedGuess> ProcessedGuessesVector;

	void startNewGame();
	void finishGame();
	void showPlayerGuesses();
	std::string getGuessCodeFromPlayer();
	void judgeNewCodeAndStore(const std::string codeStr);
	bool isGameFinished();
	bool isPlayerWinner() const;
	int getSizeOfStoredGuesses() const;
	void printSolution() const;

	Arbiter _arbiter;
	const int _maxAttempts = 10;
	const size_t _codeSize = 4;
	const int _elements = 8;

	int _currentAttempt = 0;
	bool _gameIsFinished = false;
	bool _codeIsSolved = false;
	ProcessedGuessesVector _guessAttempts;

	bool _checkInputStringCorrectness(const size_t size, const int maxElement, const std::string& str, std::string& feedbackMessage);
	bool _checkIfGuessIsWinningTheGame(const ProcessedGuess& processedGuess);
};