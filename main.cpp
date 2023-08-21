#include <iostream>
#include "calculator_functions.h"
using namespace std;

void displayMenu() {
    cout << " Menu Options " << endl;
    cout << "1: Calculator \n" << endl;
}

int main() {


    int menuChoice;

    do {
        displayMenu();
        cin >> menuChoice;
        switch (menuChoice) {
            case 1:
                cout << "Case 1: Calculator" << endl;
                calculatorMenuSelection();
                break;
            case 2:
                cout << "Case 2: " << endl;
                break;
            case 3:
                cout << "Case 3: " << endl;
                break;
        }
    } while (menuChoice != 4);

    return 0;
}
