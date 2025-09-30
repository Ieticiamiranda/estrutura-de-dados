#include <iostream>
#include "menus.h"
using namespace std;

int MenuQuestoes()
{
    int opc;
    cout << "=============================================================" << endl;
    cout << "                 ESCOLHA UMA QUESTAO                         " << endl;
    cout << "=============================================================" << endl;
    cout << " [1] QUESTAO 1 - LISTA " << endl;
    cout << " [2] QUESTAO 2 - PILHA " << endl;
    cout << " [3] QUESTAO 3 - FILA" << endl;
    cout << " [4] SAIR DO PROGRAMA " << endl;
    cout << "=============================================================" << endl;
    cout << "OPCAO: ";
    cin >> opc;
    return opc;
}

int MenuLista()
{
    int escolha;
    cout << "=============================================================" << endl;
    cout << "                 MENU LISTA                                  " << endl;
    cout << "=============================================================" << endl;
    cout << " [1] CRIAR LISTA VAZIA " << endl;
    cout << " [2] INSERIR ELEMENTO " << endl;
    cout << " [3] PERCORRER E LISTAR " << endl;
    cout << " [4] MOSTRAR ELEMENTO (por posição) " << endl;
    cout << " [5] TAMANHO DA LISTA " << endl;
    cout << " [6] VOLTAR AO MENU PRINCIPAL " << endl;
    cout << "=============================================================" << endl;
    cout << "OPCAO: ";
    cin >> escolha;
    return escolha;
}

int MenuPilha()
{
    int escolha;
    cout << "=============================================================" << endl;
    cout << "                 MENU PILHA                                  " << endl;
    cout << "=============================================================" << endl;
    cout << " [1] INSERIR ELEMENTOS " << endl;
    cout << " [2] EXCLUIR ELEMENTOS " << endl;
    cout << " [3] LISTAR CONTEUDO DA PILHA " << endl;
    cout << " [4] VERIFICAR ELEMENTO NA PILHA " << endl;
    cout << " [5] VOLTAR AO MENU PRINCIPAL " << endl;
    cout << "=============================================================" << endl;
    cout << "OPCAO: ";
    cin >> escolha;
    return escolha;
}

int MenuFila()
{
    int escolha;
    cout << "=============================================================" << endl;
    cout << "                 MENU FILA                                   " << endl;
    cout << "=============================================================" << endl;
    cout << " [1] INSERIR ELEMENTOS " << endl;
    cout << " [2] EXCLUIR ELEMENTOS " << endl;
    cout << " [3] LISTAR CONTEUDO DA FILA " << endl;
    cout << " [4] VERIFICAR ELEMENTO NA FILA " << endl;
    cout << " [5] VOLTAR AO MENU PRINCIPAL " << endl;
    cout << "=============================================================" << endl;
    cout << "OPCAO: ";
    cin >> escolha;
    return escolha;
}
