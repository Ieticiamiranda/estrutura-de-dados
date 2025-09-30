#ifndef PILHA_H
#define PILHA_H

struct NoPilha {
    int info;
    NoPilha* prox;
};

struct Pilha {
    NoPilha* topo;
    int tamanho;
};

void inicializar(Pilha& p);
void push(Pilha& p, int valor);
int pop(Pilha& p);
void listar(Pilha& p);
bool contem(Pilha& p, int valor);
void liberarPilha(Pilha& p);

#endif
