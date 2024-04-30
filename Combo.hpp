#ifndef RESTAURANT_MANAGEMENT_COMBO_HPP
#define RESTAURANT_MANAGEMENT_COMBO_HPP

#include <iostream>
#include <string>
#include "Item.hpp"
#include <vector>

using namespace std;

class Combo {
public:

    Combo(int code, vector<Item> items, float discount);
    Combo();
    
    int getCode();
    vector<Item> getItems();
    
    float getDiscount();
    float getPrice();
    void setItems(vector<Item> items);
    void setDiscount(float discount);
    void setPrice(float price);

protected:
    int code;
    vector<Item> items;
    float discount = 0/100;
    float price = 0.00;
    static unsigned int codeOrder;
};

#endif