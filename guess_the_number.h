//
// Created by Cole Walker on 8/22/23.
//

#include <iostream>
#include <random>
using namespace std;


// Desc: Intro display for guess the number
// Input: N/A
// Output: N/A
void guessTheNumberDisplay() {
    cout << "Hello, this is the guess the number game!" << endl;
    cout << "I will think of a random number between 1-100" << endl;
    cout << "and you will try to guess. " << endl;
    cout << "I will give hints along the way :) \n" << endl;
}

// Desc: Generates a random number between (1,100)
// Input: N/A
// Output: Random number (Int)
int generateRandomNumber() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribution(1, 100);
    return distribution(gen);
}

// Desc: Is the hint prompt for the game saying
//       if the guess is higher or lower than the rand.
// Input: Random number of game (Int), User guessed number (Int)
// Output: N/A
void hintPrompt(int randomNumber, int guessedNumber) {
    if (randomNumber < guessedNumber) {
        cout << "HINT: The random number is lower than your guess!" << endl;
    } else {
        cout << "HINT: The random number is higher than your guess!" << endl;
    }
}

// Desc: Checks to make sure the guessed number is between (1,100)
// Input: Guessed number (Int)
// Output:
bool checkRange(int guessedNumber) {
    bool inRange;
    if (guessedNumber >= 1 and guessedNumber <= 100) {
        inRange = true;
    } else {
        cout << "Number not within range" << endl;
        inRange = false;
    }
    return inRange;
}

// Desc: Guess the number game prompt logic
// Input: N/A
// Output: N/A
void main_GuessTheNumber(){
    guessTheNumberDisplay();
    int randomNumber = generateRandomNumber();
    int guessedNumber;

    do {
        cout << "Type your guess here" << endl;
        cin >> guessedNumber;

        if (checkRange(guessedNumber)) {
            hintPrompt(randomNumber, guessedNumber);
        }
    } while (guessedNumber != randomNumber);

    cout << "You guessed it!" << endl;
    cout << "Great Job! \n" << endl;
}