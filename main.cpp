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
    float tempo_percorrido;
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
Descritor* criar_descritor();
void cadastrar(Descritor* descritor);
Dados ler_cadastro();
void limpar_tela();

int main() {
Descritor * descritor= criar_descritor();
int opcao;
int flag = 1;// uso no controle do while
cout << descritor->inicio;
cout << "escolha uma opçao:\n1.Cadastro\n2.Consultar\n3.Deletar\n4.Listar Dados\n5.Cálculo do consumo dos percursos." << endl;
cout << "Digita a opção: ";
cin >> opcao;
while(flag == 1){
    switch (opcao){
        case 1:
            limpar_tela();
            cadastrar(descritor);
            break;
        case 2:
            cout << "ola mundo" <<endl;
            break;
        case 3:
            cout << "Ola mundo zé" <<endl;
            break;
        case 4:
            cout << "sexo" <<endl;
            break;
        case 5:
            break;
        default:
        cout << "Opção invalida zé";
        break;
} }

return 1;

}

// criar o descritor
Descritor* criar_descritor()
{
    Descritor* descritor = (Descritor*)malloc(sizeof(Descritor));
    descritor->inicio = NULL;
    descritor->final = NULL;
    descritor->tamanho = 0;
    return descritor;
}
void cadastrar(Descritor* descritor)
{
    Elem * novo = (Elem*)malloc(sizeof(Elem));
    novo->cadastro = ler_cadastro();
    novo->ant = NULL;
    novo->prox = NULL;

    //caso a lista estiver vazia
    if(descritor->inicio == NULL){
        descritor ->inicio = novo;
        descritor ->final = novo;
    }
    // caso a lista não tiver vazia insere no final.
    else{
        novo->ant = descritor->final;
        descritor->final->prox = novo;
        descritor->final = novo;
    }
    // aumenta o tamanho da lista
    (descritor->tamanho)++;
}
Dados ler_cadastro(){
    Dados novo;
    cout << "Digite o nome completo: ";
    cin.getline(novo.nome,50);

    cout << "Digite a Marca: ";
    cin.getline(novo.marca,50);

    cout<< "Digite o Modelo: ";
    cin.getline(novo.modelo,50);

    cout <<"Digite a Cidade de Partida: ";
    cin.getline(novo.cidade_partida,50);

    cout << "digite a Cidade de Destino";
    cin.getline(novo.cidade_destino,50);

    cout << "Digite o Tempo Percorrido: ";
    cin >> novo.tempo_percorrido;

    cout << "Digite a Distancia Percorrida";
    cin >> novo.distancia;

    cout << "Digite o tipo de combustivel";
    cin.getline(novo.tipo_combustivel,50);

    cout << "Digite a quantidade de combustivel consumido";
    cin >> novo.combustivel_consumido;

    return novo;
}

void limpar_tela() {
    #ifdef _WIN32
        system("cls");   // Comando para limpar a tela no Windows
    #else
        system("clear"); // Comando para limpar a tela no Linux ou macOS
    #endif
}
