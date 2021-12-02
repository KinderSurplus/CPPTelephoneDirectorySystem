//
// Created by GamerComp on 11/24/2021.
//

#ifndef WEEK12_PROG2100_TELEPHONEDIRSYSTEM_LISTING_H
#define WEEK12_PROG2100_TELEPHONEDIRSYSTEM_LISTING_H

#include <iostream>
using namespace std;

class Listing {
private:
    string telNum;
    string name;
public:
    Listing(string telNum, string name) {
        setTelNum(telNum);
        setName(name);
    }

    string getTelNum() const {
        return telNum;
    }

    void setTelNum(string telNum) {
        Listing::telNum = telNum;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Listing::name = name;
    }
};


#endif //WEEK12_PROG2100_TELEPHONEDIRSYSTEM_LISTING_H
