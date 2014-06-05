#ifndef TICTACTOERICHARDSON_H
#define TICTACTOERICHARDSON_H

class game{
	public:
		game();
		char grid[9];
		bool gameOver;
		int type;
		int p1Wins,p2Wins,cpuWins;
		void start();
		void input(int);
		void display(int);
		void ai();
		int check();
	private:
};

#endif
