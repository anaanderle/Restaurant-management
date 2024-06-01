#include "Item.hpp"
#include "Order.hpp"

using namespace std;

Order::Order(vector<Item*> items, vector<Combo*> combos, Date* createdAt) {
    Order::orderCodeSequence++;
    this->code = orderCodeSequence;

    this->items = items;
    this->combos = combos;
    this->createdAt = createdAt;
}

Order::Order() {
    Order::orderCodeSequence++;
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
    float value = 0;

    for (Item* item : items) {
        value += item->getPrice();
    }

    for (Combo* &combo : combos) {
        value += combo->getPriceWithDiscount();
    }

    return value;
}

void Order::print() {
    cout << "Itens:" << endl;

    if(items.empty()) {
        cout << "-" << endl;
    }

    for(Item* item : items) {
        item->print();
    }

    cout << "Combos:" << endl;

    if(combos.empty()) {
        cout << "-" << endl;
    }

    for(Combo* combo : combos) {
        cout << combo->toString() << endl;
    }

    cout << "Total: R$ " << totalValue << endl;
}


string Order::toString() {
    string text = "Total: R$ " + to_string(totalValue) + " - Itens: ";

    if(items.empty()) {
        text += "não adicionado";
    }
    else {
        for(int i = 0; i < items.size(); i++) {
            text += items[i]->getName();

            if (i < items.size() - 1) {
                text += ", ";
            }
        }
    }

    text += " - Combos: ";

    if(combos.empty()) {
        text += "não adicionado";
    } else {
        for(int i = 0; i < combos.size(); i++) {
            text += combos[i]->toString();

            if (i < combos.size() - 1) {
                text += ". ";
            }
        }
    }

    return text;
}
