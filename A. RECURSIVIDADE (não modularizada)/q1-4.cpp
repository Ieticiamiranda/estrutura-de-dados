#include <iostream>
using namespace std;

// questao 1 - funções recursivas
// função 1.) fatorial
int f1(int n)
{
    if (n == 0)
        return 1;
    else
        return n * f1(n - 1);
}

// função 2.) sequência recursiva
int f2(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    else
        return f2(n - 1) + 2 * f2(n - 2);
}

// função 3.) imprime valores até zero
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

// questao 2 - soma de pare
int somaPares(int n)
{
    if (n < 0)
        return 0; // caso de segurança
    if (n == 0)
        return 0;   // caso base
    if (n % 2 == 0) // se n é par, soma com resultado recursivo
        return n + somaPares(n - 2);
    else // se n é ímpar, ignora e chama para n-1
        return somaPares(n - 1);
}

// questao 3 - produto recursivo
int produto(int a, int b)
{
    if (b == 1)
        return a;
    else
        return produto(a, b - 1) + a;
}

// questao 4 - lista encadeada
// estrutura do nó
struct Node
{
    int data;
    Node *next;
};

// função para imprimir a lista
void imprimir(Node *head)
{
    if (head == nullptr)
        return;
    cout << head->data << " ";
    imprimir(head->next);
}

// função para buscar um elemento
bool buscar(Node *head, int valor)
{
    if (head == nullptr)
        return false;
    if (head->data == valor)
        return true;
    return buscar(head->next, valor);
}

// função para excluir um elemento
Node *excluir(Node *head, int valor)
{
    if (head == nullptr)
        return nullptr;
    if (head->data == valor)
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
    head->next = excluir(head->next, valor);
    return head;
}

// função para inserir elemento no início
Node *inserir(Node *head, int valor)
{
    Node *novo = new Node;
    novo->data = valor;
    novo->next = head;
    return novo;
}

// funções de menu
// menu inicial de questões
int MenuQuestoes()
{
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

// submenu da questão 1
int MenuEntradas1()
{
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

// submenu de entradas fixas - questão 1
int MenuSubEntradas1()
{
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

// submenu da questão 4
int MenuLista()
{
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

// programa principal
int main()
{
    int opcQuestao, opcFunc, opcEntrada;

    do
    {
        opcQuestao = MenuQuestoes();

        switch (opcQuestao)
        {
        case 1: // QUESTAO 1 -> f1, f2, f3
            do
            {
                opcFunc = MenuEntradas1();
                switch (opcFunc)
                {
                case 1: // f1
                    do
                    {
                        opcEntrada = MenuSubEntradas1();
                        switch (opcEntrada)
                        {
                        case 1:
                            cout << "f1(0) = " << f1(0) << endl;
                            break;
                        case 2:
                            cout << "f1(1) = " << f1(1) << endl;
                            break;
                        case 3:
                            cout << "f1(5) = " << f1(5) << endl;
                            break;
                        }
                    } while (opcEntrada != 4);
                    break;

                case 2: // f2
                    do
                    {
                        opcEntrada = MenuSubEntradas1();
                        switch (opcEntrada)
                        {
                        case 1:
                            cout << "f2(0) = " << f2(0) << endl;
                            break;
                        case 2:
                            cout << "f2(1) = " << f2(1) << endl;
                            break;
                        case 3:
                            cout << "f2(5) = " << f2(5) << endl;
                            break;
                        }
                    } while (opcEntrada != 4);
                    break;

                case 3: // f3
                    do
                    {
                        opcEntrada = MenuSubEntradas1();
                        switch (opcEntrada)
                        {
                        case 1:
                            cout << "f3(0) = ";
                            f3(0);
                            cout << endl;
                            break;
                        case 2:
                            cout << "f3(1) = ";
                            f3(1);
                            cout << endl;
                            break;
                        case 3:
                            cout << "f3(5) = ";
                            f3(5);
                            cout << endl;
                            break;
                        }
                    } while (opcEntrada != 4);
                    break;
                }
            } while (opcFunc != 4);
            break;

        case 2:
        { // QUESTAO 2 -> SOMA DE PARES
            int n;
            cout << "Digite um numero: ";
            cin >> n;
            cout << "Soma dos pares de 0 ate " << n << " = " << somaPares(n) << endl;
            break;
        }

        case 3:
        { // QUESTAO 3 -> PRODUTO RECURSIVO
            int a, b;
            cout << "Digite o valor de a: ";
            cin >> a;
            cout << "Digite o valor de b: ";
            cin >> b;
            cout << a << " * " << b << " = " << produto(a, b) << endl;
            break;
        }

        case 4:
        { // QUESTAO 4 -> LISTA ENCADEADA
            Node *lista = nullptr;
            int opcao, valor;

            do
            {
                opcao = MenuLista(); // <<< chamando a função nova

                switch (opcao)
                {
                case 1:
                    cout << "Digite o valor a inserir: ";
                    cin >> valor;
                    lista = inserir(lista, valor);
                    break;
                case 2:
                    cout << "Lista: ";
                    imprimir(lista);
                    cout << endl;
                    break;
                case 3:
                    cout << "Digite o valor a consultar: ";
                    cin >> valor;
                    if (buscar(lista, valor))
                        cout << "Registro encontrado!" << endl;
                    else
                        cout << "Registro nao encontrado." << endl;
                    break;
                case 4:
                    cout << "Digite o valor a excluir: ";
                    cin >> valor;
                    lista = excluir(lista, valor);
                    cout << "Registro excluido (se existia)." << endl;
                    break;
                case 5:
                    cout << "Retornando ao menu de questoes..." << endl;
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
                }
            } while (opcao != 5);

            // Liberar memória restante
            while (lista != nullptr)
            {
                Node *temp = lista;
                lista = lista->next;
                delete temp;
            }

            break;
        }

        case 5: // SAIR DO PROGRAMA
            cout << "Encerrando programa..." << endl;
            break;

        default:

            cout << "Opcao invalida!" << endl;
        }

    } while (opcQuestao != 5);

    return 0;
}
