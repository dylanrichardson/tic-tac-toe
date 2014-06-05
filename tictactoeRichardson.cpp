#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include "tictactoeRichardson.h"

using namespace std;

game::game() {
    strcpy(grid, "123456789");
}

void game::start() {
    cout << "TIC TAC TOE\n\n";
    do {
        cout << "1 or 2 players? ";
        cin >> type;
    } while (type < 1 || type > 2);
    system("cls");
    //1 player
    if (type == 1) {
        p1Wins = 0;
        cpuWins = 0;
        char ans;
        int start = 1;
        do {
            start = (start == 3) ? 1 : 3;
            strcpy(grid, "123456789");
            int progress = 3;
            int turn = start;
            while (progress == 3) {
                turn = (turn == 3) ? 1 : 3;
                display(1);
                input(turn);
                progress = check();
            }
            display(1);
            if (progress == 1) {
                if (turn == 1) {
                    p1Wins++;
                    display(1);
                    cout << "You win\n";
                } else {
                    cpuWins++;
                    display(1);
                    cout << "Computer wins\n";
                }
            } else
                cout << "Draw\n";
            do {
                cout << "Do you want to play again?(y/n) ";
                cin >> ans;
            } while (ans != 'y' && ans != 'n');
            system("cls");
        } while (ans == 'y');
    }
    //2 player
    else {
        p1Wins = 0;
        p2Wins = 0;
        char ans;
        int start = 1;
        do {
            start = (start % 2) ? 1 : 2;
            strcpy(grid, "123456789");
            int progress = 3;
            int turn = start;
            while (progress == 3) {
                turn = (turn % 2) ? 1 : 2;
                display(2);
                input(turn);
                turn++;
                progress = check();
            }
            display(2);
            turn--;
            if (progress == 1) {
                if (turn == 1) {
                    p1Wins++;
                    display(2);
                    cout << "Player 1 wins\n";
                } else {
                    p2Wins++;
                    display(2);
                    cout << "Player 2 wins\n";
                }
            } else
                cout << "Draw\n";
            do {
                cout << "Do you want to play again?(y/n) ";
                cin >> ans;
            } while (ans != 'y' && ans != 'n');
            system("cls");
            start++;
        } while (ans == 'y');
    }
}

void game::input(int turn) {
    if (turn == 3)
        ai();
    else {
        int number;
        char marker;
        if (turn == 1)
            marker = 'X';
        else
            marker = 'O';
        cout << "Player " << turn << "'s turn\n";
        cout << "Enter number: ";
        cin >> number;
        if (static_cast < int > (grid[number - 1]) == number + 48)
            grid[number - 1] = marker;
        else {
            display(2);
            input(turn);
        }
    }
}

void game::display(int players) {
    system("cls");
    cout << "                 TIC TAC TOE\n\n";
    cout << setw(16) << "|" << setw(16) << "|" << setw(36) << "LEGEND\n";
    cout << setw(16) << "|" << setw(16) << "|" << setw(39) << "------------\n";
    cout << setw(8) << grid[6] << setw(8) << "|" << setw(8) << grid[7] << setw(8) << "|" << setw(8) << grid[8] << setw(31) << "Player 1 - X\n";
    if (players == 2)
        cout << setw(16) << "|" << setw(16) << "|" << setw(39) << "Player 2 - O\n";
    else
        cout << setw(16) << "|" << setw(16) << "|" << setw(39) << "Computer - O\n";
    cout << setw(16) << "|" << setw(16) << "|" << endl;
    cout << "-----------------------------------------------            SCOREBOARD\n";
    cout << setw(16) << "|" << setw(16) << "|" << setw(39) << "------------\n";
    cout << setw(16) << "|" << setw(16) << "|" << setw(36) << "Player 1 -" << setw(2) << p1Wins << endl;
    if (players == 2)
        cout << setw(8) << grid[3] << setw(8) << "|" << setw(8) << grid[4] << setw(8) << "|" << setw(8) << grid[5] << setw(28) << "Player 2 -" << setw(2) << p2Wins << endl;
    else
        cout << setw(8) << grid[3] << setw(8) << "|" << setw(8) << grid[4] << setw(8) << "|" << setw(8) << grid[5] << setw(28) << "Computer -" << setw(2) << cpuWins << endl;
    cout << setw(16) << "|" << setw(16) << "|" << endl;
    cout << setw(16) << "|" << setw(16) << "|" << endl;
    cout << "-----------------------------------------------\n";
    cout << setw(16) << "|" << setw(16) << "|" << endl;
    cout << setw(16) << "|" << setw(16) << "|" << endl;
    cout << setw(8) << grid[0] << setw(8) << "|" << setw(8) << grid[1] << setw(8) << "|" << setw(8) << grid[2] << endl;
    cout << setw(16) << "|" << setw(16) << "|" << endl;
    cout << setw(16) << "|" << setw(16) << "|" << endl;
}

