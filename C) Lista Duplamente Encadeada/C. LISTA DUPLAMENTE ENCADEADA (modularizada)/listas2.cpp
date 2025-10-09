#include <iostream>
#include "listas2.h" // contém a classe e métodos da lista da segunda questão
using namespace std;

// questao 2 - lista duplamente encadeada sem duplicacao

// construtor da lista duplamente encadeada
ListaDupla::ListaDupla()
{
    inicio = nullptr; // início da lista vazio
    fim = nullptr;    // fim da lista vazio
    tamanho = 0;      // lista começa com tamanho 0
}

// verifica se a lista está vazia
bool ListaDupla::ListaVaziaLD() { return inicio == nullptr; }

// insere um elemento no início da lista, sem permitir duplicatas
void ListaDupla::InserirInicioLD(int k)
{
    NO2 *atual = inicio;

    // percorre a lista para verificar duplicatas
    while (atual != nullptr)
    {
        if (atual->info == k)
        {
            cout << "Elemento " << k << " ja existente na lista. Insercao nao realizada." << endl;
            return; // se já existe, não insere
        }
        atual = atual->prox;
    }

    NO2 *novo = new NO2; // cria o novo nó
    novo->info = k;      // armazena o valor
    novo->ant = nullptr; // será o primeiro, então anterior é nullptr

    if (ListaVaziaLD()) // se a lista estava vazia
    {
        novo->prox = nullptr; // não há próximo
        inicio = fim = novo;  // o novo nó é tanto início quanto fim
    }
    else
    {
        novo->prox = inicio; // próximo passa a ser o antigo início
        inicio->ant = novo;  // antigo início aponta de volta para o novo nó
        inicio = novo;       // atualiza início da lista
    }

    tamanho++; // atualiza o tamanho da lista
    cout << "Elemento " << k << " inserido no inicio da lista." << endl;
}

// percorre a lista do início ao fim, imprimindo os elementos
void ListaDupla::ImprimirLista()
{
    NO2 *temp = inicio;
    cout << "Lista: ";
    while (temp != nullptr)
    {
        cout << temp->info << " ";
        temp = temp->prox; // avança para o próximo nó
    }
    cout << endl;
}
