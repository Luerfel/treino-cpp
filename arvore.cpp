#include <iostream>
#include <string>

using namespace std;

typedef struct elem {

    int num;
    Elem* prox_dir;
    Elem* prox_esq;
}Elem;

int menu();
void inserir_arvore(Elem * node, int data);

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


void inserir_arvore(Elem* node, int data){

if (node == NULL){
    Elem* novo = (Elem*)malloc(sizeof(Elem*));
    novo->prox_dir = NULL;
    novo->prox_esq = NULL;
    novo->num = data;
}
}
