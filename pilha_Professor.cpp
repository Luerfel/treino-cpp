// PILHA001.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//  LIFO (ou FILO):– Last In, First Out
//  Último a entrar, primeiro a sair
//   OPERAÇÕES COM PILHAS: 
//         – Inserir os dados no topo da pilha
//         – Remover os dados do topo da pilha

#include <iostream>
#include <string>

struct dados
{
    char nome[50];
    int idade;
};

struct elemento {

    struct elemento* ant;
    dados cadastro;
    struct elemento* prox;
};

typedef struct elemento Elem;

// DEFINIR O DESCRITOS DA LISTA 
struct Descritor {

    Elem* inicio;
    int tamanho;
    Elem* final;
};

Descritor* pilha;

//CRIAR A PILHA
Descritor* criar(void) {

    Descritor* descritor;
    descritor = (Descritor*)malloc(sizeof(Descritor));
    descritor->final = NULL;
    descritor->inicio = NULL;
    descritor->tamanho = 0;

    return descritor;
}





//CADASTRAR UM ITEM NA PILHA
int inserirItemPilha(Descritor* descritor, dados d)
{
    Elem* novo;
    novo = (Elem*)malloc(sizeof(Elem));
    novo->cadastro = d;
    novo->ant = NULL;
    novo->prox = NULL;

    //Caso 1 - Pilha vazia
    if (descritor->tamanho == 0) {
        descritor->inicio = novo;
        descritor->final = novo;
    }
    else
    {
        descritor->final->prox = novo;
        novo->ant = descritor->final;
        descritor->final = novo;
    }

    (descritor->tamanho)++;
    return 1;
}


void listarPilha(Descritor* d)
{
    elemento* pos;
    int cont = 0;

    pos = d->final;

    while (cont < d->tamanho)
    {
        std::cout << "NOME:  " << pos->cadastro.nome << "\n";
        std::cout << "IDADE: " << pos->cadastro.idade << "\n";
        pos = pos->ant;
        cont++;
    }
}

dados consultarPilhaNome(char* nomeprocurado, Descritor* d)
{
    elemento* pos;
    dados resultado;
    int cont = 0;
    int cmp;
    pos = d->final;

    resultado.idade = -1;
    strcpy_s(resultado.nome, "");

    while (cont < d->tamanho)
    {
        resultado = pos->cadastro;
        cmp = strcmp(nomeprocurado, resultado.nome);
        if (cmp == 0)
        {
            return resultado;
        }
        pos = pos->ant;
        cont++;
    }

    resultado.idade = -1;
    strcpy_s(resultado.nome, "");

    return resultado;
}

// REMOVER ITEM DA PILHA
// RETORNA -1 SE NOME NÃO CADASTRADO
// RETORNA n >= 0 INDICANDO O NÚMERO DE ITENS AINDA NA PILHA
int removerItemPilha(Descritor* d)
{
    elemento* pos;
    dados resultado;

    pos = d->final;

    resultado.idade = -1;
    strcpy_s(resultado.nome, "");

    //DELETAR ITEM PILHA
    if (d->tamanho >0)
    {
        if (pos->ant != NULL)
        {
            d->final = pos->ant;
            pos->ant->prox = pos->ant;
            d->tamanho--;
            free(pos);

            return d->tamanho;
        }
        else
        {
            d->final->ant = NULL;
            d->final->prox = NULL;
            strcpy_s(d->final->cadastro.nome, "");
            d->final->cadastro.idade = -1;
            d->inicio = d->final;
            d->tamanho = 0;

            return -1;
        }
    }

    return -1;
}


// RETORNAR ITEM DISPONÍVEL NA PILHA
// SE PILHA NÃO VAZIA, RETORNA struct dados
// SE PILHA VAZIA, RETORNA  .idade = -1
//                          .nome = ""  
dados ItemPilha(Descritor* d)
{
    elemento* pos;
    dados resultado;

    pos = d->final;

    resultado.idade = -1;
    strcpy_s(resultado.nome, "");

    //RETORNAR ITEM PILHA
    if  (d->tamanho > 0)
    {
        return pos->cadastro;
    }

    return resultado;
}

