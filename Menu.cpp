#include "Item.hpp"
#include "Beverage.hpp"
#include "Dessert.hpp"
#include "Accompaniment.hpp"
#include "Combo.hpp"
#include "Snack.hpp"
#include "Menu.hpp"
#include <ctime>
using namespace std;

Menu::Menu(string name, Restaurant restaurant)
{
    this->name = name;
    this->restaurant = restaurant;

    initialMenu();
}

void Menu::initialMenu()
{
    int opcao = 0;

    while (opcao == 0)
    {
        cout << "\nBem vindo ao Sanduichero!\n" << endl;
        cout << "Escolha uma opção: " << endl;
        cout << "1 - Cliente" << endl;
        cout << "2 - Administrador" << endl;
        cout << "Outro para sair" << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            customerMenu();
            opcao = 0;
            break;

        case 2:
            adminMenu();
            opcao = 0;
            break;
        default:
            cout << "Obrigado por escolher o Sanduichero" << endl;
            return;
        }
    }
}

void Menu::customerMenu()
{
    int option = 0;
    string customerName = "";
    int customerCode;
    Customer* customer;

    while(option == 0){
        cout << "\nEscolha uma opção:" << endl;
        cout << "1 - Cadastro" << endl;
        cout << "2 - Fazer pedido" << endl;
        cout << "3 - Pagar pedido" << endl;
        cout << "Outro para voltar" << endl;
        cin >> option;
        
        switch (option)
        {
        case 1:
            cout << "\nDigite seu nome:" << endl;
            cin >> customerName;
            customer = new Customer(customerName);
            customerCode = customer->getCode();
            this->restaurant.addCustomer(customer);

            cout << "Olá, " << customerName << ". Utilize o código " << customerCode << " para realizar seus pedidos." << endl;

            option = 0;

            break;
        case 2:
            cout << "\nDigite seu código:" << endl;
            cin >> customerCode;

            customer = restaurant.getCustomerByCode(customerCode);

            if(customer == nullptr){
                cout << "\nNão foi possível encontrar um cliente com esse código!" << endl;
            } else {
                customerName = customer->getName();
                doOrder(customer);
            }
            option = 0;
            break;
        case 3:
            cout << "\nDigite seu código:" << endl;
            cin >> customerCode;

            customer = restaurant.getCustomerByCode(customerCode);

            if(customer == nullptr){
                cout << "\nNão foi possível encontrar um cliente com esse código!" << endl;
            } else {
                customerName = customer->getName();
                listOrders(customer);
            }
            option = 0;
            break;
        default:
            return;
        }
    }
}

void Menu::listOrders(Customer *customer) {
    int orderIndex = -1;
    vector<Order*> customerOrdersWaitingPayment =
            restaurant.getOrdersByCustomerCodeAndOrderStatus(customer->getCode(), waitingPayment);

    while(orderIndex == -1){
        cout << "Selecione o pedido para pagamento:" << endl;

        if(customerOrdersWaitingPayment.empty()){
            cout << "Não há nenhum pedido para pagar." << endl;
            return;
        }

        for(int i = 0; i < customerOrdersWaitingPayment.size(); i++){
            cout << i + 1 << " - " << customerOrdersWaitingPayment[i]->toString() << endl;
        }

        cin >> orderIndex;

        if(orderIndex > customerOrdersWaitingPayment.size()){
            cout << "\nParece que essa opção não está disponível!\n" << endl;
            return;
        }

        bool hasSuccess = pay(customerOrdersWaitingPayment[orderIndex - 1]);

        if(!hasSuccess){
            orderIndex = -1;
        }
    }
}

void Menu::doOrder(Customer* customer) {
    time_t currentTime = std::time(nullptr);
    tm* currentDate = localtime(&currentTime);
    Date* date = new Date(currentDate->tm_mday, currentDate->tm_mon, currentDate->tm_year);

    Order* order = new Order({}, {}, date);
    order->setCustomer(customer);
    order->setOrderStatus(waitingPayment);

    restaurant.addOrder(order);

    int option = 1;

    while(option == 1){
        cout << "\nCARDÁPIO" << endl;
        cout << "1 - Lanches" << endl;
        cout << "2 - Bebidas" << endl;
        cout << "3 - Acompanhamentos" << endl;
        cout << "4 - Sobremesas" << endl;
        cout << "5 - Combos" << endl;
        cout << "Outro para voltar" << endl;
        cin >> option;

        switch (option)
        {
            case 1:
                snacks(order);
                break;
            case 2:
                beverages(order);
                break;
            case 3:
                accompaniments(order);
                break;
            case 4:
                desserts(order);
                break;
            case 5:
                combos(order);
                break;
            default:
                return;
        }

        cout << "\nConfira seu pedido abaixo:" << endl;
        order->print();

        option = 0;

        while(option == 0){
            cout << "Selecione a opção desejada:" << endl;
            cout << "1 - Adicionar mais um item" << endl;
            cout << "2 - Pagar" << endl;
            cout << "Outro para voltar" << endl;
            cin >> option;

            if(option == 2){
                bool hasSuccess = pay(order);
                if(!hasSuccess){
                    option = 0;
                }
            }
        }
    }
}

