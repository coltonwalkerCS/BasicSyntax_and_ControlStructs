//
// Created by Cole Walker on 8/21/23.
//

#include <iostream>
#include <sstream>
using namespace std;

void calculatorMenuDisplay() {
    cout << "Calculator Menu Options" << endl;
    cout << "1: Addition" << endl;
    cout << "2: Subtraction" << endl;
    cout << "3: Multiplication" << endl;
    cout << "4: Division" << endl;
    cout << "5: Exit \n" << endl;

}

// Desc: Ask user for two values and prints the sum of them
void addition() {
    int valueOne, valueTwo;

    // Get both input
    cout << "Enter first value" << endl;
    cin >> valueOne;
    cout << "Enter second value" << endl;
    cin >> valueTwo;

    int addition = valueOne + valueTwo;

    cout << valueOne << " + " << valueTwo << " = " << addition <<  "\n" << endl;
}

// Desc: Ask user for two values and prints the sum of them
void subtraction() {
    int valueOne, valueTwo;

    // Get both input
    cout << "Enter first value" << endl;
    cin >> valueOne;
    cout << "Enter second value" << endl;
    cin >> valueTwo;

    int subtraction = valueOne - valueTwo;

    cout << valueOne << " - " << valueTwo << " = " << subtraction <<  "\n" << endl;
}

// Desc: Ask user for two values and prints the sum of them
void multiplication() {
    int valueOne, valueTwo;

    // Get both input
    cout << "Enter first value" << endl;
    cin >> valueOne;
    cout << "Enter second value" << endl;
    cin >> valueTwo;

    int multiplication = valueOne * valueTwo;

    cout << valueOne << " + " << valueTwo << " = " << multiplication <<  "\n" << endl;
}

// Desc: Ask user for two values and prints the sum of them
void division() {
    int dividend, divisor;

    // Get both input
    cout << "Enter first value" << endl;
    cin >> dividend;
    cout << "Enter second value" << endl;
    cin >> divisor;

    int quotient = dividend / divisor;
    int remainder = dividend % divisor;

    cout << dividend << " / " << divisor << " = " << quotient << " with remainder of " << remainder << "\n" << endl;
}

// Desc: Displays the calculator options
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