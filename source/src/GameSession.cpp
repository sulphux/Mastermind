#include "GameSession.h"
#include "Code.h"
#include "CodeFactory.h"
#include "GameMessages.h"

#include <string_view>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <sstream>

using namespace game_msg;
using namespace std::literals;

void GameSession::run()
{
	std::cout << WELCOME_MESSAGE << std::endl;
	std::cout << std::endl;

	char userChoice = '\0';

	do {
		_startNewGame();
		do {
			std::cout << std::endl << SEPARATOR << std::endl;
			_showPlayerGuesses();

			std::string newCodeStr = _getGuessCodeFromPlayer();
			_judgeNewCodeAndStore(newCodeStr);

			if (_isPlayerWinner()) {
				std::cout << WIN_MESSAGE << std::endl;
				_printSolution();
			}
			else if (_isGameFinished()) {
				std::cout << std::endl << SEPARATOR << std::endl;
				std::cout << FAIL_MESSAGE << std::endl;
				_showPlayerGuesses();
				_printSolution();
			}
		} while (!_isGameFinished() && !_isPlayerWinner());

		std::cout << AGAIN_MESSAGE << YN_CHOICE << std::endl;

		std::cin >> userChoice;
	} while (userChoice == 'y' || userChoice == 'Y');
	std::cout << BYE_MESSAGE << std::endl;
}

inline void GameSession::_startNewGame()
{
	_arbiter.rememberCodeToGuess(CodeFactory::createRandomCode(_CODE_SIZE));
	_currentAttempt = 0;
	_gameIsFinished = false;
	_codeIsSolved = false;
	if (!_guessAttempts.empty()) {
		_guessAttempts.clear();
	}
}

void GameSession::_finishGame()
{
	_gameIsFinished = true;
}

void GameSession::_showPlayerGuesses()
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

std::string GameSession::_getGuessCodeFromPlayer()
{
	std::cout << WRITE_YOUR_GUESS << std::endl;
	std::string guessStr;
	std::pair<bool, std::string> result;
	do {
		std::cin >> guessStr;
		result = _checkInputStringCorrectness(guessStr);
		if (result.first) {
			return guessStr;
		}
		else {
			std::cout << result.second;
			std::cout << TYPE_AGAIN << std::endl;
		}
	} while (!result.first);

	return guessStr;
}

void GameSession::_judgeNewCodeAndStore(const std::string& codeStr)
{
	CodePtr newCode = CodeFactory::createCodeFromString(codeStr);
	Suggestion suggestion = _arbiter.makeNewSuggestionFromNewCode(newCode);
	ProcessedGuess processedGuess(newCode, suggestion);
	_codeIsSolved = _checkIfGuessIsWinningTheGame(processedGuess);
	_guessAttempts.push_back(processedGuess);
	_currentAttempt++;
}

bool GameSession::_isGameFinished()
{
	if (!_gameIsFinished && _currentAttempt == _MAX_ATTEMPTS) {
		_gameIsFinished = true; 
	}
	return _gameIsFinished;
}

inline bool GameSession::_isPlayerWinner() const
{
	return _codeIsSolved;
}

inline size_t GameSession::_getSizeOfStoredGuesses() const
{
	return _guessAttempts.size();
}

void GameSession::_printSolution() const
{
	std::cout << SOLUTION_IS << *(_arbiter.unrevealSolution()) << std::endl;
}

std::pair<bool, std::string> GameSession::_checkInputStringCorrectness(const std::string& str)
{
	// Check size
	if (str.length() != _CODE_SIZE) {
		return std::make_pair(false, CODE_WRONG_SIZE);
	}

	// Check if all are digits
	for (auto ch : str) {
		if (std::isdigit(ch) != 0) {
			int num = (int)ch - 48;
			// Check if is in range
			if (num == 0 || num > _ELEMENTS_AMOUNT) {
				return std::make_pair(false, std::string(CODE_OUT_OF_RANGE_L) + 
													std::to_string(_ELEMENTS_AMOUNT) + 
													std::string(CODE_OUT_OF_RANGE_R));
			}
		}
		else {
			return std::make_pair(false, CODE_ONLY_DIGITS);
		}
	}

	// Check uniqueness of all digits
	for (size_t i = 0; i < str.length() - 1; ++i) {
		for (size_t j = i + 1; j < str.length(); ++j) {
			if (str[i] == str[j]) {
				return std::make_pair(false, CODE_UNIQUE_DIGITS);
			}
		}
	}

	return std::make_pair(true, std::string());
}

inline bool GameSession::_checkIfGuessIsWinningTheGame(const ProcessedGuess& processedGuess)
{
	return processedGuess.suggestion.getAtPositionAmount() == _CODE_SIZE;
}
