#include <iostream>
#include <cstring>  // Para usar strcpy e strcmp
#include <cstdlib>  // Para malloc e free

using namespace std;
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

// Variável global
Descritor* lista;

int main() {
cout << "Hello, Worlad" << endl;
return 1;

}
Descritor* criar(){
    Descritor* descritor = (Descritor*)malloc(sizeof(Descritor));
    descritor -> inicio = NULL;
    descritor -> final = NULL;
    descritor -> tamanho = 0;
    return descritor;
}
