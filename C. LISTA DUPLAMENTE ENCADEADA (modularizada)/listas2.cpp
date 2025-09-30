#include <iostream>
#include "listas2.h"
using namespace std;

ListaDupla::ListaDupla()
{
    inicio = nullptr;
    fim = nullptr;
    tamanho = 0;
}

bool ListaDupla::ListaVaziaLD() { return inicio == nullptr; }

void ListaDupla::InserirInicioLD(int k)
{
    NO2 *atual = inicio;
    while (atual != nullptr)
    {
        if (atual->info == k)
        {
            cout << "Elemento " << k << " ja existente na lista. Insercao nao realizada." << endl;
            return;
        }
        atual = atual->prox;
    }
    NO2 *novo = new NO2;
    novo->info = k;
    novo->ant = nullptr;
    if (ListaVaziaLD())
    {
        novo->prox = nullptr;
        inicio = fim = novo;
    }
    else
    {
        novo->prox = inicio;
        inicio->ant = novo;
        inicio = novo;
    }
    tamanho++;
    cout << "Elemento " << k << " inserido no inicio da lista." << endl;
}

void ListaDupla::ImprimirLista()
{
    NO2 *temp = inicio;
    cout << "Lista: ";
    while (temp != nullptr)
    {
        cout << temp->info << " ";
        temp = temp->prox;
    }
    cout << endl;
}
