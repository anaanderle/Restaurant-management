#ifndef RESTAURANT_MANAGEMENT_MENU_HPP
#define RESTAURANT_MANAGEMENT_MENU_HPP

#include <iostream>
#include <string>
#include "Item.hpp"
#include "Restaurant.hpp"
#include <vector>

using namespace std;

class Menu {
public:

    Menu(string name, Restaurant restaurant);

    void ordersInProduction();
    void soldItems();
    void billing();

    void initialMenu();
    void customerMenu();
    void adminMenu();
    void doOrder(Customer* customer);
    void listOrders(Customer* customer);
    bool pay(Order* order);
    void snacks(Order* order);
    void beverages(Order* order);
    void desserts(Order* order);
    void accompaniments(Order* order);
    void combos(Order* order);
private:
    string name = "";
    Restaurant restaurant;
};

#endif
