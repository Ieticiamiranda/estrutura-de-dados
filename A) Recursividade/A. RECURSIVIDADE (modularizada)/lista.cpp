#include <iostream>
using namespace std;
#include "lista.h"

void imprimir(Node *head)
{
    if (head == nullptr)
        return;
    cout << head->data << " ";
    imprimir(head->next);
}

bool buscar(Node *head, int valor)
{
    if (head == nullptr)
        return false;
    if (head->data == valor)
        return true;
    return buscar(head->next, valor);
}

Node *excluir(Node *head, int valor)
{
    if (head == nullptr)
        return nullptr;
    if (head->data == valor)
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
    head->next = excluir(head->next, valor);
    return head;
}

Node *inserir(Node *head, int valor)
{
    Node *novo = new Node;
    novo->data = valor;
    novo->next = head;
    return novo;
}
