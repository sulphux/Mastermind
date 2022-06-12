#include "static/GameSession.h"
#include <cstdlib>
#include <ctime>


//using namespace std;


int main()
{
	srand((int)time(0));
	GameSession gameSession(6);
	gameSession.printCode();
	return 0;
}
