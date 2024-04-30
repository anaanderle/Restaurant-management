#include "Item.hpp"
#include "Beverage.hpp"
#include "Accompaniment.hpp"
#include <string>

using namespace std;

Accompaniment::Accompaniment(): Item() {}

Accompaniment::Accompaniment(string name, string description, float cost, float price, AccompanimentSize accompanimentSize): Item(name, description, cost, price) {
    this->accompanimentSize = accompanimentSize;
}

AccompanimentSize Accompaniment::getAccompanimentSize() {
    return accompanimentSize;
}

void Accompaniment::setAccompanimentSize(AccompanimentSize accompanimentSize) {
    this->accompanimentSize = accompanimentSize;
}

void Accompaniment::setCost(float cost) {
    this->cost = cost;
    this->price = 1.8 * cost;
}