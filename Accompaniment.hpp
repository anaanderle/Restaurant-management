#ifndef RESTAURANT_MANAGEMENT_ACCOMPANIMENT_HPP
#define RESTAURANT_MANAGEMENT_ACCOMPANIMENT_HPP

#include <iostream>
#include <string>
#include "Item.hpp"

using namespace std;

enum accompanimentSize {
    small = 'S',
    normal = 'N',
    big = 'B',
};

class Accompaniment: public Item {
public:

    Accompaniment(string name, string description, float cost, float price, accompanimentSize accompanimentSize);
    Accompaniment();

    accompanimentSize getAccompanimentSize();

    void setAccompanimentSize(accompanimentSize accompanimentSize);
    void setCost(float cost);

private:
    accompanimentSize accompanimentSize = normal;
};

#endif
