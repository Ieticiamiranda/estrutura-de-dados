#include <iostream>
using namespace std;
#include "menus.h"

int MenuQuestoes() {
    int opc;
    cout << "=============================================================" << endl;
    cout << "                 ESCOLHA UMA QUESTAO                         " << endl;
    cout << "=============================================================" << endl;
    cout << " [1] QUESTAO 1 (FUNCOES) " << endl;
    cout << " [2] QUESTAO 2 (SOMA DE PARES) " << endl;
    cout << " [3] QUESTAO 3 (PRODUTO) " << endl;
    cout << " [4] QUESTAO 4 (LISTA ENCADEADA) " << endl;
    cout << " [5] SAIR DO PROGRAMA " << endl;
    cout << "=============================================================" << endl;
    cout << "OPCAO: ";
    cin >> opc;
    return opc;
}

int MenuEntradas1() {
    int opc;
    cout << "=============================================================" << endl;
    cout << "                  ESCOLHA UMA FUNCAO                         " << endl;
    cout << "=============================================================" << endl;
    cout << " [1] CALCULAR FATORIAL (f1)" << endl;
    cout << " [2] CALCULAR SEQUENCIA RECURSIVA (f2)" << endl;
    cout << " [3] CALCULAR IMPRESSAO ATE NUMERO 0 (f3)" << endl;
    cout << " [4] VOLTAR AO MENU DE QUESTOES " << endl;
    cout << "=============================================================" << endl;
    cout << "OPCAO: ";
    cin >> opc;
    return opc;
}

int MenuSubEntradas1() {
    int opc;
    cout << "=============================================================" << endl;
    cout << "                     ESCOLHA UMA ENTRADA                     " << endl;
    cout << "=============================================================" << endl;
    cout << " [1] f(0) " << endl;
    cout << " [2] f(1) " << endl;
    cout << " [3] f(5) " << endl;
    cout << " [4] VOLTAR AO MENU ANTERIOR " << endl;
    cout << "=============================================================" << endl;
    cout << "OPCAO: ";
    cin >> opc;
    return opc;
}

int MenuLista() {
    int opc;
    cout << "=============================================================" << endl;
    cout << "               ESCOLHA UM ITEM NO MENU ABAIXO                " << endl;
    cout << "=============================================================" << endl;
    cout << " [1] INSERIR REGISTRO " << endl;
    cout << " [2] IMPRIMIR CONTEUDO DA LISTA " << endl;
    cout << " [3] BUSCAR ELEMENTO NA LISTA " << endl;
    cout << " [4] EXCLUIR ELEMENTO DA LISTA " << endl;
    cout << " [5] VOLTAR AO MENU DE QUESTOES " << endl;
    cout << "=============================================================" << endl;
    cout << "OPCAO: ";
    cin >> opc;
    return opc;
}
