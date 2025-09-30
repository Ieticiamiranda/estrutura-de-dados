#include <iostream>
#include "pilha.h"
using namespace std;

void inicializar(Pilha &p)
{
    p.topo = nullptr;
    p.tamanho = 0;
}

void push(Pilha &p, int valor)
{
    NoPilha *novo = new NoPilha;
    novo->info = valor;
    novo->prox = p.topo;
    p.topo = novo;
    p.tamanho++;
}

int pop(Pilha &p)
{
    if (p.topo == nullptr)
    {
        cout << "Erro: pilha vazia!" << endl;
        return -1;
    }
    NoPilha *temp = p.topo;
    int valor = temp->info;
    p.topo = temp->prox;
    delete temp;
    p.tamanho--;
    return valor;
}

void listar(Pilha &p)
{
    if (p.topo == nullptr)
    {
        cout << "Pilha vazia!" << endl;
        return;
    }
    NoPilha *aux = p.topo;
    cout << "Conteudo da pilha (do topo para base):" << endl;
    while (aux != nullptr)
    {
        cout << aux->info << endl;
        aux = aux->prox;
    }
}

bool contem(Pilha &p, int valor)
{
    NoPilha *aux = p.topo;
    while (aux != nullptr)
    {
        if (aux->info == valor)
            return true;
        aux = aux->prox;
    }
    return false;
}

void liberarPilha(Pilha &p)
{
    while (p.topo != nullptr)
    {
        pop(p);
    }
}
