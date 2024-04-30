#ifndef RESTAURANT_MANAGEMENT_ITEM_HPP
#define RESTAURANT_MANAGEMENT_ITEM_HPP

#include <iostream>
#include <string>

using namespace std;

class Item {
public:

    Item(string name, string description, float cost, float price);
    Item();

    int getCode();
    string getName();
    string getDescription();
    float getCost();
    float getPrice();

    void setName(string name);
    void setDescription(string description);
    virtual void setCost(float cost);
    void setPrice(float price);

protected:
    int code;
    string name = "";
    string description = "";
    float cost = 0.00;
    float price = 0.00;
    static unsigned int itemCodeSequence;
};

#endif
