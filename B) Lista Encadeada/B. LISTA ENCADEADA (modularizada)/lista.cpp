#include <iostream>
#include "lista.h" // inclui as funções para manipulação de listas
using namespace std;

// questão 1 - lista encadeada

// cria e retorna uma lista vazia (nullptr)
Node *criarListaVazia()
{
    return nullptr;
}

// insere um elemento no início da lista
void inserirElemento(Node *&head, int valor)
{
    Node *novo = new Node; // cria um novo nó
    novo->info = valor;    // armazena o valor
    novo->next = head;     // aponta para o início atual da lista
    head = novo;           // atualiza o início da lista
}

// percorre a lista e imprime todos os elementos
void percorrerLista(Node *head)
{
    if (!head) // lista vazia
    {
        cout << "Lista vazia!" << endl;
        return;
    }

    Node *atual = head; // começa do primeiro elemento
    cout << "Elementos da lista: ";
    while (atual != nullptr)
    {
        cout << atual->info << " "; // imprime o valor
        atual = atual->next;        // vai para o próximo nó
    }
    cout << endl;
}

// retorna o número de elementos da lista
int tamanhoLista(Node *head)
{
    int count = 0;
    Node *atual = head;
    while (atual != nullptr)
    {
        count++;
        atual = atual->next;
    }
    return count;
}

// retorna o elemento da posição indicada (0 é o primeiro)
int obterElemento(Node *head, int pos)
{
    int i = 0;
    Node *atual = head;
    while (atual != nullptr)
    {
        if (i == pos)
            return atual->info; // achou o elemento
        atual = atual->next;
        i++;
    }
    return -1; // posição inválida
}
