#include <iostream>
#include "listas1.h"
using namespace std;

No1 *criarNo(int valor)
{
    No1 *novo = new No1;
    novo->dado = valor;
    novo->prox = nullptr;
    novo->ant = nullptr;
    return novo;
}

void inserir(No1 *&cabeca, int valor, int pos)
{
    No1 *novo = criarNo(valor);
    if (pos == 0)
    {
        novo->prox = cabeca;
        if (cabeca != nullptr)
            cabeca->ant = novo;
        cabeca = novo;
        return;
    }
    No1 *temp = cabeca;
    int i = 0;
    while (temp != nullptr && i < pos - 1)
    {
        temp = temp->prox;
        i++;
    }
    if (temp == nullptr)
    {
        cout << "Posicao invalida!" << endl;
        delete novo;
        return;
    }
    novo->prox = temp->prox;
    novo->ant = temp;
    if (temp->prox != nullptr)
        temp->prox->ant = novo;
    temp->prox = novo;
}

void imprimir(No1 *cabeca)
{
    No1 *temp = cabeca;
    cout << "Lista: ";
    while (temp != nullptr)
    {
        cout << temp->dado << " ";
        temp = temp->prox;
    }
    cout << endl;
}

No1 *buscar(No1 *cabeca, int valor)
{
    No1 *temp = cabeca;
    while (temp != nullptr)
    {
        if (temp->dado == valor)
            return temp;
        temp = temp->prox;
    }
    return nullptr;
}

void excluir(No1 *&cabeca, int pos)
{
    if (cabeca == nullptr)
    {
        cout << "Lista vazia!" << endl;
        return;
    }
    No1 *temp = cabeca;
    if (pos == 0)
    {
        cabeca = cabeca->prox;
        if (cabeca != nullptr)
            cabeca->ant = nullptr;
        delete temp;
        return;
    }
    int i = 0;
    while (temp != nullptr && i < pos)
    {
        temp = temp->prox;
        i++;
    }
    if (temp == nullptr)
    {
        cout << "Posicao invalida!" << endl;
        return;
    }
    if (temp->ant != nullptr)
        temp->ant->prox = temp->prox;
    if (temp->prox != nullptr)
        temp->prox->ant = temp->ant;
    delete temp;
}
