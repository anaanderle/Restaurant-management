#include "Restaurant.hpp"

Restaurant::Restaurant(string name, vector<Item> items, vector<Combo> combos,
                       vector<Order> orders) {
    this->name = name;
    this->items = items;
    this->combos = combos;
    this->orders = orders;
}

Restaurant::Restaurant() = default;

string Restaurant::getName() {
    return name;
}

vector<Item> Restaurant::getItems() {
    return items;
}

vector<Combo> Restaurant::getCombos() {
    return combos;
}

vector<Order> Restaurant::getOrders() {
    return orders;
}

void Restaurant::setName(string name) {
    this->name = name;
}

void Restaurant::setItems(vector<Item> items) {
    this->items = items;
}

void Restaurant::setCombos(vector<Combo> combos) {
    this->combos = combos;
}

void Restaurant::setOrders(vector<Order> orders) {
    this->orders = orders;
}

void Restaurant::addItem(Item item) {
    this->items.push_back(item);
}

void Restaurant::addCombo(Combo combo) {
    this->combos.push_back(combo);
}

void Restaurant::addOrder(Order order) {
    this->orders.push_back(order);
}

vector<Order> Restaurant::getOrdersWaitingPayment() {
    vector<Order> ordersWaitingPayment = {};

    for(auto& order : orders){
        if(order.getOrderStatus() == waitingPayment){
            ordersWaitingPayment.push_back(order);
        }
    }

    return ordersWaitingPayment;
}

vector<Order> Restaurant::getOrdersInProduction() {
    vector<Order> ordersInProduction = {};

    for(auto& order : orders){
        if(order.getOrderStatus() == production){
            ordersInProduction.push_back(order);
        }
    }

    return ordersInProduction;
}

vector<Item> Restaurant::getItemsSoldByDate(Date date) {
    vector<Item> itemsSold = {};

    for(auto& order : orders){
        if(order.getCreatedAt() != date) break;

        for(auto& item : order.getItems()){
            itemsSold.push_back(item);
        }
    }

    return itemsSold;
}

float Restaurant::getBillingByDate(Date date) {
    float billing = 0;

    for(auto& order : orders){
        if(order.getCreatedAt() != date) break;

        for(auto& item : order.getItems()){
            billing += item.getPrice();
        }

        for(auto& combo : order.getCombos()){
            billing += combo.getPriceWithDiscount();
        }
    }

    return billing;
}