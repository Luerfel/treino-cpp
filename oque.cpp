#include <iostream>
#include <cstring>  // Para usar strcpy e strcmp
#include <cstdlib>  // Para malloc e free

using namespace std;

// Estruturas
typedef struct Dados{
    char nome[50];
    int valor;
}Dados;
3
typedef struct Elem{
    Elem* ant;
    Dados dados;
    Elem* prox;
}Elem; Elem elmento[50];                                   
12 13 14
typedef struct Descritor{
    Elem* inicio;
    int tamanho;
    Elem* final;
}Descritor;
descritor -> inicio -> dados = descritor-> final -> dados;
//prototipos da função
Descritor* criar_descritor();
void inserir(Descritor*descritor);

descritor= 5;

int main() {
Descritor * descritor = criar_descritor();



return 1;
} 
// criar o descritor
Descritor* criar_descritor()
{
    Descritor * descritor =(Descritor*)malloc(sizeof(Descritor));
    descritor ->inicio = NULL;
    descritor->final = NULL;
    descritor->tamanho = 0;
    return descritor;
}

void inserir(Descritor* descritor){
 

}
char* carro[50]; int * idade;

main()
int *idade;


sexo sexo sexo(int *idade){
idade = 22;
-
-
-
-
-

return sexo;
} 