#include <iostream>
#include <cstring>


struct dados
{
    char nome[50];
    int idade;
};

struct elemento {

    struct elemento* ant;
    dados cadastro;
    struct elemento* prox;
};

typedef struct elemento Elem;

// DEFINIR O DESCRITOS DA LISTA 
struct Descritor {

    Elem* inicio;
    int tamanho;
    Elem* final;
};

Descritor* lista;

//CRIAR A LISTA
Descritor* criar(void) {

    Descritor* descritor;
    descritor = (Descritor*)malloc(sizeof(Descritor));
    descritor->final = NULL;
    descritor->inicio = NULL;
    descritor->tamanho = 0;

    return descritor;
}





//CADASTRAR UM ITEM NA LISTA
int inserir(Descritor* descritor, dados d)
{

    Elem* novo;
    novo = (Elem*)malloc(sizeof(Elem));
    novo->cadastro = d;
    novo->ant = NULL;
    novo->prox = NULL;

    //Caso 1 - Lista vazia
    if (descritor->tamanho == 0) {
        descritor->inicio = novo;
        descritor->final = novo;
    }
    else
     {
        descritor->final->prox = novo;
        novo->ant = descritor->final;
        descritor->final = novo;
        }

    (descritor->tamanho)++;
    return 1;
}

void listarInicio(Descritor* l)
{
    elemento* pos;
    int cont = 0;

    pos = l->inicio;

    while (cont< l->tamanho)
    {
        std::cout << "NOME:  " << pos->cadastro.nome << "\n";
        std::cout << "IDADE: " << pos->cadastro.idade << "\n";
        pos = pos->prox;
        cont++;
    }
}


void listarFim(Descritor* l)
{
    elemento* pos;
    int cont = 0;

    pos = l->final;

    while (cont < l->tamanho)
    {
        std::cout << "NOME:  " << pos->cadastro.nome << "\n";
        std::cout << "IDADE: " << pos->cadastro.idade << "\n";
        pos = pos->ant;
        cont++;
    }
}

void main()
{
    int valor;
    dados vl;

    lista = criar();

    strcpy(vl.nome, "JUVENAL");
    vl.idade = 10;
    inserir(lista, vl);
    
    strcpy(vl.nome, "ANTENOR");
    vl.idade = 20;
    inserir(lista, vl);

    strcpy(vl.nome, "PANTURRILHA");
    vl.idade = 30;
    inserir(lista, vl);


    std::cout << "\nLISTAGEM DO INICIO DA LISTA ATÉ O FIM:\n";
    listarInicio(lista);

    std::cout << "\nLISTAGEM DO FIM DA LISTA ATÉ O INICIO:\n";
    listarFim(lista);

    std::cout << "\nFIM";

}