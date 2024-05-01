#ifndef RESTAURANT_MANAGEMENT_ORDER_HPP
#define RESTAURANT_MANAGEMENT_ORDER_HPP

#include <iostream>
#include <string>
#include "Item.hpp"
#include "Combo.hpp"
#include "Date.hpp"
#include "Customer.hpp"
#include <vector>

using namespace std;

enum OrderStatus {
    waitingPayment = 'W',
    production = 'P',
    delivered = 'D',
};

enum PaymentMethod {
    money = 'M',
    card = 'C',
    pix = 'P',
};

class Order {
public:
    Order(vector<Item*> items, vector<Combo*> combos, Date* createdAt);
    Order();
    
    int getCode();
    vector<Item*> getItems();
    vector<Combo*> getCombos();
    float getTotalValue();
    OrderStatus getOrderStatus();
    Date* getCreatedAt();
    Customer* getCustomer();
    PaymentMethod getPaymentMethod();
    void print();

    void setItems(vector<Item*> items);
    void setCombos(vector<Combo*> combos);
    void setOrderStatus(OrderStatus orderStatus);
    void setCustomer(Customer* customer);
    void addItem(Item* item);
    void addCombo(Combo* combo);
    void pay(PaymentMethod paymentMethod);

private:
    int code;
    vector<Item*> items;
    vector<Combo*> combos;
    float totalValue = 0.00;
    static unsigned int orderCodeSequence;
    OrderStatus orderStatus = waitingPayment;
    PaymentMethod paymentMethod;
    Date* createdAt;
    Customer* customer;

    float calculateTotalValue();
};

#endif