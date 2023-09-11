//
// Created by Cole Walker on 9/10/23.
//


#include <iostream>
#include <utility>
#include <vector>
#include <typeinfo>
using namespace std;

int getRandomNum(int minRange, int maxRange){
    random_device rd;
    mt19937 gen(rd());
    // Min : Max (excluding max)
    uniform_int_distribution<> distribution(minRange, maxRange-1);

    return distribution(gen);
}

// Desc: "Rolls" a dice and returns its value
int rollDice() {
    int diceValue = getRandomNum(1, 7);
    return diceValue;
}

void rollDiceOneHundredTimes() {
    cout << "Rolling dice 100 times: " << endl;
    int diceVal;
    for (int i = 0; i < 100; i++){
        diceVal = rollDice();
        cout << i << ": " << diceVal << ", ";
        if (i % 10 == 0 && i != 0){
            cout << endl;
        }
    }
}


#ifndef BASICSYNTAX_AND_CONTROLSTRUCTS_DICE_ROLLING_SIMULATOR_H
#define BASICSYNTAX_AND_CONTROLSTRUCTS_DICE_ROLLING_SIMULATOR_H

#endif //BASICSYNTAX_AND_CONTROLSTRUCTS_DICE_ROLLING_SIMULATOR_H
