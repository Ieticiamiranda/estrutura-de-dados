#include <iostream> // biblioteca para entrada e saída de dados
#include "lista.h"  // inclui as funções para manipulação de listas
#include "pilha.h"  // inclui as funções para manipulação de pilhas
#include "fila.h"   // inclui as funções para manipulação de filas
#include "menus.h"  // inclui funções que mostram os menus e retornam opções
using namespace std;

/* main.cpp contém a função principal do programa, responsável por controlar o fluxo geral, além de
fazer as chamadas aos menus e às funções recursivas definidas em outros arquivos. */
int main()
{
    int opcao; // variável para armazenar a escolha do usuário no menu principal

    do
    {
        opcao = MenuQuestoes(); // exibe menu principal e retorna a questão escolhida

        switch (opcao)
        {
        case 1: // questao 1.) Lista
        {
            Node *lista = nullptr;   // cria uma lista inicialmente vazia
            int escolha, valor, pos; // variáveis auxiliares para o menu da lista
            do
            {
                escolha = MenuLista(); // mostra o menu de operações da lista
                switch (escolha)
                {
                case 1:
                    lista = criarListaVazia(); // inicializa a lista
                    cout << "Lista criada com sucesso!" << endl;
                    break;
                case 2:
                    cout << "Digite um valor: ";
                    cin >> valor;
                    inserirElemento(lista, valor); // insere o valor no final da lista
                    break;
                case 3:
                    percorrerLista(lista); // percorre e imprime todos os elementos da lista
                    break;
                case 4:
                    cout << "Digite a posicao: ";
                    cin >> pos;
                    valor = obterElemento(lista, pos); // pega o elemento da posição indicada
                    if (valor != -1)
                        cout << "Elemento na posicao " << pos << ": " << valor << endl;
                    else
                        cout << "Posicao invalida!" << endl; // -1 indica posição inexistente
                    break;
                case 5:
                    cout << "Tamanho da lista: " << tamanhoLista(lista) << endl; // mostra quantos elementos tem na lista
                    break;
                case 6:
                    cout << "Voltando ao menu principal..." << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl; // caso a entrada seja uma opcao invalida
                }
            } while (escolha != 6); // repete até a escolha voltar ser selecionada
            break;
        }
        case 2: // questao 2.) Pilha
        {
            Pilha p;
            inicializar(p); // inicializa a pilha (topo = nullptr, tamanho = 0)
            int escolha, valor;
            do
            {
                escolha = MenuPilha(); // mostra o menu de operações da pilha
                switch (escolha)
                {
                case 1:
                    cout << "Digite um valor: ";
                    cin >> valor;
                    push(p, valor); // adiciona valor no topo da pilha
                    break;
                case 2:
                    valor = pop(p); // remove e retorna o valor do topo
                    if (valor != -1)
                        cout << "Removido: " << valor << endl;
                    break;
                case 3:
                    listar(p); // imprime todos os elementos da pilha
                    break;
                case 4:
                    cout << "Digite o valor para buscar: ";
                    cin >> valor;
                    cout << (contem(p, valor) ? "Valor encontrado." : "Valor nao encontrado.") << endl;
                    break;
                case 5:
                    liberarPilha(p); // libera a memória da pilha
                    cout << "Voltando ao menu principal..." << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                }
            } while (escolha != 5); // repete até a escolha voltar ser selecionada
            break;
        }
        case 3: // questao 3.) Fila
        {
            Fila f;
            inicializar(f); // inicializa a fila (inicio e fim = nullptr)
            int escolha, valor;
            do
            {
                escolha = MenuFila(); // mostra o menu de operações da fila
                switch (escolha)
                {
                case 1:
                    cout << "Digite um valor: ";
                    cin >> valor;
                    enqueue(f, valor); // adiciona valor no final da fila
                    break;
                case 2:
                    valor = dequeue(f); // remove valor do início da fila
                    if (valor != -1)
                        cout << "Removido: " << valor << endl;
                    break;
                case 3:
                    listar(f); // imprime todos os elementos da fila
                    break;
                case 4:
                    cout << "Digite o valor para buscar: ";
                    cin >> valor;
                    cout << (contem(f, valor) ? "Valor encontrado." : "Valor nao encontrado.") << endl; // busca um valor na fila
                    break;
                case 5:
                    liberarFila(f); // libera memória da fila
                    cout << "Voltando ao menu principal..." << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                }
            } while (escolha != 5); // repete até a escolha voltar ser selecionada
            break;
        }
        case 4:                                      // opção para sair do programa
            cout << "Saindo do programa..." << endl; // encerra o programa
            break;
        default:
            cout << "Opcao invalida! Tente novamente." << endl; // se a entrada for alguma opcao invalida no menu principal
        }
    } while (opcao != 4); // se não, mantém o menu principal até escolher sair

    return 0; // programa encerrado com sucesso
}
