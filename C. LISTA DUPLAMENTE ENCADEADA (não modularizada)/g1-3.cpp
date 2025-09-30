#include <iostream>
using namespace std;

// questao 1 - lista duplamente encadeada

struct No1
{
    int dado;
    No1 *prox;
    No1 *ant;
};

No1 *criarNo(int valor)
{
    No1 *novo = new No1;
    novo->dado = valor;
    novo->prox = nullptr;
    novo->ant = nullptr;
    return novo;
}

void inserir(No1 *&cabeca, int valor, int pos)
{
    No1 *novo = criarNo(valor);
    if (pos == 0)
    {
        novo->prox = cabeca;
        if (cabeca != nullptr)
            cabeca->ant = novo;
        cabeca = novo;
        return;
    }
    No1 *temp = cabeca;
    int i = 0;
    while (temp != nullptr && i < pos - 1)
    {
        temp = temp->prox;
        i++;
    }
    if (temp == nullptr)
    {
        cout << "Posicao invalida!" << endl;
        delete novo;
        return;
    }
    novo->prox = temp->prox;
    novo->ant = temp;
    if (temp->prox != nullptr)
        temp->prox->ant = novo;
    temp->prox = novo;
}

void imprimir(No1 *cabeca)
{
    No1 *temp = cabeca;
    cout << "Lista: ";
    while (temp != nullptr)
    {
        cout << temp->dado << " ";
        temp = temp->prox;
    }
    cout << endl;
}

No1 *buscar(No1 *cabeca, int valor)
{
    No1 *temp = cabeca;
    while (temp != nullptr)
    {
        if (temp->dado == valor)
            return temp;
        temp = temp->prox;
    }
    return nullptr;
}

void excluir(No1 *&cabeca, int pos)
{
    if (cabeca == nullptr)
    {
        cout << "Lista vazia!" << endl;
        return;
    }
    No1 *temp = cabeca;
    if (pos == 0)
    {
        cabeca = cabeca->prox;
        if (cabeca != nullptr)
            cabeca->ant = nullptr;
        delete temp;
        return;
    }
    int i = 0;
    while (temp != nullptr && i < pos)
    {
        temp = temp->prox;
        i++;
    }
    if (temp == nullptr)
    {
        cout << "Posicao invalida!" << endl;
        return;
    }
    if (temp->ant != nullptr)
        temp->ant->prox = temp->prox;
    if (temp->prox != nullptr)
        temp->prox->ant = temp->ant;
    delete temp;
}

// questao 2 - lista duplamente encadeada sem duplicacao

struct NO2
{
    int info;
    NO2 *prox;
    NO2 *ant;
};

class ListaDupla
{
private:
    NO2 *inicio;
    NO2 *fim;
    int tamanho;

public:
    ListaDupla()
    {
        inicio = nullptr;
        fim = nullptr;
        tamanho = 0;
    }
    bool ListaVaziaLD() { return inicio == nullptr; }

    void InserirInicioLD(int k)
    {
        NO2 *atual = inicio;
        while (atual != nullptr)
        {
            if (atual->info == k)
            {
                cout << "Elemento " << k << " ja existente na lista. Insercao nao realizada." << endl;
                return;
            }
            atual = atual->prox;
        }
        NO2 *novo = new NO2;
        novo->info = k;
        novo->ant = nullptr;
        if (ListaVaziaLD())
        {
            novo->prox = nullptr;
            inicio = fim = novo;
        }
        else
        {
            novo->prox = inicio;
            inicio->ant = novo;
            inicio = novo;
        }
        tamanho++;
        cout << "Elemento " << k << " inserido no inicio da lista." << endl;
    }

    void ImprimirLista()
    {
        NO2 *temp = inicio;
        cout << "Lista: ";
        while (temp != nullptr)
        {
            cout << temp->info << " ";
            temp = temp->prox;
        }
        cout << endl;
    }
};

// questao 3 - lista duplamente encadeada circular

struct No3
{
    int dado;
    No3 *prox;
    No3 *ant;
};

void inserirInicio(No3 *&inicio, int valor)
{
    No3 *novo = new No3;
    novo->dado = valor;
    if (inicio == nullptr)
    {
        novo->prox = novo;
        novo->ant = novo;
        inicio = novo;
    }
    else
    {
        No3 *ultimo = inicio->ant;
        novo->prox = inicio;
        novo->ant = ultimo;
        ultimo->prox = novo;
        inicio->ant = novo;
        inicio = novo;
    }
}

void inserirFim(No3 *&inicio, int valor)
{
    if (inicio == nullptr)
    {
        inserirInicio(inicio, valor);
        return;
    }
    No3 *novo = new No3;
    novo->dado = valor;
    No3 *ultimo = inicio->ant;
    ultimo->prox = novo;
    novo->ant = ultimo;
    novo->prox = inicio;
    inicio->ant = novo;
}

