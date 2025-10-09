#include <iostream>
using namespace std;
#include "funcoes.h" // inclui funções (f1, f2, f3), somaPares e produto

// questao 1 - funções recursivas

// função 1.) fatorial
int f1(int n)
{
    if (n == 0) // caso base: fatorial de 0 é 1
        return 1;
    else
        return n * f1(n - 1); // chama a si mesma com n-1 e multiplica pelo n atual
}

// função 2.) sequência recursiva
int f2(int n)
{
    if (n == 0) // caso base 0
        return 1;
    if (n == 1) // caso base 1
        return 1;
    else
        return f2(n - 1) + 2 * f2(n - 2); // chamada recursiva combinando os dois casos anteriores
}

// função 3.) imprime cada número duas vezes até chegar em 0
void f3(int n)
{
    if (n == 0) // caso base: imprime "Zero"
        cout << "Zero ";
    else
    {
        cout << n << " "; // imprime n duas vezes
        cout << n << " ";
        f3(n - 1); // chama a si mesma com n-1
    }
}

// questao 2 - soma de pares
// função recursiva que calcula a soma de todos os números pares de 0 até n
int somaPares(int n)
{
    if (n < 0) // caso inválido: retorna 0
        return 0;
    if (n == 0) // caso base: soma de 0 é 0
        return 0;
    if (n % 2 == 0) // se n é par, soma n com a chamada recursiva decrementando de 2
        return n + somaPares(n - 2);
    else // se n é ímpar, chama a função com n-1 para alcançar o próximo par
        return somaPares(n - 1);
}

// questao 3 - produto recursivo
// função recursiva que calcula a multiplicação de a * b usando soma repetida
int produto(int a, int b)
{
    if (b == 1) // caso base: a * 1 = a
        return a;
    else
        return produto(a, b - 1) + a; // soma a a si mesmo b vezes
}
