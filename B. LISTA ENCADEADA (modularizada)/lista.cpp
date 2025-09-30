#include <iostream>
#include "lista.h"
using namespace std;

Node *criarListaVazia() { return nullptr; }

void inserirElemento(Node *&head, int valor)
{
    Node *novo = new Node;
    novo->info = valor;
    novo->next = head;
    head = novo;
}

void percorrerLista(Node *head)
{
    if (!head)
    {
        cout << "Lista vazia!" << endl;
        return;
    }
    Node *atual = head;
    cout << "Elementos da lista: ";
    while (atual != nullptr)
    {
        cout << atual->info << " ";
        atual = atual->next;
    }
    cout << endl;
}

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

int obterElemento(Node *head, int pos)
{
    int i = 0;
    Node *atual = head;
    while (atual != nullptr)
    {
        if (i == pos)
            return atual->info;
        atual = atual->next;
        i++;
    }
    return -1; // posição inválida
}
