#include <iostream>
#include <cstring>  // Para usar strcpy e strcmp
#include <cstdlib>  // Para malloc e free

using namespace std;

// Estruturas
typedef struct dados {
    char nome[50];
    char marca[50];
    char modelo[50];
    char cidade_partida[50];
    char cidade_destino[50];
    int tempo_percorrido;
    float distancia;
    char tipo_combustivel[50];
    float combustivel_consumido;
} Dados;

typedef struct elemento {
    struct elemento* ant;
    Dados cadastro;
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


int main() {
Descritor * descritor = criar();
int opcao;
int flag = 1;// uso no controle do while

cout << "escolha uma opçao:\n1.Cadastro\n2.Consultar\n3.Deletar\n4.Listar Dados\n5.Cálculo do consumo dos percursos." << endl;
cout << "Digita a opção: ";
cin >> opcao;
while(flag == 1){
    switch (opcao){
        case 1:
            cout << "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkk" << endl;
            break;
        case 2:
            cout << "ola mundo" <<endl;
            break;
        case 3:
            cout << "Ola mundo zé" <<endl;
        case 4:
            cout << "sexo" << endl;
        case 5:
            flag = 0;
            break;
        default:
        cout << "Opção invalida zé";
        break;
} }

return 1;

}

// criar o descritor
Descritor* criar()
{
    Descritor* descritor = (Descritor*)malloc(sizeof(Descritor));
    descritor->inicio = NULL;
    descritor->final = NULL;
    descritor->tamanho = 0;
    return descritor;
}
