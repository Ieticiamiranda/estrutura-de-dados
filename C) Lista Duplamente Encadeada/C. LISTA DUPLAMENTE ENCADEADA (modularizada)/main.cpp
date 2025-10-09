#include <iostream>
#include "listas1.h" // contém funções e estruturas da lista da primeira questão
#include "listas2.h" // contém a classe e métodos da lista da segunda questão
#include "listas3.h" // contem funções e estruturas da lista da terceira questão
#include "menus.h"   // inclui funções que mostram os menus e retornam opções
using namespace std;

/* main.cpp contém a função principal do programa, responsável por controlar o fluxo geral, além de
fazer as chamadas aos menus e às funções recursivas definidas em outros arquivos. */
int main()
{
    int opcao;             // variável para armazenar a escolha do usuário no menu principal
    No1 *lista1 = nullptr; // ponteiro para a primeira lista
    ListaDupla lista2;     // objeto para a segunda lista
    No3 *lista3 = nullptr; // ponteiro para a terceira lista

    do
    {
        opcao = MenuQuestoes(); // exibe menu principal e retorna a questão escolhida
        switch (opcao)
        {
        case 1: // questao 1 - lista duplamente encadeada
        {
            int opcLista1; // armazena a escolha do usuário no submenu da lista 1
            do
            {
                MenuListaCase1(); // exibe o submenu de operações da lista1
                cin >> opcLista1;
                switch (opcLista1)
                {
                case 1: // inserir elemento em posição específica
                {
                    int valor, pos;
                    cout << "Digite o valor a inserir: ";
                    cin >> valor;
                    cout << "Digite a posicao (0 para inicio): ";
                    cin >> pos;
                    inserir(lista1, valor, pos); // chama função que insere na lista 1
                    break;
                }
                case 2: // imprimir toda a lista
                    imprimir(lista1);
                    break;
                case 3: // buscar um elemento pelo valor
                {
                    int valor;
                    cout << "Digite o valor a buscar: ";
                    cin >> valor;
                    No1 *encontrado = buscar(lista1, valor);
                    if (encontrado)
                        cout << "Elemento " << valor << " encontrado!" << endl;
                    else
                        cout << "Elemento " << valor << " nao encontrado!" << endl;
                    break;
                }
                case 4: // excluir elemento por posição
                {
                    int pos;
                    cout << "Digite a posicao do elemento a excluir: ";
                    cin >> pos;
                    excluir(lista1, pos); // chama função que remove elemento da lista 1
                    break;
                }
                case 5: // voltar ao menu principal
                    cout << "Voltando ao menu principal..." << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl; // entrada de opção inválida
                }
            } while (opcLista1 != 5);
            break;
        }

        case 2: // questao 2 - lista duplamente encadeada sem duplicação
        {
            int opcLista2;
            do
            {
                MenuListaCase2(); // exibe o submenu de operações da lista 2
                cin >> opcLista2;
                switch (opcLista2)
                {
                case 1: // inserir no início da lista duplamente encadeada
                {
                    int valor;
                    cout << "Digite o valor a inserir: ";
                    cin >> valor;
                    lista2.InserirInicioLD(valor); // chama método da classe
                    break;
                }
                case 2: // imprimir lista
                    lista2.ImprimirLista();
                    break;
                case 3: // volta ao menu principal
                    cout << "Voltando ao menu principal..." << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                }
            } while (opcLista2 != 3);
            break;
        }

        case 3: // questao 3 - lista duplamente encadeada circular
        {
            int opcLista3;
            do
            {
                MenuListaCase3(); // exibe o submenu de operações da lista 3
                cin >> opcLista3;
                switch (opcLista3)
                {
                case 1: // inserir valor no início
                {
                    int valor;
                    cout << "Digite o valor: ";
                    cin >> valor;
                    inserirInicio(lista3, valor);
                    break;
                }
                case 2: // inserir valor no fim
                {
                    int valor;
                    cout << "Digite o valor: ";
                    cin >> valor;
                    inserirFim(lista3, valor);
                    break;
                }
                case 3: // remover elemento por valor
                {
                    int valor;
                    cout << "Digite o valor a remover: ";
                    cin >> valor;
                    remover(lista3, valor);
                    break;
                }
                case 4: // imprimir lista recursivamente
                    cout << "Lista: ";
                    imprimirRecursivo(lista3, lista3);
                    break;
                case 5: // voltar ao menu principal
                    cout << "Voltando ao menu principal...\n";
                    break;
                default:
                    cout << "Opcao invalida!\n"; // entrada de opção inválida
                }
            } while (opcLista3 != 5);
            break;
        }

        case 4: // sair do programa
            cout << "Saindo do programa..." << endl;
            break;
        default:
            cout << "Opcao invalida! Tente novamente." << endl;
        }
    } while (opcao != 4); // loop principal até o usuário escolher sair

    return 0; // indica que o programa terminou com sucesso
}
