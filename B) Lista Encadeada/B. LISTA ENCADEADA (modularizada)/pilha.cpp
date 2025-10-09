#include <iostream>
#include "pilha.h" // inclui as funções para manipulação de pilhas
using namespace std;

// questão 2 - pilha

// inicializa a pilha vazia
void inicializar(Pilha &p)
{
    p.topo = nullptr; // topo vazio
    p.tamanho = 0;    // tamanho 0
}

// adiciona elemento no topo da pilha
void push(Pilha &p, int valor)
{
    NoPilha *novo = new NoPilha; // cria novo nó
    novo->info = valor;          // armazena valor
    novo->prox = p.topo;         // próximo nó aponta para o topo atual
    p.topo = novo;               // atualiza topo
    p.tamanho++;                 // incrementa tamanho
}

// remove e retorna elemento do topo
int pop(Pilha &p)
{
    if (p.topo == nullptr) // pilha vazia
    {
        cout << "Erro: pilha vazia!" << endl;
        return -1;
    }

    NoPilha *temp = p.topo; // nó a ser removido
    int valor = temp->info; // pega valor
    p.topo = temp->prox;    // atualiza topo
    delete temp;            // libera memória
    p.tamanho--;            // decrementa tamanho
    return valor;           // retorna valor removido
}

// imprime todos os elementos da pilha (do topo para a base)
void listar(Pilha &p)
{
    if (p.topo == nullptr)
    {
        cout << "Pilha vazia!" << endl;
        return;
    }

    NoPilha *aux = p.topo; // começa do topo
    cout << "Conteudo da pilha (do topo para base):" << endl;
    while (aux != nullptr)
    {
        cout << aux->info << endl; // imprime valor
        aux = aux->prox;           // vai para próximo nó
    }
}

// verifica se um valor existe na pilha
bool contem(Pilha &p, int valor)
{
    NoPilha *aux = p.topo; // começa do topo
    while (aux != nullptr)
    {
        if (aux->info == valor) // achou
            return true;
        aux = aux->prox;
    }
    return false; // não achou
}

// libera toda a memória da pilha
void liberarPilha(Pilha &p)
{
    while (p.topo != nullptr) // enquanto houver elementos
    {
        pop(p); // remove elemento do topo (já libera memória)
    }
}
