#ifndef RESTAURANT_MANAGEMENT_MENU_HPP
#define RESTAURANT_MANAGEMENT_MENU_HPP

#include <iostream>
#include <string>
#include "Item.hpp"
#include "Restaurant.hpp"
#include <vector>

using namespace std;

class Menu {
public:

    Menu(string name, Restaurant restaurant);

    int pedidos_andamento();
    int itens_vendidos();
    float faturamento();

    void menu_inicial();
    void menu_cliente();
    void menu_admin();
    void finalizar();
    void lanches(Order* order);
    void bebidas(Order* order);
    void sobremesas(Order* order);
    void combos();
    void acompanhamentos(Order* order);

private:
    string name = "";
    Restaurant restaurant;
};

#endif
