#include <iostream>
using namespace std;

// questao 1 - lista encadeada
struct Node
{
    int info;
    Node *next;
};

Node *criarListaVazia() { return nullptr; }

void inserirElemento(Node *&head, int valor)
{
    Node *novo = new Node;
    novo->info = valor;
    novo->next = head;
    head = novo;
}

void percorrerLista(Node *head)
{
    if (!head)
    {
        cout << "Lista vazia!" << endl;
        return;
    }
    Node *atual = head;
    cout << "Elementos da lista: ";
    while (atual != nullptr)
    {
        cout << atual->info << " ";
        atual = atual->next;
    }
    cout << endl;
}

int tamanhoLista(Node *head)
{
    int count = 0;
    Node *atual = head;
    while (atual != nullptr)
    {
        count++;
        atual = atual->next;
    }
    return count;
}

int obterElemento(Node *head, int pos)
{
    int i = 0;
    Node *atual = head;
    while (atual != nullptr)
    {
        if (i == pos)
            return atual->info;
        atual = atual->next;
        i++;
    }
    return -1; // posição inválida
}

// questao 2 - pilha
struct NoPilha
{
    int info;
    NoPilha *prox;
};

struct Pilha
{
    NoPilha *topo;
    int tamanho;
};

void inicializar(Pilha &p)
{
    p.topo = nullptr;
    p.tamanho = 0;
}

void push(Pilha &p, int valor)
{
    NoPilha *novo = new NoPilha;
    novo->info = valor;
    novo->prox = p.topo;
    p.topo = novo;
    p.tamanho++;
}

int pop(Pilha &p)
{
    if (p.topo == nullptr)
    {
        cout << "Erro: pilha vazia!" << endl;
        return -1;
    }
    NoPilha *temp = p.topo;
    int valor = temp->info;
    p.topo = temp->prox;
    delete temp;
    p.tamanho--;
    return valor;
}

void listar(Pilha &p)
{
    if (p.topo == nullptr)
    {
        cout << "Pilha vazia!" << endl;
        return;
    }
    NoPilha *aux = p.topo;
    cout << "Conteudo da pilha (do topo para base):" << endl;
    while (aux != nullptr)
    {
        cout << aux->info << endl;
        aux = aux->prox;
    }
}

bool contem(Pilha &p, int valor)
{
    NoPilha *aux = p.topo;
    while (aux != nullptr)
    {
        if (aux->info == valor)
            return true;
        aux = aux->prox;
    }
    return false;
}

void liberarPilha(Pilha &p)
{
    while (p.topo != nullptr)
    {
        pop(p);
    }
}

// questao 3 - fila
struct NoFila
{
    int info;
    NoFila *prox;
};

struct Fila
{
    NoFila *frente;
    NoFila *tras;
    int tamanho;
};

void inicializar(Fila &f)
{
    f.frente = nullptr;
    f.tras = nullptr;
    f.tamanho = 0;
}

void enqueue(Fila &f, int valor)
{
    NoFila *novo = new NoFila;
    novo->info = valor;
    novo->prox = nullptr;
    if (f.tras == nullptr)
    {
        f.frente = novo;
    }
    else
    {
        f.tras->prox = novo;
    }
    f.tras = novo;
    f.tamanho++;
}

int dequeue(Fila &f)
{
    if (f.frente == nullptr)
    {
        cout << "Erro: fila vazia!" << endl;
        return -1;
    }
    NoFila *temp = f.frente;
    int valor = temp->info;
    f.frente = f.frente->prox;
    if (f.frente == nullptr)
        f.tras = nullptr;
    delete temp;
    f.tamanho--;
    return valor;
}

void listar(Fila &f)
{
    if (f.frente == nullptr)
    {
        cout << "Fila vazia!" << endl;
        return;
    }
    NoFila *aux = f.frente;
    cout << "Conteudo da fila (da frente para o fim):" << endl;
    while (aux != nullptr)
    {
        cout << aux->info << " ";
        aux = aux->prox;
    }
    cout << endl;
}

bool contem(Fila &f, int valor)
{
    NoFila *aux = f.frente;
    while (aux != nullptr)
    {
        if (aux->info == valor)
            return true;
        aux = aux->prox;
    }
    return false;
}

void liberarFila(Fila &f)
{
    while (f.frente != nullptr)
    {
        dequeue(f);
    }
}

// menus
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

//submenu da lista
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

//submenu da pilha
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

//submenu da fila
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

// programa principal
int main()
{
    int opcao;

    do
    {
        opcao = MenuQuestoes();

        switch (opcao)
        {
        case 1: // QUESTAO 1 -> LISTA
        { 
            Node *lista = nullptr;
            int escolha, valor, pos;
            do
            {
                escolha = MenuLista();
                switch (escolha)
                {
                case 1:
                    lista = criarListaVazia();
                    cout << "Lista criada com sucesso!" << endl;
                    break;
                case 2:
                    cout << "Digite um valor: ";
                    cin >> valor;
                    inserirElemento(lista, valor);
                    break;
                case 3:
                    percorrerLista(lista);
                    break;
                case 4:
                    cout << "Digite a posicao: ";
                    cin >> pos;
                    valor = obterElemento(lista, pos);
                    if (valor != -1)
                        cout << "Elemento na posicao " << pos << ": " << valor << endl;
                    else
                        cout << "Posicao invalida!" << endl;
                    break;
                case 5:
                    cout << "Tamanho da lista: " << tamanhoLista(lista) << endl;
                    break;
                case 6:
                    cout << "Voltando ao menu principal..." << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                }
            } while (escolha != 6);
            break;
        }
        case 2: // QUESTAO 2 -> PILHA
        { 
            Pilha p;
            inicializar(p);
            int escolha, valor;
            do
            {
                escolha = MenuPilha();
                switch (escolha)
                {
                case 1:
                    cout << "Digite um valor: ";
                    cin >> valor;
                    push(p, valor);
                    break;
                case 2:
                    valor = pop(p);
                    if (valor != -1)
                        cout << "Removido: " << valor << endl;
                    break;
                case 3:
                    listar(p);
                    break;
                case 4:
                    cout << "Digite o valor para buscar: ";
                    cin >> valor;
                    cout << (contem(p, valor) ? "Valor encontrado." : "Valor nao encontrado.") << endl;
                    break;
                case 5:
                    liberarPilha(p);
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                }
            } while (escolha != 5);
            break;
        }
        case 3: // QUESTAO 3 -> FILA
        {
            Fila f;
            inicializar(f);
            int escolha, valor;
            do
            {
                escolha = MenuFila();
                switch (escolha)
                {
                case 1:
                    cout << "Digite um valor: ";
                    cin >> valor;
                    enqueue(f, valor);
                    break;
                case 2:
                    valor = dequeue(f);
                    if (valor != -1)
                        cout << "Removido: " << valor << endl;
                    break;
                case 3:
                    listar(f);
                    break;
                case 4:
                    cout << "Digite o valor para buscar: ";
                    cin >> valor;
                    cout << (contem(f, valor) ? "Valor encontrado." : "Valor nao encontrado.") << endl;
                    break;
                case 5:
                    liberarFila(f);
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                }
            } while (escolha != 5);
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
