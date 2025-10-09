#include <iostream>
#include "listas1.h" // contém funções e estruturas da lista da primeira questão
using namespace std;

// questao 1 - lista duplamente encadeada

// cria um novo nó, inicializando os ponteiros para nullptr
No1 *criarNo(int valor)
{
    No1 *novo = new No1;
    novo->dado = valor;   // armazena o valor no nó
    novo->prox = nullptr; // próximo nó inicialmente vazio
    novo->ant = nullptr;  // nó anterior inicialmente vazio
    return novo;
}

// insere um nó em uma posição específica da lista
void inserir(No1 *&cabeca, int valor, int pos)
{
    No1 *novo = criarNo(valor); // cria o novo nó
    if (pos == 0)               // inserir no início
    {
        novo->prox = cabeca; // próximo passa a ser a antiga cabeça
        if (cabeca != nullptr)
            cabeca->ant = novo; // ajusta ponteiro do antigo primeiro nó
        cabeca = novo;          // novo nó se torna a cabeça
        return;
    }

    // percorre a lista até a posição anterior à desejada
    No1 *temp = cabeca;
    int i = 0;
    while (temp != nullptr && i < pos - 1)
    {
        temp = temp->prox;
        i++;
    }

    if (temp == nullptr) // posição inválida
    {
        cout << "Posicao invalida!" << endl;
        delete novo;
        return;
    }

    // conecta o novo nó entre temp e temp->prox
    novo->prox = temp->prox;
    novo->ant = temp;
    if (temp->prox != nullptr)
        temp->prox->ant = novo;
    temp->prox = novo;
}

// percorre a lista do início ao fim, imprimindo os valores
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

// busca um nó pelo valor, retornando o ponteiro para ele ou nullptr se não encontrado
No1 *buscar(No1 *cabeca, int valor)
{
    No1 *temp = cabeca;
    while (temp != nullptr)
    {
        if (temp->dado == valor)
            return temp; // retorna o nó encontrado
        temp = temp->prox;
    }
    return nullptr; // não encontrou
}

// remove um nó em uma posição específica
void excluir(No1 *&cabeca, int pos)
{
    if (cabeca == nullptr) // lista vazia
    {
        cout << "Lista vazia!" << endl;
        return;
    }

    No1 *temp = cabeca;

    if (pos == 0) // remover o primeiro nó
    {
        cabeca = cabeca->prox;
        if (cabeca != nullptr)
            cabeca->ant = nullptr;
        delete temp;
        return;
    }

    // percorre até a posição desejada
    int i = 0;
    while (temp != nullptr && i < pos)
    {
        temp = temp->prox;
        i++;
    }

    if (temp == nullptr) // posição inválida
    {
        cout << "Posicao invalida!" << endl;
        return;
    }

    // ajusta os ponteiros do nó anterior e do próximo
    if (temp->ant != nullptr)
        temp->ant->prox = temp->prox;
    if (temp->prox != nullptr)
        temp->prox->ant = temp->ant;

    delete temp; // libera a memória
}
