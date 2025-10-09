#ifndef LISTA_H // impede que o arquivo seja incluído mais de uma vez, evitando erros de compilação
#define LISTA_H

// define o nó da lista encadeada
struct Node
{
    int info;   // armazena o valor do nó
    Node *next; // ponteiro para o próximo nó
};

/* protótipos da funções da questão 1 (lista)
isso permite que o main saiba que essas funções existem,
mesmo que estejam definidas em outro arquivo */

Node *criarListaVazia();
void inserirElemento(Node *&head, int valor);
void percorrerLista(Node *head);
int tamanhoLista(Node *head);
int obterElemento(Node *head, int pos);

#endif
