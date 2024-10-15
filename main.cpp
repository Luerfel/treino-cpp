#include <iostream>
#include <cstring>  // Para usar strcpy
#include <cstdlib>  // Para malloc e free

// Usando typedef diretamente na definição das estruturas
typedef struct dados {
    char nome[50];
    int idade;
} dados;

typedef struct elemento {
    struct elemento* ant;
    dados cadastro;
    struct elemento* prox;
} Elem;

// Definindo o descritor da lista
typedef struct Descritor {
    Elem* inicio;
    int tamanho;
    Elem* final;
} Descritor;

// Protótipos das funções
Descritor* criar();
int inserir(Descritor* descritor, dados d);
void listarInicio(Descritor* l);
void listarFim(Descritor* l);

// Variável global
Descritor* lista;

int main() {
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

    std::cout << "\nLISTAGEM DO INÍCIO DA LISTA ATÉ O FIM:\n";
    listarInicio(lista);

    std::cout << "\nLISTAGEM DO FIM DA LISTA ATÉ O INÍCIO:\n";
    listarFim(lista);

    std::cout << "\nFIM\n";

    return 0;
}
Descritor* lista;

// Função para criar a lista
Descritor* criar() {
    Descritor* descritor;
    descritor = (Descritor*)malloc(sizeof(Descritor));
    descritor->final = NULL;
    descritor->inicio = NULL;
    descritor->tamanho = 0;

    return descritor;
}

// Função para inserir um item na lista
int inserir(Descritor* descritor, dados d) {
    Elem* novo;
    novo = (Elem*)malloc(sizeof(Elem));
    novo->cadastro = d;
    novo->ant = NULL;
    novo->prox = NULL;

    // Caso 1 - Lista vazia
    if (descritor->tamanho == 0) {
        descritor->inicio = novo;
        descritor->final = novo;
    } else {
        descritor->final->prox = novo;
        novo->ant = descritor->final;
        descritor->final = novo;
    }

    (descritor->tamanho)++;
    return 1;
}

// Função para listar do início ao fim
void listarInicio(Descritor* l) {
    Elem* pos;
    int cont = 0;

    pos = l->inicio;

    while (cont < l->tamanho) {
        std::cout << "NOME:  " << pos->cadastro.nome << "\n";
        std::cout << "IDADE: " << pos->cadastro.idade << "\n";
        pos = pos->prox;
        cont++;
    }
}

// Função para listar do fim ao início
void listarFim(Descritor* l) {
    Elem* pos;
    int cont = 0;

    pos = l->final;

    while (cont < l->tamanho) {
        std::cout << "NOME:  " << pos->cadastro.nome << "\n";
        std::cout << "IDADE: " << pos->cadastro.idade << "\n";
        pos = pos->ant;
        cont++;
    }
}