#include "Item.hpp"
#include "Combo.hpp"
#include "Snack.hpp"
#include <vector>
#include <string>

using namespace std;

void Menu(){
    int opcao = 0;
    
    cout << "Bem vindo ao Sanduichero!" << endl;
    cout << "Escolha uma opção: " << endl;
    cout << "1 - Cliente" << endl;
    cout << "2 - Administrador" << endl;
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        menu_cliente();
        break;

    case 2:
        menu_administrador();
        break;
    
    default:
        cout << "Opção inválida!" << endl;
        Menu();
        break;
    }
}

void menu_cliente(){
    int opcao = 0;
    
    cout << "CARDÁPIO" << endl;
    cout << "1 - Lanches" << endl;
    cout << "2 - Bebidas" << endl;
    cout << "3 - Acompanhamentos" << endl;
    cout << "4 - Sobremesas" << endl;
    cout << "5 - Combos" << endl;
    cin >> opcao;

    int qtd_lanches = 0;
    int qtd_bebidas = 0;
    int qtd_acompanhamentos = 0;
    int qtd_sobremesas = 0;
    int qtd_combos = 0;
    
    switch (opcao)
    {
    case 1:
        int lanche = 0;
        cout << "Lanches" << endl;
        cout << "1 - X-Burguer" << endl;
        cout << "2 - X-Salada" << endl;
        cout << "3 - X-Bacon" << endl;
        cin >> lanche;

        switch (lanche){
            case 1:
                cout << "Quantos deste lanche deseja adicionar?" << endl;
                cin >> qtd_lanches;
                //fazer preço X qtd_lanches
                cout << "Lanche adicionado ao carrinho!" << endl;
                cout << "Deseja adicionar mais algum item?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                if (opcao == 1){
                    menu_cliente();
                }else{
                    finalizar();
                }

                break;

            case 2:
                cout << "Quantos deste lanche deseja adicionar?" << endl;
                cin >> qtd_lanches;
                //fazer preço X qtd_lanches
                cout << "Lanche adicionado ao carrinho!" << endl;
                cout << "Deseja adicionar mais algum item?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                if (opcao == 1){
                    menu_cliente();
                }else{
                    finalizar();
                }
                break;
            
            case 3:
                cout << "Quantos deste lanche deseja adicionar?" << endl;
                cin >> qtd_lanches;
                //fazer preço X qtd_lanches
                cout << "Lanche adicionado ao carrinho!" << endl;
                cout << "Deseja adicionar mais algum item?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                if (opcao == 1){
                    menu_cliente();
                }else{
                    finalizar();
                }
                break;
        
            default:
                cout << "Opção inválida!" << endl;
                cout << "Pressione ENTER para voltar ao menu principal" << endl;
                cin >> opcao;
                break;
        }
        break;

    case 2:
        int bebida = 0;
        cout << "Bebidas" << endl;
        cout << "1 - Refrigerante" << endl;
        cout << "2 - Suco" << endl;
        cout << "3 - Água" << endl;
        cin >> bebida;

        switch (bebida){
            case 1:
                cout << "Quantos desta bebida deseja adicionar?" << endl;
                cin >> qtd_bebidas;
                //fazer preço X qtd_bebidas
                cout << "Bebida adicionada ao carrinho!" << endl;
                cout << "Deseja adicionar mais algum item?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                if (opcao == 1){
                    menu_cliente();
                }else{
                    finalizar();
                }
                break;

            case 2:
                cout << "Quantos desta bebida deseja adicionar?" << endl;
                cin >> qtd_bebidas;
                //fazer preço X qtd_bebidas
                cout << "Bebida adicionada ao carrinho!" << endl;
                cout << "Deseja adicionar mais algum item?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                if (opcao == 1){
                    menu_cliente();
                }else{
                    finalizar();
                }
                break;
            
            case 3:
                cout << "Quantos desta bebida deseja adicionar?" << endl;
                cin >> qtd_bebidas;
                //fazer preço X qtd_bebidas
                cout << "Bebida adicionada ao carrinho!" << endl;
                cout << "Deseja adicionar mais algum item?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                if (opcao == 1){
                    menu_cliente();
                }else{
                    finalizar();
                }
                break;
        
            default:
                cout << "Opção inválida!" << endl;
                cout << "Pressione ENTER para voltar ao menu principal" << endl;
                cin >> opcao;
                break;
        }
        break;

    case 3:
        int acompanhamento = 0;
        cout << "Acompanhamentos" << endl;
        cout << "1 - Batata Frita" << endl;
        cout << "2 - Onion Rings" << endl;
        cout << "3 - Nuggets" << endl;
        cin >> acompanhamento;

        switch (acompanhamento){
            case 1:
                cout << "Quantos deste acompanhamento deseja adicionar?" << endl;
                cin >> qtd_acompanhamentos;
                //fazer preço X qtd_acompanhamentos
                cout << "Acompanhamento adicionado ao carrinho!" << endl;
                cout << "Deseja adicionar mais algum item?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                if (opcao == 1){
                    menu_cliente();
                }else{
                    finalizar();
                }
                break;

            case 2:
                cout << "Quantos deste acompanhamento deseja adicionar?" << endl;
                cin >> qtd_acompanhamentos;
                //fazer preço X qtd_acompanhamentos
                cout << "Acompanhamento adicionado ao carrinho!" << endl;
                cout << "Deseja adicionar mais algum item?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                if (opcao == 1){
                    menu_cliente();
                }else{
                    finalizar();
                }
                break;
            
            case 3:
                cout << "Quantos deste acompanhamento deseja adicionar?" << endl;
                cin >> qtd_acompanhamentos;
                //fazer preço X qtd_acompanhamentos
                cout << "Acompanhamento adicionado ao carrinho!" << endl;
                cout << "Deseja adicionar mais algum item?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                if (opcao == 1){
                    menu_cliente();
                }else{
                    finalizar();
                }
                break;
        
            default:
                cout << "Opção inválida!" << endl;
                cout << "Pressione ENTER para voltar ao menu principal" << endl;
                cin >> opcao;
                break;
        }
        break;
    
    case 4:
        int sobremesa = 0;
        cout << "Sobremesas" << endl;
        cout << "1 - Sorvete" << endl;
        cout << "2 - Petit Gateau" << endl;
        cout << "3 - Torta de Limão" << endl;
        cin >> sobremesa;

        switch (sobremesa){
            case 1:
                cout << "Quantos desta sobremesa deseja adicionar?" << endl;
                cin >> qtd_sobremesas;
                //fazer preço X qtd_sobremesas
                cout << "Sobremesa adicionada ao carrinho!" << endl;
                cout << "Deseja adicionar mais algum item?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                if (opcao == 1){
                    menu_cliente();
                }else{
                    finalizar();
                }
                break;

            case 2:
                cout << "Quantos desta sobremesa deseja adicionar?" << endl;
                cin >> qtd_sobremesas;
                //fazer preço X qtd_sobremesas
                cout << "Sobremesa adicionada ao carrinho!" << endl;
                cout << "Deseja adicionar mais algum item?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                if (opcao == 1){
                    menu_cliente();
                }else{
                    finalizar();
                }
                break;
            
            case 3:
                cout << "Quantos desta sobremesa deseja adicionar?" << endl;
                cin >> qtd_sobremesas;
                //fazer preço X qtd_sobremesas
                cout << "Sobremesa adicionada ao carrinho!" << endl;
                cout << "Deseja adicionar mais algum item?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                if (opcao == 1){
                    menu_cliente();
                }else{
                    finalizar();
                }
                break;
        
            default:
                cout << "Opção inválida!" << endl;
                cout << "Pressione ENTER para voltar ao menu principal" << endl;
                cin >> opcao;
                break;
        }
        break;
    
    case 5:
        int combo = 0;
        cout << "Combos" << endl;
        cout << "1 - Combo 1" << endl;
        cout << "2 - Combo 2" << endl;
        cout << "3 - Combo 3" << endl;
        cin >> combo;

        switch (combo){
            case 1:
                cout << "Quantos deste combo deseja adicionar?" << endl;
                cin >> qtd_combos;
                //fazer preço X qtd_combos
                cout << "Combo adicionado ao carrinho!" << endl;
                cout << "Deseja adicionar mais algum item?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                if (opcao == 1){
                    menu_cliente();
                }else{
                    finalizar();
                }
                break;

            case 2:
                cout << "Quantos deste combo deseja adicionar?" << endl;
                cin >> qtd_combos;
                //fazer preço X qtd_combos
                cout << "Combo adicionado ao carrinho!" << endl;
                cout << "Deseja adicionar mais algum item?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                if (opcao == 1){
                    menu_cliente();
                }else{
                    finalizar();
                }
                break;
            
            case 3:
                cout << "Quantos deste combo deseja adicionar?" << endl;
                cin >> qtd_combos;
                //fazer preço X qtd_combos
                cout << "Combo adicionado ao carrinho!" << endl;
                cout << "Deseja adicionar mais algum item?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                if (opcao == 1){
                    menu_cliente();
                }else{
                    finalizar();
                }
                break;
        
            default:
                cout << "Opção inválida!" << endl;
                cout << "Pressione ENTER para voltar ao menu principal" << endl;
                cin >> opcao;
                break;
        }
        break;

    default:
        cout << "Opção inválida!" << endl;
        cout << "Pressione ENTER para voltar ao menu principal" << endl;
        cin >> opcao;
        menu_cliente();
        break;
    }
}

void finalizar(){
    cout << "Pedido finalizado!" << endl;
    cout << "Escolha a forma de pagamento: " << endl;
    cout << "1 - Dinheiro" << endl;
    cout << "2 - Cartão" << endl;
    cout << "3 - Pix" << endl;
    cout << "4 - Calcelar" << endl;
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
        //zerar contador de valor
        cout << "Pedido cancelado!" << endl;
        break;
    default:
        break;
    }
    cout << "Obrigado por escolher o Sanduichero!" << endl;
}

void menu_administrador(){
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
        faturamento_dia();
        break;
    
    default:
        cout << "Opção inválida!" << endl;
        cout << "Pressione ENTER para voltar ao menu principal" << endl;
        cin >> opcao;
        menu_administrador();
        break;
    }
}
