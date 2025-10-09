#ifndef PILHA_H // impede que o arquivo seja incluído mais de uma vez, evitando erros de compilação
#define PILHA_H

// nó da pilha, guarda um valor e um ponteiro para o próximo nó
struct NoPilha
{
    int info;      // valor armazenado no nó
    NoPilha *prox; // ponteiro para o próximo nó da pilha
};

// estrutura da pilha, com ponteiro para o topo e tamanho
struct Pilha
{
    NoPilha *topo; // topo da pilha (último elemento inserido)
    int tamanho;   // quantos elementos existem na pilha
};

/* protótipos da funções da questão 2 (pilha)
isso permite que o main saiba que essas funções existem,
mesmo que estejam definidas em outro arquivo */

void inicializar(Pilha &p);
void push(Pilha &p, int valor);
int pop(Pilha &p);
void listar(Pilha &p);
bool contem(Pilha &p, int valor);
void liberarPilha(Pilha &p);

#endif
