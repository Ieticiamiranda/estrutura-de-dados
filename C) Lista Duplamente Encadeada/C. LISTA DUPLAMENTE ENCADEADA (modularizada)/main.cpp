#include <iostream>
#include "listas1.h"
#include "listas2.h"
#include "listas3.h"
#include "menus.h"
using namespace std;

int main()
{
    int opcao;
    No1 *lista1 = nullptr;
    ListaDupla lista2;
    No3 *lista3 = nullptr;

    do
    {
        opcao = MenuQuestoes();
        switch (opcao)
        {
        case 1:
        {
            int opcLista1;
            do
            {
                MenuListaCase1();
                cin >> opcLista1;
                switch (opcLista1)
                {
                case 1:
                {
                    int valor, pos;
                    cout << "Digite o valor a inserir: ";
                    cin >> valor;
                    cout << "Digite a posicao (0 para inicio): ";
                    cin >> pos;
                    inserir(lista1, valor, pos);
                    break;
                }
                case 2:
                    imprimir(lista1);
                    break;
                case 3:
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
                case 4:
                {
                    int pos;
                    cout << "Digite a posicao do elemento a excluir: ";
                    cin >> pos;
                    excluir(lista1, pos);
                    break;
                }
                case 5:
                    cout << "Voltando ao menu principal..." << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                }
            } while (opcLista1 != 5);
            break;
        }

        case 2:
        {
            int opcLista2;
            do
            {
                MenuListaCase2();
                cin >> opcLista2;
                switch (opcLista2)
                {
                case 1:
                {
                    int valor;
                    cout << "Digite o valor a inserir: ";
                    cin >> valor;
                    lista2.InserirInicioLD(valor);
                    break;
                }
                case 2:
                    lista2.ImprimirLista();
                    break;
                case 3:
                    cout << "Voltando ao menu principal..." << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                }
            } while (opcLista2 != 3);
            break;
        }

        case 3:
        {
            int opcLista3;
            do
            {
                MenuListaCase3();
                cin >> opcLista3;
                switch (opcLista3)
                {
                case 1:
                {
                    int valor;
                    cout << "Digite o valor: ";
                    cin >> valor;
                    inserirInicio(lista3, valor);
                    break;
                }
                case 2:
                {
                    int valor;
                    cout << "Digite o valor: ";
                    cin >> valor;
                    inserirFim(lista3, valor);
                    break;
                }
                case 3:
                {
                    int valor;
                    cout << "Digite o valor a remover: ";
                    cin >> valor;
                    remover(lista3, valor);
                    break;
                }
                case 4:
                    cout << "Lista: ";
                    imprimirRecursivo(lista3, lista3);
                    break;
                case 5:
                    cout << "Voltando ao menu principal...\n";
                    break;
                default:
                    cout << "Opcao invalida!\n";
                }
            } while (opcLista3 != 5);
            break;
        }

        case 4:
            cout << "Saindo do programa..." << endl;
            break;
        default:
            cout << "Opcao invalida! Tente novamente." << endl;
        }
    } while (opcao != 4);

    return 0;
}
