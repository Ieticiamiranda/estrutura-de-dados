#include <iostream>
#include "listas3.h"
using namespace std;

void inserirInicio(No3 *&inicio, int valor)
{
    No3 *novo = new No3;
    novo->dado = valor;
    if (inicio == nullptr)
    {
        novo->prox = novo;
        novo->ant = novo;
        inicio = novo;
    }
    else
    {
        No3 *ultimo = inicio->ant;
        novo->prox = inicio;
        novo->ant = ultimo;
        ultimo->prox = novo;
        inicio->ant = novo;
        inicio = novo;
    }
}

void inserirFim(No3 *&inicio, int valor)
{
    if (inicio == nullptr)
    {
        inserirInicio(inicio, valor);
        return;
    }
    No3 *novo = new No3;
    novo->dado = valor;
    No3 *ultimo = inicio->ant;
    ultimo->prox = novo;
    novo->ant = ultimo;
    novo->prox = inicio;
    inicio->ant = novo;
}

void remover(No3 *&inicio, int valor)
{
    if (inicio == nullptr)
    {
        cout << "Lista vazia!\n";
        return;
    }
    No3 *atual = inicio;
    bool encontrado = false;
    do
    {
        if (atual->dado == valor)
        {
            encontrado = true;
            break;
        }
        atual = atual->prox;
    } while (atual != inicio);

    if (!encontrado)
    {
        cout << "Elemento " << valor << " nao encontrado.\n";
        return;
    }

    if (atual->prox == atual)
    {
        delete atual;
        inicio = nullptr;
        return;
    }

    atual->ant->prox = atual->prox;
    atual->prox->ant = atual->ant;
    if (atual == inicio)
        inicio = atual->prox;
    delete atual;
}

void imprimirRecursivo(No3 *inicio, No3 *atual, bool primeiraChamada)
{
    if (inicio == nullptr)
    {
        cout << "Lista vazia!\n";
        return;
    }
    if (!primeiraChamada && atual == inicio)
    {
        cout << endl;
        return;
    }
    cout << atual->dado << " ";
    imprimirRecursivo(inicio, atual->prox, false);
}
