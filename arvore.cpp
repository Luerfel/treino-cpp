#include <iostream>
#include <string>

struct dados
{
    char Sintoma[50];
    int ID;
};

struct elemento {

    dados cadastro;
    struct elemento* proxVerdade;
    struct elemento* proxFalso;
};

typedef struct elemento Elem;

// DEFINIR O DESCRITOS DA LISTA 
struct Descritor {

    Elem* inicio;
    int tamanho;
    Elem* final;
};

Descritor* arvore;

//CRIAR A LISTA
Descritor* criar(void) {

    Descritor* descritor;
    descritor = (Descritor*)malloc(sizeof(Descritor));
    descritor->final = NULL;
    descritor->inicio = NULL;
    descritor->tamanho = -1;

    return descritor;
}