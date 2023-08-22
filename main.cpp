#include <iostream>
#include "calculator_functions.h"
#include "guess_the_number.h"
using namespace std;

// Desc: Display menu
void displayMenu() {
    cout << " Menu Options " << endl;
    cout << "1: Calculator" << endl;
    cout << "2: Guess the number" << endl;
    cout << "4: EXIT \n" << endl;
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
                cout << "Case 3: " << endl;
                break;
        }
    } while (menuChoice != 4);

    return 0;
}
