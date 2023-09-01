//
// Created by Cole Walker on 8/30/23.
//

#ifndef BASICSYNTAX_AND_CONTROLSTRUCTS_MAINDATAANALYTICS_H
#define BASICSYNTAX_AND_CONTROLSTRUCTS_MAINDATAANALYTICS_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "matplotlibcpp.h"
using namespace std;

struct BondData {
    string date;
    double high;
    double low;
    double open;
    double close;
    double adjClose;
};


vector<BondData> importingCSVFile() {
    ifstream file("archive/TreasuryYield5Years.csv");
    string line;
    getline(file, line);
    vector<BondData> bondDataRecs;

    while (getline(file, line)) {
        istringstream ss(line);
        string field;

        BondData bondData;

        getline(ss, field, ',');
        bondData.date = field;

        getline(ss, field, ',');
        bondData.high = stod(field);

        getline(ss, field, ',');
        bondData.low = stod(field);

        getline(ss, field, ',');
        bondData.open = stod(field);

        getline(ss, field, ',');
        bondData.close = stod(field);

        getline(ss, field, ',');
        bondData.adjClose = stod(field);

        bondDataRecs.push_back(bondData);
    }


//    for (int i = 0; i < 10; i++) {
//        cout << "Date: " << bondDataRecs[i].date << "\n";
//        cout << "High: " << bondDataRecs[i].high << "\n";
//        cout << "Low: " << bondDataRecs[i].low << "\n";
//        cout << "Open: " << bondDataRecs[i].open << "\n";
//        cout << "Close: " << bondDataRecs[i].close << "\n";
//        cout << "Adj Close: " << bondDataRecs[i].adjClose << "\n";
//        cout << "\n";
//    }
    return bondDataRecs;
}

vector<double> calculateSMA(const vector<double>& data, int numDays) {
    vector<double> sma;
    for (int i = numDays - 1; i < data.size(); ++i) {
        double sum = 0.0;
        for (int j = i - numDays + 1; j <= i; ++j) {
            sum += data[j];
        }
        sma.push_back(sum / numDays);
    }
    return sma;
}

bool parseData(const string& dateStr, tm& dateTm) {
    if (dateStr.size() > 10 && dateStr.size() < 8) {
        return false;
    }

    if (dateStr.size() == 8) {
        // Ex: 1/3/2001
        dateTm.tm_mon = stoi(dateStr.substr(0, 1))-1;
        dateTm.tm_mday = stoi(dateStr.substr(2, 1));
        dateTm.tm_year = stoi(dateStr.substr(4, 4))-1900;

    } else if (dateStr.size() == 9) {
        // Ex: 5/11/2001
        if (dateStr.substr(1, 1) == "/") {
            dateTm.tm_mon = stoi(dateStr.substr(0, 1))-1;
            dateTm.tm_mday = stoi(dateStr.substr(2, 2));
            dateTm.tm_year = stoi(dateStr.substr(5, 4))-1900;
        // or 11/5/2001
        } else {
            dateTm.tm_mon = stoi(dateStr.substr(0, 2))-1;
            dateTm.tm_mday = stoi(dateStr.substr(3, 1));
            dateTm.tm_year = stoi(dateStr.substr(5, 4))-1900;
        }
    } else if (dateStr.size() == 10) {
        // Ex: 10/18/2001
        dateTm.tm_mon = stoi(dateStr.substr(0, 2))-1;
        dateTm.tm_mday = stoi(dateStr.substr(3, 2));
        dateTm.tm_year = stoi(dateStr.substr(6, 4))-1900;
    }
    return true;
}

vector<tm> getDateTimeOfBonds(vector<BondData> bondDataRecords) {
    vector<tm> dateTimes;

    for (const BondData& bond : bondDataRecords) {
        tm dateConverted = {};
        if (!parseData(bond.date, dateConverted)) {
           cout << "Error with " << bond.date << endl;
        }
        dateTimes.push_back(dateConverted);
    }

    return dateTimes;
}

void printBondFormattedDateTime(vector<BondData> bondDataRecords) {
    vector<tm> dateTimes;
    int sample[3] = {42, 210, 664};

    bool success;
    for (int i =0; i < 3; i++){
        tm dateConverted = {};
        if (parseData(bondDataRecords[sample[i]].date, dateConverted)) {
            cout << "Original: " << bondDataRecords[sample[i]].date << endl;
        }

        dateTimes.push_back(dateConverted);
    }

    cout << "TEST VALUES" << endl;
    char buffer[80];
    for (int i =0; i < 3; i++) {
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", &dateTimes[i]);
        cout << "Formatted Date and Time: " << buffer << endl;
    }
}

void displayData(vector<tm> dates, vector<int> adjClose) {

    vector<std::string> dateStrings;
    for (const auto& date : dates) {
        char buffer[11]; // Buffer for the formatted date (e.g., "YYYY-MM-DD")
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", &date);
        dateStrings.push_back(buffer);
    }
    return;
}

#endif //BASICSYNTAX_AND_CONTROLSTRUCTS_MAINDATAANALYTICS_H
