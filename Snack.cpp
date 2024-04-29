#include "Item.hpp"
#include "Snack.hpp"
#include <string>

using namespace std;

Snack::Snack(): Item() {}

Snack::Snack(string name, string description, float cost, float price): Item(name, description, cost, price) {}

void Snack::setCost(float cost) {
    this->cost = cost;
    this->price = 3 * cost;
}