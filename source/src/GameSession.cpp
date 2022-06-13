#include "GameSession.h"
#include "Code.h"
#include "CodeFactory.h"
#include "GameMessages.h"


#include <string_view>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

using namespace game_msg;
using namespace std::literals;

void GameSession::run()
{
	std::cout << WELCOME_MESSAGE << std::endl;
	std::cout << std::endl;

	char userChoice = '\0';

	do {
		startNewGame();
		do {
			std::cout << std::endl << SEPARATOR << std::endl;
			showPlayerGuesses();

			std::string newCodeStr = getGuessCodeFromPlayer();
			judgeNewCodeAndStore(newCodeStr);

			if (isPlayerWinner()) {
				std::cout << WIN_MESSAGE << std::endl;
				printSolution();
			}
			else if (isGameFinished()) {
				std::cout << std::endl << SEPARATOR << std::endl;
				std::cout << FAIL_MESSAGE << std::endl;
				showPlayerGuesses();
				printSolution();
			}
		} while (!isGameFinished() && !isPlayerWinner());

		std::cout << AGAIN_MESSAGE << YN_CHOICE << std::endl;

		std::cin >> userChoice;
	} while (userChoice == 'y' || userChoice == 'Y');
	std::cout << BYE_MESSAGE << std::endl;
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
	std::cout << LAST_GUESSES << std::endl;
	int i = 1;
	auto it = _guessAttempts.cbegin();
	for (; it != _guessAttempts.cend(); ++it) {
		std::cout << ATTEMPT << i << ": " << *((*it).code) << " " << (*it).suggestion << std::endl;
		i++;
	}
}

std::string GameSession::getGuessCodeFromPlayer()
{
	std::cout << WRITE_YOUR_GUESS << std::endl;
	std::string guessStr;
	bool isGuessStrCorrect = true;
	do {
		std::cin >> guessStr;
		std::string feedbackMessage;
		isGuessStrCorrect = _checkInputStringCorrectness(_codeSize, _elements, guessStr, feedbackMessage);
		if (!isGuessStrCorrect) {
			std::cout << feedbackMessage;
			std::cout << TYPE_AGAIN << std::endl;
		}
	} while (!isGuessStrCorrect);
	return guessStr;
}

void GameSession::judgeNewCodeAndStore(const std::string codeStr)
{
	CodePtr newCode = CodeFactory::createCodeFromString(codeStr);
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
	std::cout << SOLUTION_IS << *(_arbiter.unrevealSolution()) << std::endl;
}

bool GameSession::_checkInputStringCorrectness(const size_t size, const int maxElement, const std::string& str, std::string& feedbackMessage)
{
	feedbackMessage = "";

	// Check size
	if (str.length() != size) {
		feedbackMessage = CODE_WRONG_SIZE;
		return false;
	}

	// Check if all are digits
	for (char const& ch : str) {
		if (std::isdigit(ch) != 0) {
			int num = (int)ch - 48;
			// Check if is in range
			if (num == 0 || num > maxElement) {
				feedbackMessage = CODE_OUT_OF_RANGE_L;
				feedbackMessage += std::to_string(maxElement);
				feedbackMessage += CODE_OUT_OF_RANGE_R;
				return false;
			}
		}
		else {
			feedbackMessage = CODE_ONLY_DIGITS;
			return false;
		}
	}

	// Check uniqueness of all digits
	for (int i = 0; i < str.length() - 1; i++) {
		for (int j = i + 1; j < str.length(); j++) {
			if (str[i] == str[j]) {
				feedbackMessage = CODE_UNIQUE_DIGITS;
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
