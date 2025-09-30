#ifndef LISTAS3_H
#define LISTAS3_H

struct No3 {
    int dado;
    No3* prox;
    No3* ant;
};

void inserirInicio(No3*& inicio, int valor);
void inserirFim(No3*& inicio, int valor);
void remover(No3*& inicio, int valor);
void imprimirRecursivo(No3* inicio, No3* atual, bool primeiraChamada = true);

#endif
