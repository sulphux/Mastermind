#pragma once

#include "Code.h"
#include "Suggestion.h"
#include "Arbiter.h"

#include <vector>
#include <string>
#include <string_view>
#include <utility>

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

	Arbiter _arbiter{};

	static constexpr int _MAX_ATTEMPTS = 10;
	static constexpr int _ELEMENTS_AMOUNT = 8;
	static constexpr size_t _CODE_SIZE = 4;

	int _currentAttempt = 0;
	bool _gameIsFinished = false;
	bool _codeIsSolved = false;

	ProcessedGuessesVector _guessAttempts{};

	void _startNewGame();
	void _finishGame();
	void _showPlayerGuesses();
	void _judgeNewCodeAndStore(const std::string& codeStr);
	void _printSolution() const;

	size_t _getSizeOfStoredGuesses() const;

	bool _isGameFinished();
	bool _isPlayerWinner() const;
	std::pair<bool, std::string> _checkInputStringCorrectness(const std::string& str);
	bool _checkIfGuessIsWinningTheGame(const ProcessedGuess& processedGuess);

	std::string _getGuessCodeFromPlayer();
};