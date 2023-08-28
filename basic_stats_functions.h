//
// Created by Cole Walker on 8/27/23.
//

#include <iostream>
#include <utility>
#include <sstream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

// Declaration
void printInputNumbers(vector<int>);

// From a string to vector<int>
vector<int> splitString(const string& input, char deliminator = ' ') {
    vector<string> stringNumbers;
    size_t startPos = 0;
    size_t endPos;

    while ((endPos = input.find(deliminator, startPos)) != string::npos) {
        stringNumbers.push_back(input.substr(startPos, endPos - startPos));
        startPos = endPos+1;
    }
    stringNumbers.push_back(input.substr(startPos));

    vector<int> intNumbers;

    for(int i = 0; i < stringNumbers.size(); i++){
        intNumbers.push_back(stoi(stringNumbers[i]));
    }

    return intNumbers;
}


// Desc: Get list of number from which to get values
// Input: N/A
// Output: N/A
vector<int> getListOfNumbers(){
    cout << "Enter the list of numbers separated by spaces" << endl;
    cout << "Ex: '1 22 23 43 443 212 494 14 4 84 922'" << endl;

    string userInput;
    cin.ignore();
    getline(cin, userInput);

    vector<int> vectorOfInts = splitString(userInput);

    return vectorOfInts;
}

// Desc: Get mean
// Input: List of integers (vector)
// Output: Mean (Int)
double getMean(vector<int> inputNumbers) {
    int total = 0;
    int sizeOfList = static_cast<int>(inputNumbers.size());

    for (int i = 0; i < sizeOfList; i++) {
        total += inputNumbers[i];
    }
    double mean = static_cast<double>(total) / static_cast<double>(sizeOfList);
    return mean;
}

// Quick sort & functions
int partition(vector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        if(array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i+1], array[high]);
    return i+1;
}


void quickSort(vector<int>& array, int low, int high) {
    if (low < high) {
        int par = partition(array, low, high);
        quickSort(array, low, par-1);
        quickSort(array, par+1, high);
    }
}

// End quick sort functions

// Desc: Get median
// Input: Vector of integers
// Output: Median of the vector of ints

double getMedian(vector<int> inputNumbers) {
    double median;

    int sizeOfNumbers = static_cast<int>(inputNumbers.size());

    // Need to sort
    quickSort(inputNumbers, 0, sizeOfNumbers-1);

    if (sizeOfNumbers % 2 == 1){
        median = static_cast<double>(inputNumbers[sizeOfNumbers/2]);
    } else {
        auto midNum1 = static_cast<double>(inputNumbers[(sizeOfNumbers-1)/2]);
        auto midNum2 = static_cast<double>(inputNumbers[sizeOfNumbers/2]);
        median = (midNum1 + midNum2) / 2.0;
    }
    return median;
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
        double median;

        switch (menuChoice) {
            case 1:
                inputNumbers = getListOfNumbers();
                break;
            case 2:
                cout << "The mean of: " << endl;
                printInputNumbers(inputNumbers);
                mean = getMean(inputNumbers);
                cout << "is: " << mean << "\n" << endl;
                break;
            case 3:
                cout << "The median of: " << endl;
                printInputNumbers(inputNumbers);
                median = getMedian(inputNumbers);
                cout << "is: " << median << "\n" <<endl;
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