#include "Item.hpp"
#include "Combo.hpp"
#include "Snack.hpp"
#include "Beverage.hpp"
#include "Accompaniment.hpp"
#include "Dessert.hpp"
#include "Menu.hpp"
using namespace std;

Menu::Menu(string name, Restaurant restaurant)
{
    this->name = name;
    this->restaurant = restaurant;

    menu_inicial();
}

void Menu::menu_inicial()
{
    int opcao = 0;

    while (opcao == 0)
    {
        cout << "Bem vindo ao Sanduichero!" << endl;
        cout << "Escolha uma opção: " << endl;
        cout << "1 - Cliente" << endl;
        cout << "2 - Administrador" << endl;
        cout << "3 - Sair" << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            menu_cliente();
            opcao = 0;
            break;

        case 2:
            menu_admin();
            opcao = 0;
            break;
        case 3:
            cout << "Você escolheu Sair" << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
            opcao = 0;

            break;
        }
    }
}

void Menu::menu_cliente()
{
    int opcao = 0;
    string customerName = "";
    int customerCode;
    Customer* customer;


    while(opcao == 0){
        cout << "1 - Cadastro" << endl;
        cout << "2 - Login" << endl;
        cin >> opcao;
        
        switch (opcao)
        {
        case 1:
            cout << "Digite seu nome:" << endl;
            cin >> customerName;
            customer = new Customer(customerName);
            customerCode = customer->getCode();
            this->restaurant.addCustomer(*customer);

            cout << "Cliente cadastrado com sucesso! Utilize o código " << customerCode << " para realizer seus pedidos." << endl;
            
            opcao = 0;

            break;
        case 2:
            cout << "Digite seu código:" << endl;
            cin >> customerCode;

            customer = restaurant.getCustomerByCode(customerCode);

            if(customer == nullptr){
                cout << "Não foi possível encontrar um cliente com esse código!" << endl;
                opcao = 0;
            } else {
                customerName = customer->getName();
            }
            break;
        default:
            cout << "Opção inválida!" << endl;
            cout << "Pressione ENTER para voltar ao menu principal" << endl;
            cin >> opcao;
            opcao = 0;
            return;
        }
    }

    cout << "CARDÁPIO" << endl;
    cout << "1 - Lanches" << endl;
    cout << "2 - Bebidas" << endl;
    cout << "3 - Acompanhamentos" << endl;
    cout << "4 - Sobremesas" << endl;
    cout << "5 - Combos" << endl;
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        lanches();
        break;

    case 2:
        bebidas();
        break;

    case 3:
        acompanhamentos();
        break;

    case 4:
        sobremesas();
        break;

    case 5:
        combos();
        break;

    default:
        cout << "Opção inválida!" << endl;
        cout << "Pressione ENTER para voltar ao menu principal" << endl;
        cin >> opcao;
        menu_cliente();
        break;
    }
}

void Menu::finalizar()
{
    cout << "Pedido finalizado!" << endl;
    cout << "Escolha a forma de pagamento: " << endl;
    cout << "1 - Dinheiro" << endl;
    cout << "2 - Cartão" << endl;
    cout << "3 - Pix" << endl;
    cout << "4 - Cancelar" << endl;
    int opcao = 0;
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        cout << "Pagamento em dinheiro" << endl;
        break;

    case 2:
        cout << "Pagamento em cartão" << endl;
        break;

    case 3:
        cout << "Pagamento em Pix" << endl;
        break;

    case 4:
        // zerar contador de valor
        cout << "Pedido cancelado!" << endl;
        break;
    default:
        cout << "Opção inválida!" << endl;
        finalizar();
        break;
    }
    cout << "Obrigado por escolher o Sanduichero!" << endl;
}

