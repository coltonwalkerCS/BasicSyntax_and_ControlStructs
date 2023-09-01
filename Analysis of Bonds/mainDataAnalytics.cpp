//
// Created by Cole Walker on 8/30/23.
//

#include "mainDataAnalytics.h"

int main() {
    vector<BondData> bondDataRecords = importingCSVFile();

    vector<double> adjClose;

    for (const BondData& bond : bondDataRecords) {
        adjClose.push_back(bond.adjClose);
    }

    vector<tm> dateTimes;
    dateTimes = getDateTimeOfBonds(bondDataRecords);

    return 1;
}