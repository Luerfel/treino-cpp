#include <iostream>
#include <cstring>  // Para usar strcpy e strcmp
#include <cstdlib>  // Para malloc e free

using namespace std;

typedef struct dados{
    char nome[50];
    int idade;
}dados;

typedef struct elemento{
    elem* ant;
    dados cadastro;
}elem;

typedef struct descritor{
    elem* ultimo;
    int tamanho;
}descritor;
// o último elemento inserido é o primeiro a ser removido.
int main(){





    return 1;
}