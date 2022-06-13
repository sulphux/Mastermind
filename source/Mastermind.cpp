#include <iostream>
#include <vector>

#include "GameSession.h"
#include "CodeFactory.h"
#include "Code.h"
#include "Arbiter.h"


int main()
{
	GameSession gameSession;


	std::cout << "Welcome to Mastermind game!" << std::endl;
	std::cout << std::endl;
	std::cout << "Try to guess the code! Code has 4 digits, which should be unique \neach other and also in range = [1,8] " << std::endl;
	std::cout << std::endl;

	char s = '\0';

	do {
		gameSession.startNewGame();
		do {
			std::cout << std::endl << "############################################################" << std::endl;
			gameSession.showPlayerGuesses();

			std::string newCodeStr = gameSession.getGuessCodeFromPlayer();
			gameSession.judgeNewCodeAndStore(newCodeStr);

			if (gameSession.isPlayerWinner()) {
				std::cout << "CONGRATULATIONS!! YOU WIN!!!" << std::endl;
			}
			else if (gameSession.isGameFinished()) {
				std::cout << "Sorry too many attempts! Game finished!" << std::endl;
				gameSession.showPlayerGuesses();
				gameSession.printSolution();
			}
		} while (!gameSession.isGameFinished());

		std::cout << "Wanna play a new game?[y/N]" << std::endl;

		std::cin >> s;
	} while (s == 'y' || s == 'Y');
	std::cout << "BYE!";
	return 0;
}
