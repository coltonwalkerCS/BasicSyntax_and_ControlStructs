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
using namespace std;

struct BondData {
    string date;
    double high;
    double low;
    double open;
    double close;
    double adjClose;
};


void importingCSVFile() {
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


    for (int i = 0; i < 10; i++) {
        cout << "Date: " << bondDataRecs[i].date << "\n";
        cout << "High: " << bondDataRecs[i].high << "\n";
        cout << "Low: " << bondDataRecs[i].low << "\n";
        cout << "Open: " << bondDataRecs[i].open << "\n";
        cout << "Close: " << bondDataRecs[i].close << "\n";
        cout << "Adj Close: " << bondDataRecs[i].adjClose << "\n";
        cout << "\n";
    }
}


#endif //BASICSYNTAX_AND_CONTROLSTRUCTS_MAINDATAANALYTICS_H