bool Menu::pay(Order* order)
{
    int option = 0;

    cout << "\nVALOR TOTAL DO PEDIDO: RS " << order->getTotalValue() << endl;
    cout << "\nEscolha a forma de pagamento: " << endl;
    cout << "1 - Dinheiro" << endl;
    cout << "2 - Cartão" << endl;
    cout << "3 - Pix" << endl;
    cout << "Outro para voltar" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
        cout << "Pagamento em dinheiro" << endl;
        order->pay(money);
        return true;
    case 2:
        cout << "Pagamento em cartão" << endl;
        order->pay(card);
        return true;
    case 3:
        cout << "Pagamento em Pix" << endl;
        order->pay(pix);
        return true;
    default:
        return false;
    }
}

void Menu::snacks(Order* order)
{
    int snack = 0;
    int countSnack = 0;
    Item* selectedItem;
    vector<Snack*> snacks = {};
    int snackMenu = 1;

    for (Item* item : restaurant.getItems()) {
        if(dynamic_cast<Snack*>(item) != nullptr){
            snacks.push_back(dynamic_cast<Snack*>(item));
        }
    }

    if(snacks.empty()) {
        cout << "\nNo momento, não estamos oferencendo nenhum lanche, volte mais tarde!\n" << endl;
        return;
    }

    while(snackMenu == 1){
        cout << "Lanches" << endl;

        for (int i = 0; i < snacks.size(); i++) {
            cout << i + 1 << " - " << snacks[i]->getName() << endl;
        }

        cin >> snack;

        if(snack > snacks.size()){
            cout << "\nParece que essa opção não está disponível!\n" << endl;
            snackMenu = 1;
            continue;
        }

        selectedItem = snacks[snack - 1];

        cout << "Quantos deste lanche deseja adicionar?" << endl;
        cin >> countSnack;

        for(int i = 0; i < countSnack; i++){
            order->addItem(selectedItem);
        }

        cout << "Lanche adicionado ao carrinho!" << endl;

        cout << "Deseja adicionar mais algum lanche?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> snackMenu;
    }
}

void Menu::beverages(Order* order)
{
    int beverage = 0;
    int countBeverage = 0;
    Item* selectedItem;
    vector<Beverage*> beverages = {};
    int beverageMenu = 1;

    for (Item* item : restaurant.getItems()) {
        if(dynamic_cast<Beverage*>(item) != nullptr){
        beverages.push_back(dynamic_cast<Beverage*>(item));
        }
    }

    if(beverages.empty()) {
        cout << "\nNo momento, não estamos oferencendo nenhuma bebida, volte mais tarde!\n" << endl;
        return;
    }

    while(beverageMenu == 1){
        cout << "Bebidas" << endl;

        for (int i = 0; i < beverages.size(); i++) {
            cout << i + 1 << " - " << beverages[i]->getName() << endl;
        }

        cin >> beverage;

        if(beverage > beverages.size()){
            cout << "\nParece que essa opção não está disponível!\n" << endl;
            beverageMenu = 1;
            continue;
        }

        selectedItem = beverages[beverage - 1];

        cout << "Quantos desta bebida deseja adicionar?" << endl;
        cin >> countBeverage;

        for(int i = 0; i < countBeverage; i++){
            order->addItem(selectedItem);
        }

        cout << "Bebida adicionada ao carrinho!" << endl;

        cout << "Deseja adicionar mais alguma bebida?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> beverageMenu;
    }
}

void Menu::accompaniments(Order* order)
{
    int accompaniment = 0;
    int countAccompaniments = 0;
    Item* selectedItem;
    vector<Accompaniment*> accompaniments = {};
    int accompanimentMenu = 1;

    for (Item* item : restaurant.getItems()) {
        if(dynamic_cast<Beverage*>(item) != nullptr){
            accompaniments.push_back(dynamic_cast<Accompaniment*>(item));
        }
    }

    if(accompaniments.empty()) {
        cout << "\nNo momento, não estamos oferencendo nenhum acompanhamento, volte mais tarde!\n" << endl;
        return;
    }

    while(accompanimentMenu == 1){
        cout << "Acompanhamentos" << endl;

        for (int i = 0; i < accompaniments.size(); i++) {
            cout << i + 1 << " - " << accompaniments[i]->getName() << endl;
        }

        cin >> accompaniment;

        if(accompaniment > accompaniments.size()){
            cout << "\nParece que essa opção não está disponível!\n" << endl;
            accompanimentMenu = 1;
            continue;
        }

        selectedItem = accompaniments[accompaniment - 1];

        cout << "Quantos deste acompanhamento deseja adicionar?" << endl;
        cin >> countAccompaniments;

        for(int i = 0; i < countAccompaniments; i++){
            order->addItem(selectedItem);
        }

        cout << "Acompanhamento adicionado ao carrinho!" << endl;

        cout << "Deseja adicionar mais algum acompanhamento?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> accompanimentMenu;
    }
}

