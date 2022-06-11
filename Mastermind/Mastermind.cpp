// Mastermind.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "Mastermind.h"
#include <vector>
#include <algorithm>
#include <random>
#include <array>
#include <iostream>
#include <string>
#include <functional>
#include <cstdlib>
#include <ctime>


//using namespace std;

enum Ball {
	WHITE = 0,
	BLACK = 1,
	RED = 2,
	GREEN = 3,
	BLUE = 4,
	YELLOW = 5,
	MAGENTA = 6,
	CYAN = 7
};

class GameSession {
public:
	GameSession(int size, std::vector<Ball> codeToGuess) {
		codeSize = size;
		this->codeToGuess = codeToGuess;
	}

	GameSession(int size) {
		codeSize = size;

	}
private:
	int codeSize = 4;
	std::vector<Ball> codeToGuess;
};

int main()
{
	srand((int)time(0));
	return 0;
}
