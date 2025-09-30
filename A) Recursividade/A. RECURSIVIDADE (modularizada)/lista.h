#ifndef LISTA_H
#define LISTA_H

struct Node {
    int data;
    Node *next;
};

void imprimir(Node *head);
bool buscar(Node *head, int valor);
Node* excluir(Node *head, int valor);
Node* inserir(Node *head, int valor);

#endif