void Menu::desserts(Order* order)
{

    int dessert = 0;
    int countDessert = 0;
    Item* selectedItem;
    vector<Dessert*> desserts = {};
    int dessertMenu = 1;

    for (Item* item : restaurant.getItems()) {
        if(dynamic_cast<Dessert*>(item) != nullptr){
        desserts.push_back(dynamic_cast<Dessert*>(item));
        }
    }

    if(desserts.empty()) {
        cout << "\nNo momento, não estamos oferencendo nenhuma sobremesa, volte mais tarde!\n" << endl;
        return;
    }

    while(dessertMenu == 1){
        cout << "Sobremesas" << endl;

        for (int i = 0; i < desserts.size(); i++) {
            cout << i + 1 << " - " << desserts[i]->getName() << endl;
        }

        cin >> dessert;

        if(dessert > desserts.size()){
            cout << "\nParece que essa opção não está disponível!\n" << endl;
            dessertMenu = 1;
            continue;
        }

        selectedItem = desserts[dessert - 1];

        cout << "Quantos desta sobremesa deseja adicionar?" << endl;
        cin >> countDessert;

        for(int i = 0; i < countDessert; i++){
            order->addItem(selectedItem);
        }

        cout << "Sobremesa adicionada ao carrinho!" << endl;

        cout << "Deseja adicionar mais alguma sobremesa?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> dessertMenu;
    }
}

void Menu::combos(Order* order)
{
    int combo = 0;
    int countCombos = 0;
    Combo* selectedCombo;
    int comboMenu = 1;

    while(comboMenu == 1){
        cout << "Combos" << endl;

        for (int i = 0; i < restaurant.getCombos().size(); i++) {
            cout << i + 1 << " - " << restaurant.getCombos()[i]->toString() << endl;
        }

        cin >> combo;

        selectedCombo = restaurant.getCombos()[combo - 1];

        cout << "Quantos deste combo deseja adicionar?" << endl;
        cin >> countCombos;

        for(int i = 0; i < countCombos; i++){
            order->addCombo(selectedCombo);
        }

        cout << "Combo adicionado ao carrinho!" << endl;

        cout << "Deseja adicionar mais algum combo?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> comboMenu;
    }
}

void Menu::adminMenu()
{
    int opcao = 0;

    cout << "\nMENU ADMINISTRADOR" << endl;
    cout << "1 - Pedidos em andamento" << endl;
    cout << "2 - Quantidade de itens vendidos" << endl;
    cout << "3 - Faturamento do dia" << endl;
    cout << "Outro para voltar" << endl;
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        ordersInProduction();
        break;
    case 2:
        soldItems();
        break;
    case 3:
        billing();
        break;
    default:
        return;
    }
}

void Menu::ordersInProduction()
{
    cout << "Pedidos em andamento:" << endl;
    vector<Order*> orders = restaurant.getOrdersInProduction();

    for(Order* order : orders){
        order->print();
        cout << "\n" << endl;
    }
}

void Menu::soldItems()
{
    time_t currentTime = std::time(nullptr);
    tm* currentDate = localtime(&currentTime);
    Date* date = new Date(currentDate->tm_mday, currentDate->tm_mon, currentDate->tm_year);

    vector<Item*> items = restaurant.getItemsSoldByDate(date);
    vector<vector<Item*>> groupedItems = {};

    for(Item* item : items){
        bool existsOnGroupedItems = false;

        for(vector<Item*>& groupedItem : groupedItems){
            if(groupedItem[0]->getCode() == item->getCode()){
                groupedItem.push_back(item);
                existsOnGroupedItems = true;
            }
        }

        if(!existsOnGroupedItems){
            groupedItems.push_back({item});
        }
    }

    cout << "Itens vendidos:" << endl;
    for(vector<Item*> groupedItem : groupedItems){
        cout << groupedItem.size() << "x - " << groupedItem[0]->getName() << endl;
    }
}

void Menu::billing()
{
    time_t currentTime = std::time(nullptr);
    tm* currentDate = localtime(&currentTime);
    Date* date = new Date(currentDate->tm_mday, currentDate->tm_mon, currentDate->tm_year);

    cout << "Faturamento do dia: R$" << restaurant.getBillingByDate(date) << endl;
}
