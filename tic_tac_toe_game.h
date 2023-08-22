//
// Created by Cole Walker on 8/22/23.
//
// Resource: https://thesharperdev.com/coding-the-perfect-tic-tac-toe-bot/

#include <iostream>
#include <vector>
using namespace std;

class TicTacToeBoard {
private:
    vector<vector<char>> board;
    const int size = 3;

public:
    TicTacToeBoard() {
        board = vector<vector<char>>(size, vector<char>(size, '.'));
    }

    void displayTicTacToeBoard() {
        for (int i = 0; i < size; i++) { // i is row
            cout << "|";
            for (int j = 0; j < size; j++) { // j is col
                cout << board[i][j];
                if (j < size - 1) {
                    cout << " ";
                }
            }
            cout << "|" << endl;
        }
        cout << endl;
    }
};

// Desc: Intro display for tic tac toe
// Input: N/A
// Output: N/A
void ticTacToeMenuDisplay() {
    cout << "Hello, this is the menu tic tac toe game!" << endl;
    cout << "1: Random-Selection Bot" << endl;
    cout << "2: Perfect-Play Bot" << endl;
    cout << "3: Exit \n" << endl;
}


// Desc: Tic Tac Toe game prompt logic
// Input: N/A
// Output: N/A
void main_TicTacToe(){

    int menuChoice;

    do {
        ticTacToeMenuDisplay();
        cin >> menuChoice;

        cout << "Test printing board" << endl;
        TicTacToeBoard ticTacToe = TicTacToeBoard();
        ticTacToe.displayTicTacToeBoard();

    } while (menuChoice != 3);

    cout << "You guessed it!" << endl;
    cout << "Great Job! \n" << endl;
}