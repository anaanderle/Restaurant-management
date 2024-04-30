#include <string>

#ifndef RESTAURANT_MANAGEMENT_CUSTOMER_HPP
#define RESTAURANT_MANAGEMENT_CUSTOMER_HPP

using namespace std;

class Customer {
public:
    Customer(string name);
    Customer();

    int getCode();
    string getName();

    void setName(string name);

private:
    int code;
    string name;
    static unsigned int customerCodeSequence;
};

#endif
