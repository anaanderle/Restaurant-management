//
// Created by ana on 30/04/24.
//

#ifndef RESTAURANT_MANAGEMENT_RESTAURANT_HPP
#define RESTAURANT_MANAGEMENT_RESTAURANT_HPP

#include <string>
#include "Order.hpp"

using namespace std;

class Restaurant {
public:
    Restaurant(string name, vector<Item*> items, vector<Combo*> combos, vector<Order*> orders, vector<Customer*> customers);
    Restaurant();

    string getName();
    vector<Item*> getItems();
    vector<Combo*> getCombos();
    vector<Order*> getOrders();
    vector<Customer*> getCustomers();

    void setName(string name);
    void setItems(vector<Item*> items);
    void setCombos(vector<Combo*> combos);
    void setOrders(vector<Order*> orders);
    void setCustomers(vector<Customer*> customers);

    void addItem(Item* item);
    void addCombo(Combo* combo);
    void addOrder(Order* order);
    void addCustomer(Customer* customer);

    vector<Order*> getOrdersWaitingPayment();
    vector<Order*> getOrdersInProduction();
    vector<Item*> getItemsSoldByDate(Date* date);
    float getBillingByDate(Date* date);
    Customer* getCustomerByCode(int code);

private:
    string name;
    vector<Item*> items = {};
    vector<Combo*> combos = {};
    vector<Order*> orders = {};
    vector<Customer*> customers = {};
};


#endif //RESTAURANT_MANAGEMENT_RESTAURANT_HPP
