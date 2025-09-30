#include <iostream>
using namespace std;
#include "funcoes.h"

int f1(int n)
{
    if (n == 0)
        return 1;
    else
        return n * f1(n - 1);
}

int f2(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    else
        return f2(n - 1) + 2 * f2(n - 2);
}

void f3(int n)
{
    if (n == 0)
        cout << "Zero ";
    else
    {
        cout << n << " ";
        cout << n << " ";
        f3(n - 1);
    }
}

int somaPares(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 0;
    if (n % 2 == 0)
        return n + somaPares(n - 2);
    else
        return somaPares(n - 1);
}

int produto(int a, int b)
{
    if (b == 1)
        return a;
    else
        return produto(a, b - 1) + a;
}
