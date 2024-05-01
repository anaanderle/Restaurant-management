#ifndef RESTAURANT_MANAGEMENT_SNACK_HPP
#define RESTAURANT_MANAGEMENT_SNACK_HPP

#include <iostream>
#include <string>
#include "Item.hpp"

using namespace std;

class Snack: public Item {
public:

    Snack(string name, string description, float cost, float price);
    Snack();

    char getType();

    void setCost(float cost);
};

#endif
