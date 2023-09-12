//
// Created by Cole Walker on 9/11/23.
//

#include <iostream>
#include <random>
using namespace std;

#ifndef BASICSYNTAX_AND_CONTROLSTRUCTS_MONTE_CARLO_DISTRIBUTION_H
#define BASICSYNTAX_AND_CONTROLSTRUCTS_MONTE_CARLO_DISTRIBUTION_H

#endif //BASICSYNTAX_AND_CONTROLSTRUCTS_MONTE_CARLO_DISTRIBUTION_H

// Define a process class which takes the
// average duration and the variance.

class TimeOfProcess {
private:
    // mu of process (Expected value)
    int averageTimeOfProcess;
    // Variance (sigma^2)
    int varianceOfProcess;

public:
    TimeOfProcess(int avgTime, int variance) {
        averageTimeOfProcess = avgTime;
        varianceOfProcess = variance;
    }

    double getTimeOfProcess() {
        // Get a random num
        random_device rd;
        mt19937 rng(rd());
        uniform_real_distribution<double> uniform_dist(0.0, 1.0);

        // Create normal dist. given exp val and variance
        normal_distribution<double> normal_dist(averageTimeOfProcess, sqrt(varianceOfProcess));
        // Get rand val from that normal dist.
        double randTime = normal_dist(rng);

        // Return the random time generated!
        return randTime;
    }
};

double getProbOverATime(const vector<double>& totalEachRun, double timeToBeOver) {
    int count = 0;
    for (double run : totalEachRun) {
        if (run > timeToBeOver) {
            count += 1;
        }
    }

    double probOfExceedingLimit = (static_cast<double>(count) / static_cast<double>(totalEachRun.size())) * 100.0;
    return probOfExceedingLimit;
}

// Desc: Run samples on many processes to get the probability of a time occuring
void runSamples(){
    cout << "RUN SAMPLES" << endl;
    int s = 100000;
    TimeOfProcess ProcessOne = TimeOfProcess(5, 1);
    TimeOfProcess ProcessTwo = TimeOfProcess(10, 1);
    TimeOfProcess ProcessThree = TimeOfProcess(15, 1);

    vector<double> totalOfRuns;
    double tempTotal;
    double totalOfRun = 0;
    for (int i = 0; i < s; i++){
        tempTotal = ProcessOne.getTimeOfProcess() + ProcessTwo.getTimeOfProcess() + ProcessThree.getTimeOfProcess();
        totalOfRun += tempTotal;
        totalOfRuns.push_back(tempTotal);
    }

    double averageTimeTaken = totalOfRun / s;
    cout << "Average Time = " << averageTimeTaken << endl;

    double timeToBeOver = 34.0;
    double probOverLim = getProbOverATime(totalOfRuns, timeToBeOver);
    cout << "Prob of getting over " << timeToBeOver << " is: " << probOverLim << endl;
}

void monteCarloMenuDisplay() {
    cout << "Hello, here is the menu for the monte carlo sim" << endl;
    cout << "1: Run Simulator and get average time" << endl;
    cout << "2: EXIT" << endl;
}

// Make test to guarentee it is a monte carlo sim and it worked

void monteCarloMenu() {
    int menuChoice;
    do {
        monteCarloMenuDisplay();
        cin >> menuChoice;
        switch (menuChoice) {
            case 1:
                runSamples();
                break;
        }
    } while (menuChoice != 2);
}