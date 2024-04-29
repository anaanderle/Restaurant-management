#ifndef RESTAURANT_MANAGEMENT_BEVERAGE_HPP
#define RESTAURANT_MANAGEMENT_BEVERAGE_HPP

#include <iostream>
#include <string>
#include "Item.hpp"

using namespace std;

class Beverage: public Item {
public:

    Beverage(string name, string description, float cost, float price, float sizeLiters);
    Beverage();

    float getSizeLiters();

    void setSizeLiters(float sizeLiters);
    void setCost(float cost);

private:
    float sizeLiters = 0;
};

#endif
