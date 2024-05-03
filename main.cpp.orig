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
    Snack snack1("X-Burguer", "Pão, hambúrguer, bacon, queijo, alface, tomate, maionese, ovo", 15.0, 20.0);
    Snack snack2("X-Salada", "Pão, hambúrguer, queijo, alface, tomate, maionese", 10.0, 15.0);
    Snack snack3("X-Bacon", "Pão, hambúrguer, bacon, queijo, alface, tomate, maionese", 20.0, 25.0);
    Beverage beverage1("Coca-Cola", "Refrigerante de cola", 5.0, 7.0, 0.5);
    Beverage beverage2("Suco", "Suco natural laranja", 5.0, 7.0, 0.5);
    Beverage beverage3("Água", "Água", 2.0, 5.0, 0.5);
    Dessert dessert1("Sorvete", "Sorvete de creme", 10.0, 15.0);
    Dessert dessert2("Petit Gateau", "Petit Gateau", 25.0, 35.0);
    Dessert dessert3("Torta", "Torta de limão", 15.0, 20.0);
    AccompanimentSize tamanho;
    Accompaniment acompanhamento1("Batata frita", "Batata frita", 10.0, 15.0, tamanho);
    Accompaniment acompanhamento2("Onion rings", "Anéis de cebola empanados", 10.0, 15.0, tamanho);
    Accompaniment acompanhamento3("Nuggets", "Nuggets de frango", 10.0, 15.0, tamanho);
    vector<Item*> itemsCombo1 = {&snack1, &beverage1, &acompanhamento1};
    vector<Item*> itemsCombo2 = {&snack2, &beverage2, &acompanhamento2};
    vector<Item*> itemsCombo3 = {&snack3, &beverage3, &acompanhamento3};
    Combo combo1(itemsCombo1, 0.15);
    Combo combo2(itemsCombo2, 0.15);
    Combo combo3(itemsCombo3, 0.15);

    vector<Item*> restaurantItems = {&snack1, &snack2, &snack3, &beverage1, &beverage2, &beverage3, &dessert1, &dessert2, &dessert3, &acompanhamento1, &acompanhamento2, &acompanhamento3};
    vector<Combo*> restaurantCombos = {&combo1, &combo2, &combo3};
    
    Restaurant restaurant("Sanduichero", restaurantItems, restaurantCombos, {}, {});

    Menu("Menu", restaurant);

    return 0;
}