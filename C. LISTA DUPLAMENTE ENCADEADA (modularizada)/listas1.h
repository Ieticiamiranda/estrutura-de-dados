#ifndef LISTAS1_H
#define LISTAS1_H

struct No1 {
    int dado;
    No1* prox;
    No1* ant;
};

No1* criarNo(int valor);
void inserir(No1*& cabeca, int valor, int pos);
void imprimir(No1* cabeca);
No1* buscar(No1* cabeca, int valor);
void excluir(No1*& cabeca, int pos);

#endif
