#include <iostream>
#include "funcoes.h"
#include "lista.h"
#include "menus.h"
using namespace std;

int main()
{
    int opcQuestao, opcFunc, opcEntrada;

    do
    {
        opcQuestao = MenuQuestoes();

        switch (opcQuestao)
        {
        case 1: // QUESTAO 1 -> f1, f2, f3
            do
            {
                opcFunc = MenuEntradas1();
                switch (opcFunc)
                {
                case 1: // f1
                    do
                    {
                        opcEntrada = MenuSubEntradas1();
                        switch (opcEntrada)
                        {
                        case 1:
                            cout << "f1(0) = " << f1(0) << endl;
                            break;
                        case 2:
                            cout << "f1(1) = " << f1(1) << endl;
                            break;
                        case 3:
                            cout << "f1(5) = " << f1(5) << endl;
                            break;
                        }
                    } while (opcEntrada != 4);
                    break;

                case 2: // f2
                    do
                    {
                        opcEntrada = MenuSubEntradas1();
                        switch (opcEntrada)
                        {
                        case 1:
                            cout << "f2(0) = " << f2(0) << endl;
                            break;
                        case 2:
                            cout << "f2(1) = " << f2(1) << endl;
                            break;
                        case 3:
                            cout << "f2(5) = " << f2(5) << endl;
                            break;
                        }
                    } while (opcEntrada != 4);
                    break;

                case 3: // f3
                    do
                    {
                        opcEntrada = MenuSubEntradas1();
                        switch (opcEntrada)
                        {
                        case 1:
                            cout << "f3(0) = ";
                            f3(0);
                            cout << endl;
                            break;
                        case 2:
                            cout << "f3(1) = ";
                            f3(1);
                            cout << endl;
                            break;
                        case 3:
                            cout << "f3(5) = ";
                            f3(5);
                            cout << endl;
                            break;
                        }
                    } while (opcEntrada != 4);
                    break;
                }
            } while (opcFunc != 4);
            break;

        case 2:
        { // QUESTAO 2
            int n;
            cout << "Digite um numero: ";
            cin >> n;
            cout << "Soma dos pares de 0 ate " << n << " = " << somaPares(n) << endl;
            break;
        }

        case 3:
        { // QUESTAO 3
            int a, b;
            cout << "Digite o valor de a: ";
            cin >> a;
            cout << "Digite o valor de b: ";
            cin >> b;
            cout << a << " * " << b << " = " << produto(a, b) << endl;
            break;
        }

        case 4:
        { // QUESTAO 4
            Node *lista = nullptr;
            int opcao, valor;

            do
            {
                opcao = MenuLista();

                switch (opcao)
                {
                case 1:
                    cout << "Digite o valor a inserir: ";
                    cin >> valor;
                    lista = inserir(lista, valor);
                    break;
                case 2:
                    cout << "Lista: ";
                    imprimir(lista);
                    cout << endl;
                    break;
                case 3:
                    cout << "Digite o valor a consultar: ";
                    cin >> valor;
                    if (buscar(lista, valor))
                        cout << "Registro encontrado!" << endl;
                    else
                        cout << "Registro nao encontrado." << endl;
                    break;
                case 4:
                    cout << "Digite o valor a excluir: ";
                    cin >> valor;
                    lista = excluir(lista, valor);
                    cout << "Registro excluido (se existia)." << endl;
                    break;
                case 5:
                    cout << "Retornando ao menu de questoes..." << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                }
            } while (opcao != 5);

            // liberar memória
            while (lista != nullptr)
            {
                Node *temp = lista;
                lista = lista->next;
                delete temp;
            }
            break;
        }

        case 5:
            cout << "Encerrando programa..." << endl;
            break;

        default:
            cout << "Opcao invalida!" << endl;
        }
    } while (opcQuestao != 5);

    return 0;
}
