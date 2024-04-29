#include "Item.hpp"
#include "Dessert.hpp"
#include <string>

using namespace std;

Dessert::Dessert(): Item() {}

Dessert::Dessert(string name, string description, float cost, float price): Item(name, description, cost, price) {}

void Dessert::setCost(float cost) {
    this->cost = cost;
    this->price = 1.3 * cost;
}