#include "Item.hpp"
#include <string>

using namespace std;

Item::Item() {
    this->codeOrder++;
    this->code = codeOrder;
}

Item::Item(string name, string description, float cost, float price) {
    this->codeOrder++;
    this->code = codeOrder;

    this->name = name;
    this->description = description;
    this->cost = cost;
    this->price = price;
}

int Item::getCode() {
    return code;
}

string Item::getName() {
    return name;
}

string Item::getDescription() {
    return description;
}

float Item::getCost() {
    return cost;
}
float Item::getPrice() {
    return price;
}

void Item::setName(string name) {
    this->name = name;
}

void Item::setDescription(string description) {
    this->description = description;
}

void Item::setCost(float cost) {
    this->cost = cost;
    this->price = 1.5 * cost;
}

void Item::setPrice(float price) {
    this->price = price;
}
