#ifndef LISTA_H // impede que o arquivo seja incluído mais de uma vez, evitando erros de compilação
#define LISTA_H

// define o nó da lista encadeada
struct Node {
    int data;      // armazena o valor do nó
    Node *next;    // ponteiro para o próximo nó na lista
};

/* protótipos da funções da questão 4 (lista encadeada)
isso permite que o main saiba que essas funções existem,
mesmo que estejam definidas em outro arquivo */

void imprimir(Node *head);          
bool buscar(Node *head, int valor);
Node* excluir(Node *head, int valor);
Node* inserir(Node *head, int valor);

#endif