void remover(No3 *&inicio, int valor)
{
    if (inicio == nullptr)
    {
        cout << "Lista vazia!\n";
        return;
    }
    No3 *atual = inicio;
    bool encontrado = false;
    do
    {
        if (atual->dado == valor)
        {
            encontrado = true;
            break;
        }
        atual = atual->prox;
    } while (atual != inicio);

    if (!encontrado)
    {
        cout << "Elemento " << valor << " nao encontrado.\n";
        return;
    }

    if (atual->prox == atual)
    {
        delete atual;
        inicio = nullptr;
        return;
    }

    atual->ant->prox = atual->prox;
    atual->prox->ant = atual->ant;
    if (atual == inicio)
        inicio = atual->prox;
    delete atual;
}

void imprimirRecursivo(No3 *inicio, No3 *atual, bool primeiraChamada = true)
{
    if (inicio == nullptr)
    {
        cout << "Lista vazia!\n";
        return;
    }
    if (!primeiraChamada && atual == inicio)
    {
        cout << endl;
        return;
    }
    cout << atual->dado << " ";
    imprimirRecursivo(inicio, atual->prox, false);
}

// funcoes de menu
// menu incial de questoes
int MenuQuestoes()
{
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

// submenu da questao 1
void MenuListaCase1()
{
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

// submenu da questao 2
void MenuListaCase2()
{
    cout << "=============================================================" << endl;
    cout << "             MENU - LISTA SEM DUPLICACAO                     " << endl;
    cout << "=============================================================" << endl;
    cout << " [1] Inserir elemento no inicio" << endl;
    cout << " [2] Imprimir lista" << endl;
    cout << " [3] Voltar ao menu principal" << endl;
    cout << "=============================================================" << endl;
    cout << "OPCAO: ";
}

// submenu da questao 3
void MenuListaCase3()
{
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

// programa principal

int main()
{
    int opcao;

    No1 *lista1 = nullptr;
    ListaDupla lista2;
    No3 *lista3 = nullptr;

    do
    {
        opcao = MenuQuestoes();

        switch (opcao)
        {
        case 1: //  QUESTAO 1 -> LISTA DUPLAMENTE ENCADEADA
        {
            int opcLista1;
            do
            {
                MenuListaCase1();
                cin >> opcLista1;

                switch (opcLista1)
                {
                case 1:
                {
                    int valor, pos;
                    cout << "Digite o valor a inserir: ";
                    cin >> valor;
                    cout << "Digite a posicao (0 para inicio): ";
                    cin >> pos;
                    inserir(lista1, valor, pos);
                    break;
                }
                case 2:
                    imprimir(lista1);
                    break;
                case 3:
                {
                    int valor;
                    cout << "Digite o valor a buscar: ";
                    cin >> valor;
                    No1 *encontrado = buscar(lista1, valor);
                    if (encontrado != nullptr)
                        cout << "Elemento " << valor << " encontrado!" << endl;
                    else
                        cout << "Elemento " << valor << " nao encontrado!" << endl;
                    break;
                }
                case 4:
                {
                    int pos;
                    cout << "Digite a posicao do elemento a excluir: ";
                    cin >> pos;
                    excluir(lista1, pos);
                    break;
                }
                case 5:
                    cout << "Voltando ao menu principal..." << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                }

            } while (opcLista1 != 5);
            break;
        }

        case 2: // QUESTAO 2 -> LISTA DUPLAMENTE ENCADEADA SEM DUPLICACAO
        {
            int opcLista2;
            do
            {
                MenuListaCase2();
                cin >> opcLista2;

                switch (opcLista2)
                {
                case 1:
                {
                    int valor;
                    cout << "Digite o valor a inserir: ";
                    cin >> valor;
                    lista2.InserirInicioLD(valor);
                    break;
                }
                case 2:
                    lista2.ImprimirLista();
                    break;
                case 3:
                    cout << "Voltando ao menu principal..." << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                }

            } while (opcLista2 != 3);
            break;
        }

        case 3: // QUESTAO 3 -> LISTA CIRCULAR DUPLAMENTE ENCADEADA
        {
            int opcLista3;
            do
            {
                MenuListaCase3();
                cin >> opcLista3;

                switch (opcLista3)
                {
                case 1:
                {
                    int valor;
                    cout << "Digite o valor: ";
                    cin >> valor;
                    inserirInicio(lista3, valor);
                    break;
                }
                case 2:
                {
                    int valor;
                    cout << "Digite o valor: ";
                    cin >> valor;
                    inserirFim(lista3, valor);
                    break;
                }
                case 3:
                {
                    int valor;
                    cout << "Digite o valor a remover: ";
                    cin >> valor;
                    remover(lista3, valor);
                    break;
                }
                case 4:
                    cout << "Lista: ";
                    imprimirRecursivo(lista3, lista3);
                    break;
                case 5:
                    cout << "Voltando ao menu principal...\n";
                    break;
                default:
                    cout << "Opcao invalida!\n";
                }
            } while (opcLista3 != 5);
            break;
        }

        case 4: // SAIR DO PROGRAMA
            cout << "Saindo do programa..." << endl;
            break;

        default:
            cout << "Opcao invalida! Tente novamente." << endl;
        }

    } while (opcao != 4);

    return 0;
}