void game::ai() {
    //ai offense
    if (((grid[6] == 'O' && grid[7] == 'O') || (grid[0] == 'O' && grid[4] == 'O') || (grid[2] == 'O' && grid[5] == 'O')) && grid[8] != 'X')
        grid[8] = 'O';
    else if (((grid[6] == 'O' && grid[3] == 'O') || (grid[4] == 'O' && grid[8] == 'O') || (grid[2] == 'O' && grid[1] == 'O')) && grid[0] != 'X')
        grid[0] = 'O';
    else if (((grid[0] == 'O' && grid[3] == 'O') || (grid[2] == 'O' && grid[4] == 'O') || (grid[7] == 'O' && grid[8] == 'O')) && grid[6] != 'X')
        grid[6] = 'O';
    else if (((grid[0] == 'O' && grid[1] == 'O') || (grid[6] == 'O' && grid[4] == 'O') || (grid[8] == 'O' && grid[5] == 'O')) && grid[2] != 'X')
        grid[2] = 'O';
    else if (((grid[6] == 'O' && grid[8] == 'O') || (grid[1] == 'O' && grid[4] == 'O')) && grid[7] != 'X')
        grid[7] = 'O';
    else if (((grid[6] == 'O' && grid[0] == 'O') || (grid[4] == 'O' && grid[5] == 'O')) && grid[3] != 'X')
        grid[3] = 'O';
    else if (((grid[3] == 'O' && grid[4] == 'O') || (grid[8] == 'O' && grid[2] == 'O')) && grid[5] != 'X')
        grid[5] = 'O';
    else if (((grid[0] == 'O' && grid[2] == 'O') || (grid[4] == 'O' && grid[7] == 'O')) && grid[1] != 'X')
        grid[1] = 'O';
    else if (((grid[0] == 'O' && grid[8] == 'O') || (grid[1] == 'O' && grid[7] == 'O') || (grid[2] == 'O' && grid[6] == 'O') || (grid[3] == 'O' && grid[5] == 'O')) && grid[4] != 'X')
        grid[4] = 'O';
    //ai defense
    else if (((grid[6] == 'X' && grid[7] == 'X') || (grid[0] == 'X' && grid[4] == 'X') || (grid[2] == 'X' && grid[5] == 'X')) && grid[8] != 'O')
        grid[8] = 'O';
    else if (((grid[6] == 'X' && grid[3] == 'X') || (grid[4] == 'X' && grid[8] == 'X') || (grid[2] == 'X' && grid[1] == 'X')) && grid[0] != 'O')
        grid[0] = 'O';
    else if (((grid[0] == 'X' && grid[3] == 'X') || (grid[2] == 'X' && grid[4] == 'X') || (grid[7] == 'X' && grid[8] == 'X')) && grid[6] != 'O')
        grid[6] = 'O';
    else if (((grid[0] == 'X' && grid[1] == 'X') || (grid[6] == 'X' && grid[4] == 'X') || (grid[8] == 'X' && grid[5] == 'X')) && grid[2] != 'O')
        grid[2] = 'O';
    else if (((grid[6] == 'X' && grid[8] == 'X') || (grid[1] == 'X' && grid[4] == 'X')) && grid[7] != 'O')
        grid[7] = 'O';
    else if (((grid[6] == 'X' && grid[0] == 'X') || (grid[4] == 'X' && grid[5] == 'X')) && grid[3] != 'O')
        grid[3] = 'O';
    else if (((grid[3] == 'X' && grid[4] == 'X') || (grid[8] == 'X' && grid[2] == 'X')) && grid[5] != 'O')
        grid[5] = 'O';
    else if (((grid[0] == 'X' && grid[2] == 'X') || (grid[4] == 'X' && grid[7] == 'X')) && grid[1] != 'O')
        grid[1] = 'O';
    else if (((grid[0] == 'X' && grid[8] == 'X') || (grid[1] == 'X' && grid[7] == 'X') || (grid[2] == 'X' && grid[6] == 'X') || (grid[3] == 'X' && grid[5] == 'X')) && grid[4] != 'O')
        grid[4] = 'O';
    //random
    else {
        int possible[9];
        int counter = 0;
        for (int i = 0; i < 9; i++) {
            if (static_cast < int > (grid[i]) == i + 49)
                possible[counter++] = i;
        }
        grid[possible[rand() % counter]] = 'O';
    }
}

int game::check() {
    if (grid[0] == grid[1] && grid[0] == grid[2])
        return 1;
    else if (grid[3] == grid[4] && grid[3] == grid[5])
        return 1;
    else if (grid[6] == grid[7] && grid[6] == grid[8])
        return 1;
    else if (grid[0] == grid[3] && grid[0] == grid[6])
        return 1;
    else if (grid[1] == grid[4] && grid[1] == grid[7])
        return 1;
    else if (grid[2] == grid[5] && grid[2] == grid[8])
        return 1;
    else if (grid[0] == grid[4] && grid[0] == grid[8])
        return 1;
    else if (grid[2] == grid[4] && grid[2] == grid[6])
        return 1;
    else if (grid[0] != '1' && grid[1] != '2' && grid[2] != '3' && grid[3] != '4' && grid[4] != '5' && grid[5] != '6' && grid[6] != '7' && grid[7] != '8' && grid[8] != '9')
        return 2;
    else
        return 3;
}
