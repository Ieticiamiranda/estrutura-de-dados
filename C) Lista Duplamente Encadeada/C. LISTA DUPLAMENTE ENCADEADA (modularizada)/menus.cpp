#include <iostream>
#include "menus.h"
using namespace std;

int MenuQuestoes() {
    int opc;
    cout << "=============================================================" << endl;
    cout << "                 ESCOLHA UMA QUESTAO                         " << endl;
    cout << "=============================================================" << endl;
    cout << " [1] QUESTAO 1  " << endl;
    cout << " [2] QUESTAO 2  " << endl;
    cout << " [3] QUESTAO 3  " << endl;
    cout << " [4] SAIR DO PROGRAMA " << endl;
    cout << "=============================================================" << endl;
    cout << "OPCAO: ";
    cin >> opc;
    return opc;
}

void MenuListaCase1() {
    cout << "=============================================================" << endl;
    cout << "             MENU - LISTA DUPLAMENTE ENCADEADA               " << endl;
    cout << "=============================================================" << endl;
    cout << " [1] Inserir elemento" << endl;
    cout << " [2] Imprimir lista" << endl;
    cout << " [3] Buscar elemento" << endl;
    cout << " [4] Excluir elemento" << endl;
    cout << " [5] Voltar ao menu principal" << endl;
    cout << "=============================================================" << endl;
    cout << "OPCAO: ";
}

void MenuListaCase2() {
    cout << "=============================================================" << endl;
    cout << "             MENU - LISTA SEM DUPLICACAO                     " << endl;
    cout << "=============================================================" << endl;
    cout << " [1] Inserir elemento no inicio" << endl;
    cout << " [2] Imprimir lista" << endl;
    cout << " [3] Voltar ao menu principal" << endl;
    cout << "=============================================================" << endl;
    cout << "OPCAO: ";
}

void MenuListaCase3() {
    cout << "=============================================================" << endl;
    cout << "       MENU - LISTA CIRCULAR DUPLAMENTE ENCADEADA            " << endl;
    cout << "=============================================================" << endl;
    cout << " [1] Inserir no inicio" << endl;
    cout << " [2] Inserir no fim" << endl;
    cout << " [3] Remover elemento" << endl;
    cout << " [4] Imprimir lista" << endl;
    cout << " [5] Voltar ao menu principal" << endl;
    cout << "=============================================================" << endl;
    cout << "OPCAO: ";
}
