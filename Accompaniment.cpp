#include "Item.hpp"
#include "Beverage.hpp"
#include "Accompaniment.hpp"
#include <string>

using namespace std;

Accompaniment::Accompaniment(): Item() {}

Accompaniment::Accompaniment(string name, string description, float cost, float price, enum accompanimentSize accompanimentSize): Item(name, description, cost, price) {
    this->accompanimentSize = accompanimentSize;
}

accompanimentSize Accompaniment::getAccompanimentSize() {
    return accompanimentSize;
}

void Accompaniment::setAccompanimentSize(enum accompanimentSize accompanimentSize) {
    this->accompanimentSize = accompanimentSize;
}

void Accompaniment::setCost(float cost) {
    this->cost = cost;
    this->price = 1.8 * cost;
}