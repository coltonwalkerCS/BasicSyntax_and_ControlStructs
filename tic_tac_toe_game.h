//
// Created by Cole Walker on 8/22/23.
//
// Resource: https://thesharperdev.com/coding-the-perfect-tic-tac-toe-bot/

#include <iostream>
#include <vector>
using namespace std;

struct MovePair {
    int row;
    int col;
};

int getRandomNumber(int minRange, int maxRange){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> distribution(minRange, maxRange);

    return distribution(gen);
}

class TicTacToeBoard {
private:
    vector<vector<char>> board;
    const int size = 3;
    vector<MovePair> moves;

public:
    TicTacToeBoard() {
        board = vector<vector<char>>(size, vector<char>(size, '.'));
    }

    void UpdateTicTacToeBoard(vector<vector<char>> newBoard, vector<MovePair> newMoves) {
        board = newBoard;
        moves = newMoves;
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

    // Given the current board determine if there is a winner
    int is_winner() {
        // Need 5 or more moves
        if (this->moves.size() < 5) {
            return 0;
        }

        // Check rows for 3 in a row
        for (int row = 0; row < 3; row++) {
            vector<char> currRow = this->board[row];
            // Check each item is equal
            if (currRow[0] == currRow[1] and currRow[1] == currRow[2]) {
                // If X return player 1 won else player 2
                if (currRow[0] == 'X') {
                    return 1;
                } else {
                    return 2;
                }
            }
        }

        // Check the columns for 3 in a row
        for (int col = 0; col < 3; col++) {
            vector<char> currCol(3);
            for (int i = 0; i < 3; i++){
                currCol[i] = this->board[i][col];
            }

            // Check each item is equal
            if (currCol[0] == currCol[1] and currCol[1] == currCol[2]) {
                // If X return player 1 won else player 2
                if (currCol[0] == 'X') {
                    return 1;
                } else {
                    return 2;
                }
            }
        }

        // Check backward diagonal (top left to bottom right)
        if (this->board[0][0] == this->board[1][1] and this->board[1][1] == this->board[2][2]) {
            if (this->board[0][0] == 'X') {
                return 1;
            } else {
                return 2;
            }
        }

        // Check forward diagonal (bottom left to top right)
        if (this->board[2][0] == this->board[1][1] and this->board[1][1] == this->board[0][2]) {
            if (this->board[0][0] == 'X') {
                return 1;
            } else {
                return 2;
            }
        }

        // If all elements are filled and there is no
        // winner then it's a tie!
        if (this->moves.size() == 9) {
            return 3;
        }

        return 0;
    }

    void makeMove(int row, int col, int player) {
        // Set to player 1 else change
        char move = 'X';
        if (player == 2) {
            move = 'O';
        }

        // Set the MovePair
        MovePair moveLoc;
        moveLoc.row = row;
        moveLoc.col = col;

        this->moves.push_back(moveLoc);

        this->board[row][col] = move;
    }

    MovePair lastMove() {
        return this->moves.back();
    }

    bool isLocationEmpty(int row, int col) {
        if(this->board[row][col] == '.'){
            return true;
        }
        return false;
    }

    vector<vector<int>> getAllLegalMoves() {
        vector<vector<int>> legalMoves;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (this->board[row][col] == '.'){
                    vector<int> legalMove = {row, col};
                    legalMoves.push_back(legalMove);
                }
            }
        }
        return legalMoves;
    }

//    TicTacToeBoard copy() {
//        TicTacToeBoard newBoard;
//        newBoard.board = this->board;
//        newBoard.moves = this->moves;
//        return newBoard;
//    }
};

class RandomBot {
private:
    int player;

public:
    RandomBot(int player_bot) {
        player = player_bot;
    }

    MovePair SelectMove(TicTacToeBoard board) {
        MovePair newMove;
        vector<vector<int>> legalMoves = board.getAllLegalMoves();
        int randMoveLoc = getRandomNumber(0, legalMoves.size());
        newMove.row = legalMoves[randMoveLoc][0];
        newMove.col = legalMoves[randMoveLoc][1];
        return newMove;
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