#include <iostream>

#include "GameSession.h"


int main()
{
	GameSession gameSession;

	const std::string SEPARATOR = "---------------------------------";
	const std::string WIN_MESSAGE = "CONGRATULATIONS!!YOU WIN!!!";
	const std::string FAIL_MESSAGE = "Sorry too many attempts! Game finished!";
	const std::string WELCOME_MESSAGE= "Welcome to Mastermind game!\n\n"
									   "Try to guess the code! Code has 4 digits, which should be unique \n"
									   "each other and also in range = [1,8]\n\n"
									   "You have 10 attempts\n\n"
									   "Let's start!";
	const std::string AGAIN_MESSAGE = "Wanna play a new game ?";
	const std::string BYE_MESSAGE = "See you later!";
	



	std::cout << WELCOME_MESSAGE << std::endl;
	std::cout << std::endl;

	char userChoice = '\0';

	do {
		gameSession.startNewGame();
		do {
			std::cout << std::endl << SEPARATOR<< std::endl;
			gameSession.showPlayerGuesses();

			std::string newCodeStr = gameSession.getGuessCodeFromPlayer();
			gameSession.judgeNewCodeAndStore(newCodeStr);

			if (gameSession.isPlayerWinner()) {
				std::cout << WIN_MESSAGE << std::endl;
				gameSession.printSolution();
			}
			else if (gameSession.isGameFinished()) {
				std::cout << std::endl << SEPARATOR << std::endl;
				std::cout << FAIL_MESSAGE << std::endl;
				gameSession.showPlayerGuesses();
				gameSession.printSolution();
			}
		} while (!gameSession.isGameFinished() && !gameSession.isPlayerWinner());

		std::cout << AGAIN_MESSAGE + "[y/N]" << std::endl;

		std::cin >> userChoice;
	} while (userChoice == 'y' || userChoice == 'Y');
	std::cout << BYE_MESSAGE << std::endl;
	return 0;
}
