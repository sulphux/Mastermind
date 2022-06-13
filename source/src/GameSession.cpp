#include "GameSession.h"
#include "GameSession.h"
#include "GameSession.h"
#include "GameSession.h"
#include "GameSession.h"
#include "Code.h"
#include "CodeFactory.h"

#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

GameSession::GameSession() {
	srand((int)time(0));
}

void GameSession::startNewGame()
{
	_arbiter.rememberCodeToGuess(CodeFactory::createRandomCode(_codeSize));
	_currentAttempt = 0;
	_gameIsFinished = false;
	_codeIsSolved = false;
	if (!_guessAttempts.empty()) {
		_guessAttempts.clear();
	}
}

void GameSession::finishGame()
{
	_gameIsFinished = true;
}

void GameSession::showPlayerGuesses()
{
	if (_guessAttempts.empty()) {
		return;
	}
	std::cout << "your last guesses:" << std::endl;
	int i = 1;
	auto it = _guessAttempts.cbegin();
	for (; it != _guessAttempts.cend(); ++it) {
		std::cout << "Attempt " << i << ": " << *((*it).code) << " " << (*it).suggestion << std::endl;
		i++;
	}
}

std::string GameSession::getGuessCodeFromPlayer()
{
	std::cout << "write your next guess:" << std::endl;
	std::string guessStr;
	bool isGuessStrCorrect;
	do {
		std::cin >> guessStr;
		std::string feedbackMessage;
		isGuessStrCorrect = _checkInputStringCorrectness(_codeSize, _elements, guessStr, feedbackMessage);
		if (!isGuessStrCorrect) {
			std::cout << feedbackMessage;
			std::cout << " Type your guess again !" << std::endl;
		}
	} while (!isGuessStrCorrect);
	return guessStr;
}

void GameSession::judgeNewCodeAndStore(const std::string codeStr)
{
	Code* newCode = CodeFactory::createCodeFromString(codeStr);
	Suggestion suggestion = _arbiter.makeNewSuggestionFromNewCode(newCode);
	ProcessedGuess processedGuess(newCode, suggestion);
	_codeIsSolved = _checkIfGuessIsWinningTheGame(processedGuess);
	_guessAttempts.push_back(processedGuess);
	_currentAttempt++;
}

bool GameSession::isGameFinished()
{
	if (!_gameIsFinished && _currentAttempt == _maxAttempts) {
		_gameIsFinished = true; 
		return true;
	}
	return _gameIsFinished;
}

bool GameSession::isPlayerWinner() const
{
	return _codeIsSolved;
}

int GameSession::getSizeOfStoredGuesses() const
{
	return _guessAttempts.size();
}

void GameSession::printSolution() const
{
	std::cout << "Solution is:" << *(_arbiter.unrevealSolution()) << std::endl;
}

bool GameSession::_checkInputStringCorrectness(const size_t size, const int maxElement, const std::string& str, std::string& feedbackMessage)
{
	feedbackMessage = "";

	// Check size
	if (str.length() != size) {
		feedbackMessage = "Wrong size of code !";
		return false;
	}

	// Check if all are digits
	for (char const& ch : str) {
		if (std::isdigit(ch) != 0) {
			int num = (int)ch - 48;
			if (num == 0 || num > maxElement) {
				// Check if is in range
				feedbackMessage = "Only digits from range [1, " + std::to_string(maxElement) + "] are allowed !";
				return false;
			}
		}
		else {
			feedbackMessage = "Code should have only digits !";
			return false;
		}
	}

	// Check uniqueness of all digits
	for (int i = 0; i < str.length() - 1; i++) {
		for (int j = i + 1; j < str.length(); j++) {
			if (str[i] == str[j]) {
				feedbackMessage = "Code should have unique digits !";
				return false;
			}
		}
	}

	return true;
}

bool GameSession::_checkIfGuessIsWinningTheGame(const ProcessedGuess& processedGuess)
{
	if (processedGuess.suggestion.getAtPositionAmount() == _codeSize) {
		return true;
	}
	return false;
}
