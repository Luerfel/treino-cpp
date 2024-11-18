#include <iostream>
#include <string>

using namespace std;

typedef struct elem {

    int num;
    Elem* prox_dir;
    Elem* prox_esq;
}Elem;


// DEFINIR O DESCRITOS DA LISTA 
struct Descritor {

    Elem* inicio;
    int tamanho;
};


//Prototipo de funções
Descritor* criar(); 
int menu();
void inserir_arvore(Descritor * desc, int num);

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
    descritor->inicio = NULL;
    descritor->tamanho = 0;

    return descritor; 
}
void inserir_arvore(Descritor * desc, int num){

}
