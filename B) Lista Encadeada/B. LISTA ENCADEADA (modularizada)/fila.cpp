#include <iostream>
#include "fila.h" // inclui as funções para manipulação de filas
using namespace std;

// questão 3 - fila

// inicializa a fila vazia
void inicializar(Fila &f)
{
    f.frente = nullptr; // não tem elemento na frente
    f.tras = nullptr;   // não tem elemento no fim
    f.tamanho = 0;      // tamanho começa em 0
}

// adiciona um elemento sempre no final da fila
void enqueue(Fila &f, int valor)
{
    NoFila *novo = new NoFila; // cria um novo nó dinamicamente
    novo->info = valor;        // armazena o valor
    novo->prox = nullptr;      // próximo nó é nulo, porque será o último

    if (f.tras == nullptr) // se a fila estiver vazia
        f.frente = novo;   // novo nó também é o primeiro
    else
        f.tras->prox = novo; // conecta o último nó atual ao novo nó

    f.tras = novo; // atualiza o ponteiro do fim da fila
    f.tamanho++;   // incrementa o tamanho
}

// remove e retorna o elemento do início da fila
int dequeue(Fila &f)
{
    if (f.frente == nullptr) // fila vazia
    {
        cout << "Erro: fila vazia!" << endl;
        return -1; // sinaliza erro
    }

    NoFila *temp = f.frente;   // armazena o nó que será removido
    int valor = temp->info;    // pega o valor para retornar
    f.frente = f.frente->prox; // atualiza a frente da fila

    if (f.frente == nullptr) // se a fila ficou vazia, atualiza o fim
        f.tras = nullptr;

    delete temp;  // libera memória do nó removido
    f.tamanho--;  // decrementa o tamanho
    return valor; // retorna o valor removido
}

// imprime todos os elementos da fila
void listar(Fila &f)
{
    if (f.frente == nullptr)
    {
        cout << "Fila vazia!" << endl;
        return;
    }

    NoFila *aux = f.frente; // começa do primeiro elemento
    cout << "Conteudo da fila (da frente para o fim):" << endl;
    while (aux != nullptr)
    {
        cout << aux->info << " "; // imprime valor
        aux = aux->prox;          // vai para o próximo
    }
    cout << endl;
}

// verifica se um valor existe na fila
bool contem(Fila &f, int valor)
{
    NoFila *aux = f.frente; // começa do primeiro
    while (aux != nullptr)
    {
        if (aux->info == valor) // encontrou
            return true;
        aux = aux->prox;
    }
    return false; // não encontrou
}

// libera toda a memória usada pela fila
void liberarFila(Fila &f)
{
    while (f.frente != nullptr) // enquanto houver elementos
    {
        dequeue(f); // remove cada elemento, sempre do inicio (já libera memória)
    }
}
