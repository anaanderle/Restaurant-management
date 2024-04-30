#include "Customer.hpp"
#include <string>

using namespace std;

Customer::Customer(string name) {
    this->customerCodeSequence++;
    this->code = customerCodeSequence;

    this->name = name;
}

Customer::Customer() {
    this->customerCodeSequence++;
    this->code = customerCodeSequence;
}

int Customer::getCode() {
    return code;
}

string Customer::getName() {
    return name;
}

void Customer::setName(string name) {
    this->name = name;
}