void Menu::lanches()
{
    int lanche = 0;

    cout << "Lanches" << endl;
    vector<Snack> snacks = {};

    for (Item item : restaurant.getItems()) {
        if (dynamic_cast<Snack*>(item) != nullptr) {
        //     snacks.push_back(item);
        }
    }
    // tu consegue commitar? pra eu conseguir ver os erros aqui, estamos bem perto, depois que fizer pra lanche é só replicar
    // erro no item do lado do snack
    cout << "1 - X-Burguer" << endl;
    cout << "2 - X-Salada" << endl;
    cout << "3 - X-Bacon" << endl;
    cin >> lanche;

    int opcao = 0;
    int qtd_lanches = 0;

    switch (lanche)
    {
    case 1:
        cout << "Quantos deste lanche deseja adicionar?" << endl;
        cin >> qtd_lanches;
        // fazer preço X qtd_lanches
        cout << "Lanche adicionado ao carrinho!" << endl;
        cout << "Deseja adicionar mais algum item?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            menu_cliente();
            // aqui tem um
        }
        else
        {
            finalizar();
            // aqui
        }

        break;

    case 2:
        cout << "Quantos deste lanche deseja adicionar?" << endl;
        cin >> qtd_lanches;
        // fazer preço X qtd_lanches

        cout << "Lanche adicionado ao carrinho!" << endl;
        cout << "Deseja adicionar mais algum item?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            menu_cliente();
        }
        else
        {
            finalizar();
        }
        break;

    case 3:
        cout << "Quantos deste lanche deseja adicionar?" << endl;
        cin >> qtd_lanches;
        // fazer preço X qtd_lanches
        
        cout << "Lanche adicionado ao carrinho!" << endl;
        cout << "Deseja adicionar mais algum item?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            menu_cliente();
        }
        else
        {
            finalizar();
        }
        break;

    default:
        cout << "Opção inválida!" << endl;
        cout << "Pressione ENTER para voltar ao menu principal" << endl;
        cin >> opcao;
        break;
    }
}

void Menu::bebidas()
{
    int bebida = 0;
    cout << "Bebidas" << endl;
    cout << "1 - Refrigerante" << endl;
    cout << "2 - Suco" << endl;
    cout << "3 - Água" << endl;
    cin >> bebida;

    int qtd_bebidas = 0;
    int opcao = 0;

    switch (bebida)
    {
    case 1:
        cout << "Quantos desta bebida deseja adicionar?" << endl;
        cin >> qtd_bebidas;
        // fazer preço X qtd_bebidas
        cout << "Bebida adicionada ao carrinho!" << endl;
        cout << "Deseja adicionar mais algum item?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            menu_cliente();
        }
        else
        {
            finalizar();
        }
        break;

    case 2:
        cout << "Quantos desta bebida deseja adicionar?" << endl;
        cin >> qtd_bebidas;
        // fazer preço X qtd_bebidas
        cout << "Bebida adicionada ao carrinho!" << endl;
        cout << "Deseja adicionar mais algum item?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            menu_cliente();
        }
        else
        {
            finalizar();
        }
        break;

    case 3:
        cout << "Quantos desta bebida deseja adicionar?" << endl;
        cin >> qtd_bebidas;
        // fazer preço X qtd_bebidas
        cout << "Bebida adicionada ao carrinho!" << endl;
        cout << "Deseja adicionar mais algum item?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            menu_cliente();
        }
        else
        {
            finalizar();
        }
        break;

    default:
        cout << "Opção inválida!" << endl;
        cout << "Pressione ENTER para voltar ao menu principal" << endl;
        cin >> opcao;
        break;
    }
}

void Menu::acompanhamentos()
{
    int acompanhamento = 0;
    cout << "Acompanhamentos" << endl;
    cout << "1 - Batata Frita" << endl;
    cout << "2 - Onion Rings" << endl;
    cout << "3 - Nuggets" << endl;
    cin >> acompanhamento;

    int qtd_acompanhamentos = 0;
    int opcao = 0;

    switch (acompanhamento)
    {
    case 1:
        cout << "Quantos deste acompanhamento deseja adicionar?" << endl;
        cin >> qtd_acompanhamentos;
        // fazer preço X qtd_acompanhamentos
        cout << "Acompanhamento adicionado ao carrinho!" << endl;
        cout << "Deseja adicionar mais algum item?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            menu_cliente();
        }
        else
        {
            finalizar();
        }
        break;

    case 2:
        cout << "Quantos deste acompanhamento deseja adicionar?" << endl;
        cin >> qtd_acompanhamentos;
        // fazer preço X qtd_acompanhamentos
        cout << "Acompanhamento adicionado ao carrinho!" << endl;
        cout << "Deseja adicionar mais algum item?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            menu_cliente();
        }
        else
        {
            finalizar();
        }
        break;

    case 3:
        cout << "Quantos deste acompanhamento deseja adicionar?" << endl;
        cin >> qtd_acompanhamentos;
        // fazer preço X qtd_acompanhamentos
        cout << "Acompanhamento adicionado ao carrinho!" << endl;
        cout << "Deseja adicionar mais algum item?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            menu_cliente();
        }
        else
        {
            finalizar();
        }
        break;

    default:
        cout << "Opção inválida!" << endl;
        cout << "Pressione ENTER para voltar ao menu principal" << endl;
        cin >> opcao;
        break;
    }
}

