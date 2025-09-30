#ifndef LISTA_H
#define LISTA_H

struct Node {
    int info;
    Node* next;
};

Node* criarListaVazia();
void inserirElemento(Node*& head, int valor);
void percorrerLista(Node* head);
int tamanhoLista(Node* head);
int obterElemento(Node* head, int pos);

#endif
