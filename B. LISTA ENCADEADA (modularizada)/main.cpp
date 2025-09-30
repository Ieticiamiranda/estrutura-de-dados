#include <iostream>
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "menus.h"
using namespace std;

int main()
{
    int opcao;

    do
    {
        opcao = MenuQuestoes();

        switch (opcao)
        {
        case 1:
        { // LISTA
            Node *lista = nullptr;
            int escolha, valor, pos;
            do
            {
                escolha = MenuLista();
                switch (escolha)
                {
                case 1:
                    lista = criarListaVazia();
                    cout << "Lista criada com sucesso!" << endl;
                    break;
                case 2:
                    cout << "Digite um valor: ";
                    cin >> valor;
                    inserirElemento(lista, valor);
                    break;
                case 3:
                    percorrerLista(lista);
                    break;
                case 4:
                    cout << "Digite a posicao: ";
                    cin >> pos;
                    valor = obterElemento(lista, pos);
                    if (valor != -1)
                        cout << "Elemento na posicao " << pos << ": " << valor << endl;
                    else
                        cout << "Posicao invalida!" << endl;
                    break;
                case 5:
                    cout << "Tamanho da lista: " << tamanhoLista(lista) << endl;
                    break;
                case 6:
                    cout << "Voltando ao menu principal..." << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                }
            } while (escolha != 6);
            break;
        }
        case 2:
        { // PILHA
            Pilha p;
            inicializar(p);
            int escolha, valor;
            do
            {
                escolha = MenuPilha();
                switch (escolha)
                {
                case 1:
                    cout << "Digite um valor: ";
                    cin >> valor;
                    push(p, valor);
                    break;
                case 2:
                    valor = pop(p);
                    if (valor != -1)
                        cout << "Removido: " << valor << endl;
                    break;
                case 3:
                    listar(p);
                    break;
                case 4:
                    cout << "Digite o valor para buscar: ";
                    cin >> valor;
                    cout << (contem(p, valor) ? "Valor encontrado." : "Valor nao encontrado.") << endl;
                    break;
                case 5:
                    liberarPilha(p);
                    cout << "Voltando ao menu principal..." << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                }
            } while (escolha != 5);
            break;
        }
        case 3:
        { // FILA
            Fila f;
            inicializar(f);
            int escolha, valor;
            do
            {
                escolha = MenuFila();
                switch (escolha)
                {
                case 1:
                    cout << "Digite um valor: ";
                    cin >> valor;
                    enqueue(f, valor);
                    break;
                case 2:
                    valor = dequeue(f);
                    if (valor != -1)
                        cout << "Removido: " << valor << endl;
                    break;
                case 3:
                    listar(f);
                    break;
                case 4:
                    cout << "Digite o valor para buscar: ";
                    cin >> valor;
                    cout << (contem(f, valor) ? "Valor encontrado." : "Valor nao encontrado.") << endl;
                    break;
                case 5:
                    liberarFila(f);
                    cout << "Voltando ao menu principal..." << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                }
            } while (escolha != 5);
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
