#ifndef RESTAURANT_MANAGEMENT_DESSERT_HPP
#define RESTAURANT_MANAGEMENT_DESSERT_HPP

#include <iostream>
#include <string>
#include "Item.hpp"

using namespace std;

class Dessert: public Item {
public:

    Dessert(string name, string description, float cost, float price);
    Dessert();

    void setCost(float cost);
};

#endif
