#include "static/GameSession.h"

#include <vector>
#include <iostream>

GameSession::GameSession(int size, std::vector<Ball> codeToGuess) {
	codeSize = size;
	this->codeToGuess = codeToGuess;
}

GameSession::GameSession(int size) {
	codeSize = size;
	for (int i = 0; i < size; ++i) {
		int r = rand() % 8;
		codeToGuess.push_back(static_cast<Ball>(r));
	}
}

void GameSession::printCode() {
	for (auto it = codeToGuess.cbegin(); it != codeToGuess.cend(); ++it) {
		std::cout << *it << ' ';
	}
}

int GameSession::bla(int arg1) {
    return arg1 * 2;
}