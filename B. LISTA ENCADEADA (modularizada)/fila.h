#ifndef FILA_H
#define FILA_H

struct NoFila {
    int info;
    NoFila* prox;
};

struct Fila {
    NoFila* frente;
    NoFila* tras;
    int tamanho;
};

void inicializar(Fila& f);
void enqueue(Fila& f, int valor);
int dequeue(Fila& f);
void listar(Fila& f);
bool contem(Fila& f, int valor);
void liberarFila(Fila& f);

#endif
