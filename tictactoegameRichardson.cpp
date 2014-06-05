#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include "tictactoeRichardson.h"

using namespace std;

int main() {
	char end;
	srand(time(0));
	while (true) {
		game GAME;
		GAME.start();
	}
	return EXIT_SUCCESS;
}
