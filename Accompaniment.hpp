#ifndef RESTAURANT_MANAGEMENT_ACCOMPANIMENT_HPP
#define RESTAURANT_MANAGEMENT_ACCOMPANIMENT_HPP

#include <iostream>
#include <string>
#include "Item.hpp"

using namespace std;

enum AccompanimentSize {
    small = 'S',
    normal = 'N',
    big = 'B',
};

class Accompaniment: public Item {
public:

    Accompaniment(string name, string description, float cost, float price, AccompanimentSize accompanimentSize);
    Accompaniment();

    AccompanimentSize getAccompanimentSize();

    void setAccompanimentSize(AccompanimentSize accompanimentSize);
    void setCost(float cost);

private:
    AccompanimentSize accompanimentSize = normal;
};

#endif
