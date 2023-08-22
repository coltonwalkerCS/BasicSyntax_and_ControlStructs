//
// Created by Cole Walker on 8/21/23.
//

#include <iostream>
using namespace std;

// Used for returning integer pairs
struct IntPair {
    // Default values of 0
    int valueOne = 0;
    int valueTwo = 0;
};

// Desc: Display for the calculator menu
// Input: N/A
// Output: N/A
void calculatorMenuDisplay() {
    cout << "Calculator Menu Options" << endl;
    cout << "1: Addition" << endl;
    cout << "2: Subtraction" << endl;
    cout << "3: Multiplication" << endl;
    cout << "4: Division" << endl;
    cout << "5: Exit \n" << endl;

}

// Desc: Gets two inputs for the user
// Input: N/A
// Output: IntPair
IntPair getTwoValuesPrompt() {
    IntPair enteredValues;

    cout << "Enter first value" << endl;
    cin >> enteredValues.valueOne;
    cout << "Enter second value" << endl;
    cin >> enteredValues.valueTwo;

    return enteredValues;
}

// Desc: Ask user for two values and prints the sum of them
// Input: N/A
// Output: N/A
void addition() {

    // Get both input
    IntPair enteredValues = getTwoValuesPrompt();

    int addition = enteredValues.valueOne + enteredValues.valueTwo;

    cout << enteredValues.valueOne << " + " << enteredValues.valueTwo << " = " << addition <<  "\n" << endl;
}

// Desc: Ask user for two values and prints the sum of them
// Input: N/A
// Output: N/A
void subtraction() {
    IntPair enteredValues = getTwoValuesPrompt();

    int subtraction = enteredValues.valueOne - enteredValues.valueTwo;

    cout << enteredValues.valueOne << " - " << enteredValues.valueTwo << " = " << subtraction <<  "\n" << endl;
}

// Desc: Ask user for two values and prints the sum of them
// Input: N/A
// Output: N/A
void multiplication() {
    IntPair enteredValues = getTwoValuesPrompt();

    int multiplication = enteredValues.valueOne * enteredValues.valueTwo;

    cout << enteredValues.valueOne << " + " << enteredValues.valueTwo << " = " << multiplication <<  "\n" << endl;
}

// Desc: Ask user for two values and prints the sum of them
// Input: N/A
// Output: N/A
void division() {
    IntPair enteredValues = getTwoValuesPrompt();

    int quotient = enteredValues.valueOne / enteredValues.valueTwo;
    int remainder = enteredValues.valueOne % enteredValues.valueTwo;

    cout << enteredValues.valueOne << " / " << enteredValues.valueTwo << " = " << quotient << " with remainder of " << remainder << "\n" << endl;
}

// Desc: Displays the calculator options
// Input: N/A
// Output: N/A
void calculatorMenuSelection() {

    int calcChoice;

    do {
        calculatorMenuDisplay();
        cin >> calcChoice;

        switch(calcChoice) {
            case 1:
                cout << "Case 1: Addition" << endl;
                addition();
                break;
            case 2:
                cout << "Case 2: Subtraction" << endl;
                subtraction();
                break;
            case 3:
                cout << "Case 3: Multiplication" << endl;
                multiplication();
                break;
            case 4:
                cout << "Case 4: Subtraction" << endl;
                division();
                break;
        }
    } while (calcChoice != 5);

}