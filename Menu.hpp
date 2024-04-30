#ifndef RESTAURANT_MANAGEMENT_MENU_HPP
#define RESTAURANT_MANAGEMENT_MENU_HPP

#include <iostream>
#include <string>
#include "Item.hpp"
#include <vector>

using namespace std;

class Menu {
public:

    Menu();
    Menu(string name, vector<Item> items);
    
    int getCode();
    string getName();
    vector<Item> getItems();
    
    void setName(string name);
    void setItems(vector<Item> items);
};

#endif
