#include <iostream> // biblioteca para entrada e saída de dados
#include "funcoes.h" // inclui funções (f1, f2, f3), somaPares e produto
#include "lista.h"   // inclui as funções e structs para manipulação de listas
#include "menus.h"   // inclui funções que mostram os menus e retornam opções
using namespace std;

/* main.cpp contém a função principal do programa, responsável por controlar o fluxo geral, além de
fazer as chamadas aos menus e às funções recursivas definidas em outros arquivos. */
int main()
{
    int opcQuestao, opcFunc, opcEntrada; // variáveis para armazenar opções dos menus

    do
    {
        opcQuestao = MenuQuestoes(); // exibe menu principal e retorna a questão escolhida

        switch (opcQuestao)
        {
        case 1: // QUESTAO 1 -> f1, f2, f3
            do
            {
                opcFunc = MenuEntradas1(); // menu das funções (f1, f2, f3)
                switch (opcFunc)
                {
                case 1: // f1
                    do
                    {
                        opcEntrada = MenuSubEntradas1(); // submenu com entradas específicas
                        switch (opcEntrada)
                        {
                        case 1:
                            cout << "f1(0) = " << f1(0) << endl; // chama f1 com 0
                            break;
                        case 2:
                            cout << "f1(1) = " << f1(1) << endl; // chama f1 com 1
                            break;
                        case 3:
                            cout << "f1(5) = " << f1(5) << endl; // chama f1 com 5
                            break;
                        }
                    } while (opcEntrada != 4); // repetir até escolher voltar
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
                            f3(0); // f3 imprime diretamente, por isso não precisa de cout completo
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
            } while (opcFunc != 4); // repetir até escolher voltar
            break;

        case 2: // QUESTAO 2 -> somaPares
        { 
            int n;
            cout << "Digite um numero: ";
            cin >> n;
            cout << "Soma dos pares de 0 ate " << n << " = " << somaPares(n) << endl; // chama função que soma pares
            break;
        }

        case 3: // QUESTAO 3 -> produto
        {
            int a, b;
            cout << "Digite o valor de a: ";
            cin >> a;
            cout << "Digite o valor de b: ";
            cin >> b;
            cout << a << " * " << b << " = " << produto(a, b) << endl; // chama função que multiplica
            break;
        }

        case 4: // QUESTAO 4 -> lista encadeada
        { 
            Node *lista = nullptr; // lista inicialmente vazia
            int opcao, valor;

            do
            {
                opcao = MenuLista(); // menu de operações da lista

                switch (opcao)
                {
                case 1: // inserir
                    cout << "Digite o valor a inserir: ";
                    cin >> valor; 
                    lista = inserir(lista, valor); // cria um novo Node com esse valor e adiciona no início da lista
                    break;
                case 2: // imprimir
                    cout << "Lista: ";
                    imprimir(lista); // percorre todos os nós da lista e mostra o valor de cada um
                    cout << endl;
                    break;
                case 3: // buscar
                    cout << "Digite o valor a consultar: ";
                    cin >> valor;
                    if (buscar(lista, valor)) // percorre a lista nó a nó até achar o valor.
                        cout << "Registro encontrado!" << endl;
                    else
                        cout << "Registro nao encontrado." << endl;
                    break;
                case 4: // excluir
                    cout << "Digite o valor a excluir: ";
                    cin >> valor;
                    lista = excluir(lista, valor); // procura o nó com esse valor e o remove da lista
                    cout << "Registro excluido (se existia)." << endl;
                    break;
                case 5: // voltar
                    cout << "Retornando ao menu de questoes..." << endl;
                    break; // encerra o loop da lista e retorna para o menu principal
                default:
                    cout << "Opcao invalida!" << endl;
                }
            } while (opcao != 5);

            // liberar memória da lista antes de sair
            while (lista != nullptr) // percorre toda a lista e deleta cada nó, liberando a memória
            {
                Node *temp = lista;
                lista = lista->next;
                delete temp;
            }
            break;
        }

        case 5: // encerrar programa
            cout << "Encerrando programa..." << endl;
            break;

        default:
            cout << "Opcao invalida!" << endl; // para entradas fora das opções válidas do menu principal
        }
    } while (opcQuestao != 5); // repetir até escolher encerrar

    return 0; // quando o programa termina corretamente
}