void main()
{
    int valor;
    int resultado;
    dados vl;
    dados vlresultado;

    pilha = criar();



    // ****************************************************************
    // INSERIR ITEM NA PIHLA
    // ****************************************************************
    strcpy_s(vl.nome, "JUVENAL");
    vl.idade = 10;
    resultado = inserirItemPilha(pilha, vl);
    if (resultado == 1)
        std::cout << "ITEM INSERIDO COM SUCESSO NA PILHA:  " << vl.nome << "  " << vl.idade << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.nome, "ANTENOR");
    vl.idade = 20;
    resultado = inserirItemPilha(pilha, vl);
    if (resultado == 1)
        std::cout << "ITEM INSERIDO COM SUCESSO NA PILHA:  " << vl.nome << "  " << vl.idade << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.nome, "PANTURRILHA");
    vl.idade = 30;
    resultado = inserirItemPilha(pilha, vl);
    if (resultado == 1)
        std::cout << "ITEM INSERIDO COM SUCESSO NA PILHA:  " << vl.nome << "  " << vl.idade << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.nome, "ARTROSY");
    vl.idade = 40;
    resultado = inserirItemPilha(pilha, vl);
    if (resultado == 1)
        std::cout << "ITEM INSERIDO COM SUCESSO NA PILHA:  " << vl.nome << "  " << vl.idade << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.nome, "GERUZA");
    vl.idade = 50;
    resultado = inserirItemPilha(pilha, vl);
    if (resultado == 1)
        std::cout << "ITEM INSERIDO COM SUCESSO NA PILHA:  " << vl.nome << "  " << vl.idade << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.nome, "CELENIO");
    vl.idade = 60;
    resultado = inserirItemPilha(pilha, vl);
    if (resultado == 1)
        std::cout << "ITEM INSERIDO COM SUCESSO NA PILHA:  " << vl.nome << "  " << vl.idade << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    // ****************************************************************
    // LISTAR DADOS PILHA
    // ****************************************************************
    std::cout << "\nLISTAGEM DOS DADOS NA PILHA:\n";
    listarPilha(pilha);


    // ****************************************************************
    // CONSULTAR DADOS NA PILHA
    // ****************************************************************
    char nomeProcurado[50];
    strcpy_s(nomeProcurado, "ARTROSY");
    std::cout << "\nPROCURANDO O NOME:  " << nomeProcurado << "\n";
    vlresultado = consultarPilhaNome(nomeProcurado, pilha);
    if (vlresultado.idade > 0)
        std::cout << "CONSULTA COM SUCESSO:  " << vlresultado.nome << "  " << vlresultado.idade << "\n";
    else
        std::cout << "ERRO NA CONSULTA - NOME: " << nomeProcurado << " , NAO CADASTRADO\n";

    strcpy_s(nomeProcurado, "LEONCIO");
    std::cout << "\nPROCURANDO O NOME:  " << nomeProcurado << "\n";
    vlresultado = consultarPilhaNome(nomeProcurado, pilha);
    if (vlresultado.idade > 0)
        std::cout << "CONSULTA COM SUCESSO:  " << vlresultado.nome << "  " << vlresultado.idade << "\n";
    else
        std::cout << "ERRO NA CONSULTA - NOME: " << nomeProcurado << " , NAO CADASTRADO\n";



    // ****************************************************************
    // REMOVER ITEM DA PILHA
    // ****************************************************************
    dados itempilha;
    int r;

    std::cout << "\n\nREMOVER ITEM DA PILHA\n";
    itempilha = ItemPilha(pilha);
    std::cout << "\n\nITEM DISPONÍVEL NO TOPO DA PILHA: " << itempilha.nome << itempilha.idade<<"\n";
    r = removerItemPilha(pilha);
    if (r >=0 )
    {
        std::cout << "ITEM REMOVIDO COM SUCESSO DA PILHA\n";
    }
    else
    {
        std::cout << "PILHA ESTÁ VAZIA\n";
    }

    std::cout << "\nLISTAGEM DOS DADOS NA PILHA:\n";
    listarPilha(pilha);

    itempilha = ItemPilha(pilha);
    std::cout << "\n\nITEM DISPONÍVEL NO TOPO DA PILHA: " << itempilha.nome << itempilha.idade << "\n";
    r = removerItemPilha(pilha);
    if (r >= 0)
    {
        std::cout << "ITEM REMOVIDO COM SUCESSO DA PILHA\n";
    }
    else
    {
        std::cout << "PILHA ESTÁ VAZIA\n";
    }

    std::cout << "\n\nLISTAGEM DOS DADOS NA PILHA:\n";
    listarPilha(pilha);

    itempilha = ItemPilha(pilha);
    std::cout << "\n\nITEM DISPONÍVEL NO TOPO DA PILHA: " << itempilha.nome << itempilha.idade << "\n";
    r = removerItemPilha(pilha);
    if (r >= 0)
    {
        std::cout << "ITEM REMOVIDO COM SUCESSO DA PILHA\n";
    }
    else
    {
        std::cout << "PILHA ESTÁ VAZIA\n";
    }

    std::cout << "\n\nLISTAGEM DOS DADOS NA PILHA:\n";
    listarPilha(pilha);

    itempilha = ItemPilha(pilha);
    std::cout << "\n\nITEM DISPONÍVEL NO TOPO DA PILHA: " << itempilha.nome << itempilha.idade << "\n";
    r = removerItemPilha(pilha);
    if (r >= 0)
    {
        std::cout << "ITEM REMOVIDO COM SUCESSO DA PILHA\n";
    }
    else
    {
        std::cout << "PILHA ESTÁ VAZIA\n";
    }

    std::cout << "\n\nLISTAGEM DOS DADOS NA PILHA:\n";
    listarPilha(pilha);


    itempilha = ItemPilha(pilha);
    std::cout << "\n\nITEM DISPONÍVEL NO TOPO DA PILHA: " << itempilha.nome << itempilha.idade << "\n";
    r = removerItemPilha(pilha);
    if (r >= 0)
    {
        std::cout << "ITEM REMOVIDO COM SUCESSO DA PILHA\n";
    }
    else
    {
        std::cout << "PILHA ESTÁ VAZIA\n";
    }

    std::cout << "\n\nLISTAGEM DOS DADOS NA PILHA:\n";
    listarPilha(pilha);


    itempilha = ItemPilha(pilha);
    std::cout << "\n\nITEM DISPONÍVEL NO TOPO DA PILHA: " << itempilha.nome << itempilha.idade << "\n";
    r = removerItemPilha(pilha);
    if (r >= 0)
    {
        std::cout << "ITEM REMOVIDO COM SUCESSO DA PILHA\n";
    }
    else
    {
        std::cout << "PILHA ESTÁ VAZIA\n";
    }

    std::cout << "\n\nLISTAGEM DOS DADOS NA PILHA:\n";
    listarPilha(pilha);


    itempilha = ItemPilha(pilha);
    std::cout << "\n\nITEM DISPONÍVEL NO TOPO DA PILHA: " << itempilha.nome << itempilha.idade << "\n";
    r = removerItemPilha(pilha);
    if (r >= 0)
    {
        std::cout << "ITEM REMOVIDO COM SUCESSO DA PILHA\n";
    }
    else
    {
        std::cout << "PILHA ESTÁ VAZIA\n";
    }

    std::cout << "\n\nLISTAGEM DOS DADOS NA PILHA:\n";
    listarPilha(pilha);


    itempilha = ItemPilha(pilha);
    std::cout << "\n\nITEM DISPONÍVEL NO TOPO DA PILHA: " << itempilha.nome << itempilha.idade << "\n";
    r = removerItemPilha(pilha);
    if (r >= 0)
    {
        std::cout << "ITEM REMOVIDO COM SUCESSO DA PILHA\n";
    }
    else
    {
        std::cout << "PILHA ESTÁ VAZIA\n";
    }

    std::cout << "\n\nLISTAGEM DOS DADOS NA PILHA:\n";
    listarPilha(pilha);



}



// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln