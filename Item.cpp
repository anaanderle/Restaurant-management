#include "Item.hpp"
#include <string>

using namespace std;

Item::Item() {
    Item::itemCodeSequence++;
    this->code = itemCodeSequence;
}

Item::Item(string name, string description, float cost, float price) {
    Item::itemCodeSequence++;
    this->code = itemCodeSequence;

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

void Item::print() {
    cout << name << endl;
}