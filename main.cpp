#include <iostream>
#include <string>
typedef struct dados
{
    char nome[50];
    int idade;
}Dados;

typedef struct elemento {
    struct elemento *ant;
    Dados cadastro;
    struct elementos* prox;
}Elem;

typedef struct lista {
    Elem* inicio;
    int tamanho;
    Elem* final;
}Lista;
Lista* lista;
//Prototipos das funções
Lista* criar(void);
void main() {

}
Lista* criar(void){

}