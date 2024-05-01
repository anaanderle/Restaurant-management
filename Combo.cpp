//combo.cpp

#include "Combo.hpp"
#include <string>

using namespace std;

Combo::Combo() {
    this->comboCodeSequence++;
    this->code = comboCodeSequence;
}

Combo::Combo(vector<Item*> items, float discount) {
    this->comboCodeSequence++;
    this->code = comboCodeSequence;

    this->items = items;
    this->discount = discount;
}

int Combo::getCode() {
    return code;
}

vector<Item*> Combo::getItems() {
    return items;
}

float Combo::getDiscount() {
    return discount;
}

float Combo::getPrice() {
    return price;
}

float Combo::getPriceWithDiscount() {
    for (Item* item : items) {
        price += item->getPrice();
    }
    return price - (price * discount);
}

void Combo::setItems(vector<Item*> items) {
    this->items = items;
}

void Combo::setDiscount(float discount) {
    this->discount = discount;
}

void Combo::setPrice(float price) {
    this->price = price;
}

