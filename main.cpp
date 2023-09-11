#include <iostream>
#include "calculator_functions.h"
#include "guess_the_number.h"
#include "tic_tac_toe_game.h"
#include "basic_stats_functions.h"
#include "dice_rolling_simulator.h"

using namespace std;

// Desc: Display menu
void displayMenu() {
    cout << " Menu Options " << endl;
    cout << "1: Calculator" << endl;
    cout << "2: Guess the number" << endl;
    cout << "3: Tic Tac Toe Game" << endl;
    cout << "4: Basic Stats Calc" << endl;
    cout << "5: Roll Dice" << endl;
    cout << "6: EXIT \n" << endl;
}

int main() {

    int menuChoice;

    do {
        displayMenu();
        cin >> menuChoice;
        switch (menuChoice) {
            case 1:
                calculatorMenuSelection();
                break;
            case 2:
                main_GuessTheNumber();
                break;
            case 3:
                main_TicTacToe();
                break;
            case 4:
                main_BasicStatsCalc();
                break;
            case 5:
                rollDiceOneHundredTimes();
                break;
        }
    } while (menuChoice != 5);

    return 0;
}