void Menu::sobremesas()
{

    int sobremesa = 0;
    cout << "Sobremesas" << endl;
    cout << "1 - Sorvete" << endl;
    cout << "2 - Petit Gateau" << endl;
    cout << "3 - Torta de Limão" << endl;
    cin >> sobremesa;

    int qtd_sobremesas = 0;
    int opcao = 0;

    switch (sobremesa)
    {
    case 1:
        cout << "Quantos desta sobremesa deseja adicionar?" << endl;
        cin >> qtd_sobremesas;
        // fazer preço X qtd_sobremesas
        cout << "Sobremesa adicionada ao carrinho!" << endl;
        cout << "Deseja adicionar mais algum item?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            menu_cliente();
        }
        else
        {
            finalizar();
        }
        break;

    case 2:
        cout << "Quantos desta sobremesa deseja adicionar?" << endl;
        cin >> qtd_sobremesas;
        // fazer preço X qtd_sobremesas
        cout << "Sobremesa adicionada ao carrinho!" << endl;
        cout << "Deseja adicionar mais algum item?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            menu_cliente();
        }
        else
        {
            finalizar();
        }
        break;

    case 3:
        cout << "Quantos desta sobremesa deseja adicionar?" << endl;
        cin >> qtd_sobremesas;
        // fazer preço X qtd_sobremesas
        cout << "Sobremesa adicionada ao carrinho!" << endl;
        cout << "Deseja adicionar mais algum item?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            menu_cliente();
        }
        else
        {
            finalizar();
        }
        break;

    default:
        cout << "Opção inválida!" << endl;
        cout << "Pressione ENTER para voltar ao menu principal" << endl;
        cin >> opcao;
        break;
    }
}

void Menu::combos()
{

    int combo = 0;
    cout << "Combos" << endl;
    cout << "1 - Combo 1" << endl;
    cout << "2 - Combo 2" << endl;
    cout << "3 - Combo 3" << endl;
    cin >> combo;

    int qtd_combos = 0;
    int opcao = 0;

    switch (combo)
    {
    case 1:
        cout << "Quantos deste combo deseja adicionar?" << endl;
        cin >> qtd_combos;
        // fazer preço X qtd_combos
        cout << "Combo adicionado ao carrinho!" << endl;
        cout << "Deseja adicionar mais algum item?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            menu_cliente();
        }
        else
        {
            finalizar();
        }
        break;

    case 2:
        cout << "Quantos deste combo deseja adicionar?" << endl;
        cin >> qtd_combos;
        // fazer preço X qtd_combos
        cout << "Combo adicionado ao carrinho!" << endl;
        cout << "Deseja adicionar mais algum item?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            menu_cliente();
        }
        else
        {
            finalizar();
        }
        break;

    case 3:
        cout << "Quantos deste combo deseja adicionar?" << endl;
        cin >> qtd_combos;
        // fazer preço X qtd_combos
        cout << "Combo adicionado ao carrinho!" << endl;
        cout << "Deseja adicionar mais algum item?" << endl;
        cout << "1 - Sim" << endl;
        cout << "2 - Não" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            menu_cliente();
        }
        else
        {
            finalizar();
        }
        break;

    default:
        cout << "Opção inválida!" << endl;
        cout << "Pressione ENTER para voltar ao menu principal" << endl;
        cin >> opcao;
        break;
    }
}

void Menu::menu_admin()
{
    int opcao = 0;

    cout << "MENU ADMINISTRADOR" << endl;
    cout << "1 - Pedidos em andamento" << endl;
    cout << "2 - Quantidade de itens vendidos" << endl;
    cout << "3 - Faturamento do dia" << endl;
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        pedidos_andamento();
        break;

    case 2:
        itens_vendidos();
        break;

    case 3:
        faturamento();
        break;

    default:
        cout << "Opção inválida!" << endl;
        cout << "Pressione ENTER para voltar ao menu principal" << endl;
        cin >> opcao;
        menu_admin();
        break;
    }
}

int Menu::pedidos_andamento()
{

    int pedidos = 0;
    cout << "Pedidos em andamento:" << endl;
    return pedidos;
}

int Menu::itens_vendidos()
{
    int itens = 0;
    cout << "Itens vendidos:" << endl;
    return itens;
}

float Menu::faturamento()
{
    float faturamento = 0.00;
    cout << "Faturamento do dia:" << endl;
    return faturamento;
}
