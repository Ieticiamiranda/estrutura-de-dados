#ifndef FILA_H // impede que o arquivo seja incluído mais de uma vez, evitando erros de compilação
#define FILA_H

// nó da fila, guarda um valor e um ponteiro para o próximo nó
struct NoFila
{
    int info;
    NoFila *prox;
};

// estrutura da fila em si, com ponteiros para frente e tras, e tamanho
struct Fila
{
    NoFila *frente; // primeiro elemento da fila
    NoFila *tras;   // último elemento da fila
    int tamanho;    // quantos elementos existem na fila
};

/* protótipos da funções da questão 3 (fila)
isso permite que o main saiba que essas funções existem,
mesmo que estejam definidas em outro arquivo */

void inicializar(Fila &f);
void enqueue(Fila &f, int valor);
int dequeue(Fila &f);
void listar(Fila &f);
bool contem(Fila &f, int valor);
void liberarFila(Fila &f);

#endif
