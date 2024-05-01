#include "Item.hpp"
#include "Order.hpp"
// oii, tá me vendo?
using namespace std;

Order::Order(vector<Item*> items, vector<Combo*> combos, Date* createdAt) {
    this->orderCodeSequence++;
    this->code = orderCodeSequence;

    this->items = items;
    this->combos = combos;
    this->createdAt = createdAt;
}

Order::Order(){
    this->orderCodeSequence++;
    this->code = orderCodeSequence;
}


int Order::getCode() {
    return code;
}

vector<Item*> Order::getItems() {
    return items;
}

vector<Combo*> Order::getCombos() {
    return combos;
}

float Order::getTotalValue() {
    return totalValue;
}

OrderStatus Order::getOrderStatus() {
    return orderStatus;
}

Date* Order::getCreatedAt() {
    return createdAt;
}

Customer* Order::getCustomer() {
    return customer;
}

PaymentMethod Order::getPaymentMethod() {
    return paymentMethod;
}

void Order::setItems(vector<Item*> items) {
    this->items = items;
    this->totalValue = this->calculateTotalValue();
}

void Order::setCombos(vector<Combo*> combos) {
    this->combos = combos;
    this->totalValue = this->calculateTotalValue();
}

void Order::setOrderStatus(OrderStatus orderStatus) {
    this->orderStatus = orderStatus;
}

void Order::setCustomer(Customer* customer) {
    this->customer = customer;
}

void Order::addItem(Item* item) {
        this->items.push_back(item);
        this->totalValue = this->calculateTotalValue();
}

void Order::addCombo(Combo* combo) {
    this->combos.push_back(combo);
    this->totalValue = this->calculateTotalValue();
}

void Order::pay(PaymentMethod paymentMethod) {
    this->paymentMethod = paymentMethod;
    this->orderStatus = production;
}

float Order::calculateTotalValue() {
    float totalValue = 0;

    for (auto& item : items) {
        totalValue += item->getPrice();
    }

    for (auto& combo : combos) {
        totalValue += combo->getPriceWithDiscount();
    }

    return totalValue;
}

void Order::print() {
    for(auto item : items){
        item->print();
    }
}