#ifndef LISTAS1_H // impede que o arquivo seja incluído mais de uma vez, evitando erros de compilação
#define LISTAS1_H

// estrutura do nó da lista duplamente encadeada
struct No1
{
    int dado;  // valor armazenado no nó
    No1 *prox; // ponteiro para o próximo nó
    No1 *ant;  // ponteiro para o nó anterior
};

/* protótipos da funções da questão 1 (lista duplamente encadeada)
isso permite que o main saiba que essas funções existem,
mesmo que estejam definidas em outro arquivo */

No1 *criarNo(int valor);
void inserir(No1 *&cabeca, int valor, int pos);
void imprimir(No1 *cabeca);
No1 *buscar(No1 *cabeca, int valor);
void excluir(No1 *&cabeca, int pos);

#endif
