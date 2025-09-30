#ifndef LISTAS2_H
#define LISTAS2_H

class ListaDupla {
private:
    struct NO2 {
        int info;
        NO2* prox;
        NO2* ant;
    };
    NO2* inicio;
    NO2* fim;
    int tamanho;

public:
    ListaDupla();
    bool ListaVaziaLD();
    void InserirInicioLD(int k);
    void ImprimirLista();
};

#endif
