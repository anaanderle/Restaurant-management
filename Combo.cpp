//combo.cpp

#include "Combo.hpp"
#include <string>

using namespace std;

Combo::Combo() {
    this->codeOrder++;
    this->code = codeOrder;
}

Combo::Combo(int code, vector<Item> items, float discount) {
    this->codeOrder++;
    this->code = codeOrder;

    this->items = items;
    this->discount = discount;
}

int Combo::getCode() {
    return code;
}

vector<Item> Combo::getItems() {
    return items;
}

float Combo::getDiscount() {
    return discount;
}

float Combo::getPrice() {
    float price = 0.00;
    for (Item item : items) {
        price += item.getPrice();
    }
    return price - (price * discount);
}

void Combo::setItems(vector<Item> items) {
    this->items = items;
}

void Combo::setDiscount(float discount) {
    this->discount = discount;
}

void Combo::setPrice(float price) {
    this->price = price;
}

unsigned int Combo::codeOrder = 0;
