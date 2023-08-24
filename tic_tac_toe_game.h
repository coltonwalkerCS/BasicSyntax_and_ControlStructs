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
    char is_winner() {
        // Need 5 or more moves
        if (this->moves.size() < 5) {
            return ' ';
        }

        // Check rows for 3 in a row
        for (int row = 0; row < 3; row++) {
            vector<char> currRow = this->board[row];
            // Check each item is equal
            if (currRow[0] == currRow[1] and currRow[1] == currRow[2]) {
                // If X return player 1 won else player 2
                if (currRow[0] == 'X') {
                    return 'X';
                } else {
                    return 'O';
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
                    return 'X';
                } else {
                    return 'O';
                }
            }
        }

        // Check backward diagonal (top left to bottom right)
        if (this->board[0][0] == this->board[1][1] and this->board[1][1] == this->board[2][2]) {
            if (this->board[0][0] == 'X') {
                return 'X';
            } else {
                return 'O';
            }
        }

        // Check forward diagonal (bottom left to top right)
        if (this->board[2][0] == this->board[1][1] and this->board[1][1] == this->board[0][2]) {
            if (this->board[0][0] == 'X') {
                return 'X';
            } else {
                return 'O';
            }
        }

        // If all elements are filled and there is no
        // winner then it's a tie!
        if (this->moves.size() == 9) {
            return 'T';
        }

        return ' ';
    }

    void makeMove(int row, int col, char player) {
        // Set the MovePair
        MovePair moveLoc;
        moveLoc.row = row;
        moveLoc.col = col;

        this->moves.push_back(moveLoc);

        this->board[row][col] = player;
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

    vector<MovePair> getAllLegalMoves() {
        vector<MovePair> legalMoves;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (this->board[row][col] == '.'){
                    MovePair newMove;
                    newMove.row = row;
                    newMove.col = col;
                    legalMoves.push_back(newMove);
                }
            }
        }
        return legalMoves;
    }

    TicTacToeBoard copy() {
        TicTacToeBoard newBoard;
        newBoard.board = this->board;
        newBoard.moves = this->moves;
        return newBoard;
    }
};

class RandomBot {
private:
    int player;

public:
    RandomBot(int player_type) {
        player = player_type;
    }

    MovePair SelectMove(TicTacToeBoard board) {
        MovePair newMove;
        vector<MovePair> legalMoves = board.getAllLegalMoves();
        int numLegalMoves = static_cast<int>(legalMoves.size());
        int randMoveLoc = getRandomNumber(0, numLegalMoves);
        newMove.row = legalMoves[randMoveLoc].row;
        newMove.col = legalMoves[randMoveLoc].col;
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

char swapPlayers(char currPlayer) {
    char newPlayer;
    if (currPlayer == 'X'){
        newPlayer = '0';
    }else{
        newPlayer = 'X';
    }
    return newPlayer;
}

// Game logic
void PlayGame(char playerPiece){
    // Set bot piece
    char botPiece = 'X';
    if (playerPiece == 'X') {
        botPiece = 'O';
    }

    TicTacToeBoard board = TicTacToeBoard();
    RandomBot RandoBot(botPiece);

    char currentPlayer = 'X';
    char winner;

    for(int round = 0; round < 9; round++){
        MovePair currentMove;

        if (playerPiece == currentPlayer) {
            bool isValidMove;
            do {
                // Set to false then find if valid
                isValidMove = false;

                cout << "Input your move." << endl;
                cout << "Row:" << endl;
                cin >> currentMove.row;
                cout << "Col:" << endl;
                cin >> currentMove.col;

                // Check is valid move
                // TODO: FIX FOR LOOP? - Not sure what range-based is
                vector<MovePair> legalMoves = board.getAllLegalMoves();
                for (int move = 0; move < legalMoves.size(); move++) {
                    if (legalMoves[move].row == currentMove.row && legalMoves[move].col == currentMove.col ){
                        isValidMove = true;
                        break;
                    }
                }

            } while (!isValidMove);
        } else {
            currentMove = RandoBot.SelectMove(board);
        }

        // Update board & display
        board.makeMove(currentMove.row, currentMove.col, currentPlayer);
        board.displayTicTacToeBoard();

        // Check if there is a winner
        winner = board.is_winner();
        if (winner != ' ') {
            // Winner has been found exit loop
            break;
        }

        // Get next player
        currentPlayer = swapPlayers(currentPlayer);

    }
    // Display the winner
    if (winner == 'T') {
        cout << "The game was a TIE!" << endl;
    } else {
        cout << "The winner is player " << winner << "!" << endl;
    }
    cout << "Thanks for playing!" << endl;
}

char getPlayerPiece(){
    char playerPiece;
    bool validChoice;
    do {
        validChoice = true;
        cout << "Which piece do you want to play as? (X or O)" << endl;
        cin >> playerPiece;

        if (!(playerPiece == 'X' || playerPiece == 'O')) {
            cout << "Invalid piece" << endl;
            validChoice = false;
        }
    } while (!validChoice);
    return playerPiece;
}

// Desc: Tic Tac Toe game prompt logic
// Input: N/A
// Output: N/A
void main_TicTacToe(){

    int menuChoice;

    do {
        char playerPiece;

        ticTacToeMenuDisplay();
        cin >> menuChoice;

        switch (menuChoice) {
            case 1:
                playerPiece = getPlayerPiece();
                PlayGame(playerPiece);
                break;
            case 2:
                cout << "Perfect bot is currently not available" << endl;
                break;
        }

    } while (menuChoice != 3);

}