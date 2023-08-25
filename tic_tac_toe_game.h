//
// Created by Cole Walker on 8/22/23.
//
// Resource: https://thesharperdev.com/coding-the-perfect-tic-tac-toe-bot/

#include <iostream>
#include <utility>
#include <vector>
#include <typeinfo>
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
    const int size = 3;
    vector<vector<char>> board;
    vector<MovePair> moves;

public:
    TicTacToeBoard() {
        board = vector<vector<char>>(size, vector<char>(size, '.'));
    }

    TicTacToeBoard(vector<vector<char>> board_input, vector<MovePair> moves_input) : board(board_input), moves(moves_input) {}

    TicTacToeBoard(const TicTacToeBoard& newBoard) : board(newBoard.board), moves(newBoard.moves) {}

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
            if (currRow[0] == currRow[1] && currRow[1] == currRow[2] && currRow[0] != '.') {
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
            if (currCol[0] == currCol[1] && currCol[1] == currCol[2] && currCol[0] != '.') {
                // If X return player 1 won else player 2
                if (currCol[0] == 'X') {
                    return 'X';
                } else {
                    return 'O';
                }
            }
        }

        // Check backward diagonal (top left to bottom right)
        if (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != '.') {
            if (this->board[0][0] == 'X') {
                return 'X';
            } else {
                return 'O';
            }
        }

        // Check forward diagonal (bottom left to top right)
        if (this->board[2][0] == this->board[1][1] && this->board[1][1] == this->board[0][2] && this->board[2][0] != '.') {
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
        return TicTacToeBoard(*this);
    }
};

// -------- BOTS ------------ //
class Bot {
public:
    virtual ~Bot() {};
    virtual MovePair SelectMove(TicTacToeBoard board) = 0;
};

class RandomBot : public Bot {
private:
    char player;

public:
    RandomBot(char playerPiece) : player(playerPiece) {}

    MovePair SelectMove(TicTacToeBoard board) override {
        MovePair newMove;
        vector<MovePair> legalMoves = board.getAllLegalMoves();
        int numLegalMoves = static_cast<int>(legalMoves.size());
        int randMoveLoc = getRandomNumber(0, numLegalMoves);
        newMove.row = legalMoves[randMoveLoc].row;
        newMove.col = legalMoves[randMoveLoc].col;
        return newMove;
    }

};

class OneMoveDeepBot : public Bot {
private:
    char player;

public:
    OneMoveDeepBot(char playerPiece) : player(playerPiece) {}

    MovePair SelectMove(TicTacToeBoard board) override {
        MovePair newMove;
        vector<MovePair> legalMoves = board.getAllLegalMoves();
        int numLegalMoves = static_cast<int>(legalMoves.size());

        // See if there is a move which will win the game
        // if so choose it else get a random move
        for (int i = 0; i < numLegalMoves; i++) {
            int tempRow = legalMoves[i].row;
            int tempCol = legalMoves[i].col;

            TicTacToeBoard newBoard = board.copy();
            newBoard.makeMove(tempRow, tempCol, this->player);

            if (newBoard.is_winner() == this->player) {
                newMove.row = tempRow;
                newMove.col = tempCol;
                return  newMove;
            }
        }
        // TODO: FIND OUT WHY BOT CHOOSES 0, 0 sometimes even when not in legal moves
        // Issue when bot chooses 0, 0 which is not a legal move

        int randMoveLoc = getRandomNumber(0, numLegalMoves);

        newMove.row = legalMoves[randMoveLoc].row;
        newMove.col = legalMoves[randMoveLoc].col;
        return newMove;
    }
};

// -------- END BOTS ------------ //

// Desc: Intro display for tic tac toe
// Input: N/A
// Output: N/A
void ticTacToeMenuDisplay() {
    cout << "Hello, this is the menu tic tac toe game!" << endl;
    cout << "1: Random-Selection Bot" << endl;
    cout << "2: One-Move-Deep Bot" << endl;
    cout << "3: Exit \n" << endl;
}

char swapPlayers(char currPlayer) {
    char newPlayer;
    if (currPlayer == 'X'){
        newPlayer = 'O';
    }else{
        newPlayer = 'X';
    }
    return newPlayer;
}

MovePair getPlayerMove(TicTacToeBoard board) {
    bool isValidMove;
    MovePair currentMove;
    do {
        // Set to false then find if valid
        isValidMove = false;

        cout << "Input your move." << endl;
        cout << "Row:" << endl;
        cin >> currentMove.row;
        cout << "Col:" << endl;
        cin >> currentMove.col;

        // Check is valid move
        vector<MovePair> legalMoves = board.getAllLegalMoves();
        for (int move = 0; move < legalMoves.size(); move++) {
            if (legalMoves[move].row == currentMove.row && legalMoves[move].col == currentMove.col ){
                isValidMove = true;
                break;
            }
        }
        if (!isValidMove) {
            cout << "INVALID MOVE" << endl;
        }

    } while (!isValidMove);
    return currentMove;
}

// Game logic
void PlayGame(char playerPiece, Bot *gameBot){

    TicTacToeBoard board = TicTacToeBoard();


    char currentPlayer = 'X';
    char winner;

    for(int round = 0; round < 9; round++){
        MovePair currentMove;

        if (playerPiece == currentPlayer) {
            currentMove = getPlayerMove(board);
        } else {
            currentMove = gameBot->SelectMove(board);
            cout << "Bots Move: " << currentMove.row << ", " << currentMove.col << endl;
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
    board.displayTicTacToeBoard();
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

char getBotPiece(char playerPiece) {
    char botPiece = 'X';
    if (playerPiece == 'X') {
        botPiece = 'O';
    }
    return botPiece;
}

// Desc: Tic Tac Toe game prompt logic
// Input: N/A
// Output: N/A
void main_TicTacToe(){


    int menuChoice;

    do {
        char playerPiece;
        char botPiece;
        Bot* gameBot = nullptr;

        ticTacToeMenuDisplay();
        cin >> menuChoice;

        switch (menuChoice) {
            case 1:
                playerPiece = getPlayerPiece();
                botPiece = getBotPiece(playerPiece);
                gameBot = new RandomBot(botPiece);
                PlayGame(playerPiece, gameBot);
                break;
            case 2:
                playerPiece = getPlayerPiece();
                botPiece = getBotPiece(playerPiece);
                gameBot = new OneMoveDeepBot(botPiece);
                PlayGame(playerPiece, gameBot);
                break;
        }

    } while (menuChoice != 3);

}