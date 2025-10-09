#ifndef LISTAS2_H // impede que o arquivo seja incluído mais de uma vez, evitando erros de compilação
#define LISTAS2_H

// classe que representa uma lista duplamente encadeada sem duplicatas
class ListaDupla
{
private:
    // estrutura interna do nó da lista
    struct NO2
    {
        int info;  // valor armazenado no nó
        NO2 *prox; // ponteiro para o próximo nó
        NO2 *ant;  // ponteiro para o nó anterior
    };

    NO2 *inicio; // ponteiro para o início da lista
    NO2 *fim;    // ponteiro para o fim da lista
    int tamanho; // mantém o tamanho da lista

    /* protótipos da funções da questão 2 (lista duplamente encadeada sem duplicação)
    isso permite que o main saiba que essas funções existem,
    mesmo que estejam definidas em outro arquivo */

public:
    ListaDupla();
    bool ListaVaziaLD();
    void InserirInicioLD(int k);
    void ImprimirLista();
};

#endif
