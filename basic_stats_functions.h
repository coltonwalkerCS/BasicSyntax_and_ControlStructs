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

// Quicksort algorithm
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

// Desc: Get mode
// Input: Vector of integers
// Output: Mode of the vector of ints
int getMode(vector<int> inputNumbers) {

    int maxVal = *max_element(inputNumbers.begin(), inputNumbers.end());

    int cntSize = maxVal+1;

    // Initialize counter arr with 0's
    int counter[cntSize];
    for (int i = 0; i < cntSize; i++){
        counter[i] = 0;
    }

    // Go through vector and count number elements
    for (int i = 0; i < inputNumbers.size(); i++){
        counter[inputNumbers[i]]++;
    }

    // Go through counter and find the index with the largest value
    int mode = 0;
    int temp = counter[0];
    int sameMax = 0;
    for (int i = 1; i < cntSize; i++){
        if (counter[i] > temp) {
            mode = i;
            temp = counter[i];
            sameMax = 0;
        }else if (counter[i] == temp){
            sameMax += 1;
        }
    }
    if (sameMax != 0) {
        mode = 0;
    }
    return mode;
}

// Desc: Gets the standard deviation for a set of numbers
// Input: List of numbers (Vector<int>)
// Output: Standard deviation (double)
double getStandardDeviation(vector<int> inputNumbers) {
    double mean = getMean(inputNumbers);
    double squaredDiffSum = 0.0;

    for (double val : inputNumbers) {
        double difference = val - mean;
        squaredDiffSum += difference * difference;
    }
    double meanSquaredDiff = squaredDiffSum / static_cast<double>(inputNumbers.size());

    return sqrt(meanSquaredDiff);
}

// Desc: Gets the range for a data set
// Input: List of numbers (Vector<int>)
// Output: Range (int)
int getRange(vector<int> inputNumbers) {
    if (inputNumbers.size() < 2) {
        cout << "Error: Invalid input to range finder" << endl;
    }
    int max = inputNumbers[0];
    int min = inputNumbers[0];
    for (int val : inputNumbers) {
        if (val > max) {
            max = val;
        }
        if (val < min) {
            min = val;
        }
    }
    return max - min;
}

// Desc: Print the user inputted numbers
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
        int mode;
        double stdDev;
        int range;

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
                cout << "The mode of: " << endl;
                printInputNumbers(inputNumbers);
                mode = getMode(inputNumbers);
                cout << "is: " << mode << "\n" <<endl;
                break;
            case 5:
                cout << "The standard deviation of: " << endl;
                printInputNumbers(inputNumbers);
                stdDev = getStandardDeviation(inputNumbers);
                cout << "is: " << stdDev << "\n" <<endl;
                break;
            case 6:
                cout << "The range of: " << endl;
                printInputNumbers(inputNumbers);
                range = getRange(inputNumbers);
                cout << "is: " << range << "\n" <<endl;
                break;
        }

    } while (menuChoice != 7);

}