#include <iostream>
#include <string>

using namespace std;
typedef struct dados
{
    char Sintoma[50];
    int ID;
}Dados;

typedef struct elem {

    Dados cadastro;
    Elem* proxVerdade;
    Elem* proxFalso;
}Elem;


// DEFINIR O DESCRITOS DA LISTA 
struct Descritor {

    Elem* inicio;
    int tamanho;
    Elem* final;
};


//Prototipo de funções
Descritor* criar(); 
int menu();



int main() {
Descritor * descritor= criar();
int opcao,opcao2;
while(true){
    opcao = menu();
    switch (opcao){
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            break;
        case 5:
            break;
        default:
            cout << "Opção invalida zé";
        break;
} }

return 1;

}

int menu(){
    int opcao;
    cout << "escolha uma opçao:\n1.Cadastro\n2.Consultar\n3.Deletar\n4.Listar Dados\n5-Sair" << endl;
    cout << "Digita a opção: ";
    cin >> opcao;
    cin.ignore();
    return opcao;
}

Descritor* criar(void) {

    Descritor* descritor;
    descritor = (Descritor*)malloc(sizeof(Descritor));
    descritor->final = NULL;
    descritor->inicio = NULL;
    descritor->tamanho = -1;

    return descritor;
}