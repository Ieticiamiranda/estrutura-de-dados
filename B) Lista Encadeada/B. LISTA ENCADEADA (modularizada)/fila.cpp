#include <iostream>
#include "fila.h"
using namespace std;

void inicializar(Fila &f)
{
    f.frente = nullptr;
    f.tras = nullptr;
    f.tamanho = 0;
}

void enqueue(Fila &f, int valor)
{
    NoFila *novo = new NoFila;
    novo->info = valor;
    novo->prox = nullptr;
    if (f.tras == nullptr)
    {
        f.frente = novo;
    }
    else
    {
        f.tras->prox = novo;
    }
    f.tras = novo;
    f.tamanho++;
}

int dequeue(Fila &f)
{
    if (f.frente == nullptr)
    {
        cout << "Erro: fila vazia!" << endl;
        return -1;
    }
    NoFila *temp = f.frente;
    int valor = temp->info;
    f.frente = f.frente->prox;
    if (f.frente == nullptr)
        f.tras = nullptr;
    delete temp;
    f.tamanho--;
    return valor;
}

void listar(Fila &f)
{
    if (f.frente == nullptr)
    {
        cout << "Fila vazia!" << endl;
        return;
    }
    NoFila *aux = f.frente;
    cout << "Conteudo da fila (da frente para o fim):" << endl;
    while (aux != nullptr)
    {
        cout << aux->info << " ";
        aux = aux->prox;
    }
    cout << endl;
}

bool contem(Fila &f, int valor)
{
    NoFila *aux = f.frente;
    while (aux != nullptr)
    {
        if (aux->info == valor)
            return true;
        aux = aux->prox;
    }
    return false;
}

void liberarFila(Fila &f)
{
    while (f.frente != nullptr)
    {
        dequeue(f);
    }
}
