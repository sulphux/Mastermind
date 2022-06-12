#pragma once

#include <vector>


class GameSession {
private: 
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
public:
	GameSession(int size, std::vector<Ball> codeToGuess);

	GameSession(int size);

	void printCode();
	
	static int bla(int arg1);
private:
	int codeSize = 4;
	std::vector<Ball> codeToGuess;
	
	

};