#include <iostream>
using namespace std;
#include "lista.h" // inclui as funções e structs para manipulação de listas

// questao 4 - lista encadeada

// opcao 1.) imprimir a lista
// função recursiva que percorre a lista e imprime os valores
void imprimir(Node *head)
{
    if (head == nullptr) // caso base: chegou no final da lista
        return;
    cout << head->data << " "; // imprime o valor do nó atual
    imprimir(head->next);      // chama a função para o próximo nó
}

// opcao 2.) buscar um elemento na lista
// função recursiva que procura um valor na lista
bool buscar(Node *head, int valor)
{
    if (head == nullptr) // caso base: lista vazia ou fim da lista
        return false;
    if (head->data == valor) // se o valor do nó atual é o procurado
        return true;
    return buscar(head->next, valor); // chama a função para o próximo nó
}

// opcao 3.) excluir um elemento da lista
// função recursiva que remove o nó com o valor especificado
Node *excluir(Node *head, int valor)
{
    if (head == nullptr) // caso base: lista vazia
        return nullptr;
    if (head->data == valor) // se o nó atual é o que deve ser excluído
    {
        Node *temp = head->next; // salva o próximo nó
        delete head;             // libera memória do nó atual
        return temp;             // retorna o próximo nó para atualizar a lista
    }
    head->next = excluir(head->next, valor); // chama recursivamente para o próximo nó
    return head;                             // retorna a lista atualizada
}

// opcao 4.) inserir um elemento no início da lista
// função que cria um novo nó e insere no início da lista
Node *inserir(Node *head, int valor)
{
    Node *novo = new Node; // aloca memória para o novo nó
    novo->data = valor;    // define o valor do nó
    novo->next = head;     // aponta para o antigo início da lista
    return novo;           // retorna o novo nó como novo início da lista
}
