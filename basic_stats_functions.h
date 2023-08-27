//
// Created by Cole Walker on 8/27/23.
//

#include <iostream>
#include <utility>
#include <sstream>
#include <vector>
#include <typeinfo>
using namespace std;

// Declaration
void printInputNumbers(vector<int>);

// Desc: Get list of number from which to get values
// Input: N/A
// Output: N/A
vector<int> getListOfNumbers(){
    cout << "Enter the list of numbers separated by spaces" << endl;
    cout << "Ex: '1 22 23 43 443 212 494 14 4 84 922'" << endl;

    vector<int> vectorOfInts;

    string userInput;
    cin.ignore();
    getline(cin, userInput);

    // TODO: SEE IF THERE IS A BETTER WAY THAN -48
    for (unsigned char c : userInput) {
        if (c != ' ') {
            vectorOfInts.push_back(static_cast<int>(c)-48);
        }
    }

    return vectorOfInts;
}

// Desc: Get mean
// Input: N/A
// Output: N/A
double getMean(vector<int> inputNumbers) {
    int total = 0;
    int sizeOfList = static_cast<int>(inputNumbers.size());

    for (int i = 0; i < sizeOfList; i++) {
        total += inputNumbers[i];
    }
    double mean = static_cast<double>(total) / static_cast<double>(sizeOfList);
    return mean;
}


void printInputNumbers(vector<int> inputNumbers) {
    for (int i = 0; i < inputNumbers.size(); i++) {
        cout << inputNumbers[i] << " ";
    }
    cout << endl;
}

// Desc: Intro display for basic stats
// Input: N/A
// Output: N/A
void basicStatsMenuDisplay() {
    cout << "Hello, this is the menu for basic stats operations!" << endl;
    cout << "It lets you enter a series of numbers and then " << endl;
    cout << "perform different operations on them!" << endl;
    cout << "1: Enter your numbers" << endl;
    cout << "2: Get mean" << endl;
    cout << "3: Get median" << endl;
    cout << "4: Get mode" << endl;
    cout << "5: Get standard deviation" << endl;
    cout << "6: Get range" << endl;
    cout << "7: Exit \n" << endl;
}

// Desc: Basic statistics calculator
// Input: N/A
// Output: N/A
void main_BasicStatsCalc(){

    int menuChoice;
    vector<int> inputNumbers;

    do {


        basicStatsMenuDisplay();
        cin >> menuChoice;


        // Variable inits
        double mean;

        switch (menuChoice) {
            case 1:
                inputNumbers = getListOfNumbers();
                break;
            case 2:
                cout << "The mean of: " << endl;
                printInputNumbers(inputNumbers);

                mean = getMean(inputNumbers);

                cout << "is: " << mean << endl;
                break;
            case 3:
                cout << "3" << endl;
                break;
            case 4:
                cout << "4" << endl;
                break;
            case 5:
                cout << "5" << endl;
                break;
            case 6:
                cout << "6" << endl;
                break;
            case 7:
                cout << "7" << endl;
                break;
        }

    } while (menuChoice != 8);

}