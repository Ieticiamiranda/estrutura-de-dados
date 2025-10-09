#include <iostream>
#include "listas3.h" // contem funções e estruturas da lista da terceira questão
using namespace std;

// questao 3 - lista duplamente encadeada circular

// insere um nó no início da lista circular
void inserirInicio(No3 *&inicio, int valor)
{
    No3 *novo = new No3;
    novo->dado = valor;

    if (inicio == nullptr) // lista vazia
    {
        novo->prox = novo; // aponta para si mesmo (circular)
        novo->ant = novo;  // ponteiro anterior também aponta para si
        inicio = novo;     // início agora é o novo nó
    }
    else
    {
        No3 *ultimo = inicio->ant; // nó anterior ao início (último nó)
        novo->prox = inicio;       // próximo do novo nó é o início atual
        novo->ant = ultimo;        // anterior do novo nó é o último
        ultimo->prox = novo;       // último nó aponta para o novo
        inicio->ant = novo;        // início aponta de volta para o novo
        inicio = novo;             // atualiza início
    }
}

// insere um nó no final da lista circular
void inserirFim(No3 *&inicio, int valor)
{
    if (inicio == nullptr) // lista vazia
    {
        inserirInicio(inicio, valor); // reaproveita função do início
        return;
    }

    No3 *novo = new No3;
    novo->dado = valor;
    No3 *ultimo = inicio->ant; // último nó atual
    ultimo->prox = novo;       // último aponta para o novo
    novo->ant = ultimo;        // anterior do novo é o antigo último
    novo->prox = inicio;       // próximo do novo é o início (circular)
    inicio->ant = novo;        // início aponta de volta para o novo
}

// remove um nó pelo valor
void remover(No3 *&inicio, int valor)
{
    if (inicio == nullptr)
    {
        cout << "Lista vazia!\n";
        return;
    }

    No3 *atual = inicio;
    bool encontrado = false;

    // percorre a lista circular até encontrar o valor
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

    if (atual->prox == atual) // se é o único nó
    {
        delete atual;
        inicio = nullptr;
        return;
    }

    // ajusta ponteiros dos nós anterior e próximo
    atual->ant->prox = atual->prox;
    atual->prox->ant = atual->ant;

    if (atual == inicio) // se estava no início, atualiza
        inicio = atual->prox;

    delete atual; // libera memória
}

// imprime a lista recursivamente
void imprimirRecursivo(No3 *inicio, No3 *atual, bool primeiraChamada)
{
    if (inicio == nullptr)
    {
        cout << "Lista vazia!\n";
        return;
    }

    if (!primeiraChamada && atual == inicio) // volta ao início, termina recursão
    {
        cout << endl;
        return;
    }

    cout << atual->dado << " ";
    imprimirRecursivo(inicio, atual->prox, false); // chama próxima recursivamente
}
