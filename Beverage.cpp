#include "Item.hpp"
#include "Beverage.hpp"
#include <string>

using namespace std;

Beverage::Beverage(): Item() {}

Beverage::Beverage(string name, string description, float cost, float price, float sizeLiters): Item(name, description, cost, price) {
    this->sizeLiters = sizeLiters;
}

float Beverage::getSizeLiters() {
    return sizeLiters;
}

void Beverage::setSizeLiters(float sizeLiters) {
    this->sizeLiters = sizeLiters;
}

void Beverage::setCost(float cost) {
    this->cost = cost;
    this->price = 2 * cost;
}