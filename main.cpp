#include "Item.hpp"
#include "Combo.hpp"
#include "Snack.hpp"
#include "Beverage.hpp"
#include "Accompaniment.hpp"
#include "Dessert.hpp"
#include "Menu.hpp"
#include "Restaurant.hpp"
#include <iostream>

unsigned int Item::itemCodeSequence = 0;
unsigned int Combo::comboCodeSequence = 0;
unsigned int Customer::customerCodeSequence = 0;
unsigned int Order::orderCodeSequence = 0;

int main()
{
    Snack lanche1("X-Burguer", "Pão, hambúrguer, bacon, queijo, alface, tomate, maionese, ovo", 15.0, 20.0);
    Snack lanche2("X-Salada", "Pão, hambúrguer, queijo, alface, tomate, maionese", 10.0, 15.0);
    Snack lanche3("X-Bacon", "Pão, hambúrguer, bacon, queijo, alface, tomate, maionese", 20.0, 25.0);
    Beverage bebida1("Coca-Cola", "Refrigerante de cola", 5.0, 7.0, 0.5);
    Beverage bebida2("Suco", "Suco natural laranja", 5.0, 7.0, 0.5);
    Beverage bebida3("Água", "Água", 2.0, 5.0, 0.5);
    Dessert sobremesa1("Sorvete", "Sorvete de creme", 10.0, 15.0);
    Dessert sobremesa2("Petit Gateau", "Petit Gateau", 25.0, 35.0);
    Dessert sobremesa3("Torta", "Torta de limão", 15.0, 20.0);
    AccompanimentSize tamanho;
    Accompaniment acompanhamento1("Batata frita", "Batata frita", 10.0, 15.0, tamanho);
    Accompaniment acompanhamento2("Onion rings", "Anéis de cebola empanados", 10.0, 15.0, tamanho);
    Accompaniment acompanhamento3("Nuggets", "Nuggets de frango", 10.0, 15.0, tamanho);
    vector<Item*> itemsCombo1 = {&lanche1, &bebida1, &acompanhamento1};
    vector<Item*> itemsCombo2 = {&lanche2, &bebida2, &acompanhamento2};
    vector<Item*> itemsCombo3 = {&lanche3, &bebida3, &acompanhamento3};
    Combo combo1(itemsCombo1, 0.15);
    Combo combo2(itemsCombo2, 0.15);
    Combo combo3(itemsCombo3, 0.15);

    vector<Item*> restaurantItems = {&lanche1, &lanche2, &lanche3, &bebida1, &bebida2, &bebida3, &sobremesa1,
                                     &sobremesa2, &sobremesa3, &acompanhamento1, &acompanhamento2, &acompanhamento3};
    vector<Combo*> restaurantCombos = {&combo1, &combo2, &combo3};
    
    Restaurant restaurant("Hamburgueria", restaurantItems, restaurantCombos, {}, {});

    Menu("Menu", restaurant);

    return 0;
}