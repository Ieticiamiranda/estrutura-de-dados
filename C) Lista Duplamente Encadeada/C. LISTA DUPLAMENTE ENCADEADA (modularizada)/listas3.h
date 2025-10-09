#ifndef LISTAS3_H // impede que o arquivo seja incluído mais de uma vez, evitando erros de compilação
#define LISTAS3_H

// estrutura do nó da lista duplamente encadeada circular
struct No3
{
    int dado;  // valor armazenado no nó
    No3 *prox; // ponteiro para o próximo nó
    No3 *ant;  // ponteiro para o nó anterior
};

/* protótipos da funções da questão 3 (lista duplamente encadeada circular)
isso permite que o main saiba que essas funções existem,
mesmo que estejam definidas em outro arquivo */

void inserirInicio(No3 *&inicio, int valor);
void inserirFim(No3 *&inicio, int valor);
void remover(No3 *&inicio, int valor);
void imprimirRecursivo(No3 *inicio, No3 *atual, bool primeiraChamada = true);

#endif
