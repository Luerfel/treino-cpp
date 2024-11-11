#include <iostream>
#include <string>

struct dados
{
    char Sintoma[50];
    int ID;
};

struct elemento {

    dados cadastro;
    struct elemento* proxVerdade;
    struct elemento* proxFalso;
};

typedef struct elemento Elem;

// DEFINIR O DESCRITOS DA LISTA 
struct Descritor {

    Elem* inicio;
    int tamanho;
    Elem* final;
};

Descritor* arvore;

//CRIAR A LISTA
Descritor* criar(void) {

    Descritor* descritor;
    descritor = (Descritor*)malloc(sizeof(Descritor));
    descritor->final = NULL;
    descritor->inicio = NULL;
    descritor->tamanho = -1;

    return descritor;
}


Elem *buscarID(Elem* e, int ID)
{
    Elem* result;

    // INICIALIZANDO VALOR DE RETORNO NULL
    if (e == NULL) {
        return NULL; // Se o nó atual é NULL, retorna NULL.
    }

    if (e->cadastro.ID == ID) {
        return e; // Se encontrou o ID, retorna o nó atual.
    }

    Elem* vd = e->proxVerdade;
    if (vd != NULL) {
        if (vd->cadastro.ID == ID) {
            return vd; // Se o próximo "verdadeiro" tem o ID, retorna ele.
        } else {
            result = buscarID(vd, ID); // Continua buscando na subárvore "verdadeira".
            if (result != NULL && result->cadastro.ID == ID) {
                return result;
            }
        }
    }

    Elem* fls = e->proxFalso;
    if (fls != NULL) {
        if (fls->cadastro.ID == ID) {
            return fls; // Se o próximo "falso" tem o ID, retorna ele.
        } else {
            result = buscarID(fls, ID); // Continua buscando na subárvore "falsa".
            if (result != NULL && result->cadastro.ID == ID) {
                return result;
            }
        }
    }

    return NULL; // Caso não encontre, retorna NULL.
}


//CADASTRAR UM ITEM NA ARVORE
int inserir(Descritor* descritor, int ID, int status, dados d)
{

    Elem* novo;
    novo = (Elem*)malloc(sizeof(Elem));
    novo->cadastro = d;
    //novo->antVerdade = NULL;
    novo->proxVerdade = NULL;
    //novo->antFalso = NULL;
    novo->proxFalso = NULL;

    Elem* pontoCadastro;
    pontoCadastro = (Elem*)malloc(sizeof(Elem));

    //Caso 1 - Lista vazia
    if (descritor->tamanho <0 ) {
        descritor->inicio = novo;
        descritor->final = novo;
    }
    else
    {
        pontoCadastro = buscarID(descritor->inicio, ID);
        if (status == true)
        {
            pontoCadastro->proxVerdade = novo;
        }
        else
        {
            pontoCadastro->proxFalso = novo;
        }
    }

    (descritor->tamanho)++;
    return 1;
}

//LISTAR ITENS E CONEXÕES NA ARVORE
void listarArvore(Elem* e)
{
    if (e != NULL)
    {
        if (e->proxVerdade != NULL)
            std::cout << e->cadastro.ID << "  " << e->cadastro.Sintoma << "  TRUE:  " << e->proxVerdade->cadastro.Sintoma << "   " << e->proxVerdade->cadastro.ID << "\n";
        else
            std::cout << e->cadastro.ID << "  " << e->cadastro.Sintoma << "  TRUE:  NULL\n";

        if (e->proxFalso != NULL)
            std::cout << e->cadastro.ID << "  " << e->cadastro.Sintoma << "  FALSO: " << e->proxFalso->cadastro.Sintoma << "   " << e->proxFalso->cadastro.ID << "\n";
        else
            std::cout << e->cadastro.ID << "  " << e->cadastro.Sintoma << "  FALSO: NULL\n";
        listarArvore(e->proxVerdade);
        listarArvore(e->proxFalso);
    }
}


void main()
{
    int valor;
    int resultado;
    dados vl;
    dados vlresultado;

    arvore = criar();

 

    // ****************************************************************
    // CADASTRAR
    // ****************************************************************
    //NÓ ZERO
    strcpy_s(vl.Sintoma, "DORPEITO");
    vl.ID = (arvore->tamanho)+1;
    resultado = inserir(arvore, 0, true, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    //COMPLETAR NÓ ZERO  1 - Verdade   2 - Falso
    strcpy_s(vl.Sintoma, "PRESSAOALTA");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 0, true, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.Sintoma, "DORBRACOESQUERDO");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 0, false, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    //COMPLETAR NÓ 1  3 - Verdade   4 - Falso
    strcpy_s(vl.Sintoma, "ECCIRREGULAR3");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 1, true, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.Sintoma, "ECGIRREGULAR4");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 1, false, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    //COMPLETAR NÓ 2  5 - Verdade   6 - Falso
    strcpy_s(vl.Sintoma, "SENSACAOPESODESCONFORTO");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 2, true, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.Sintoma, "SENSACAOPESOESTOMAGO");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 2, false, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    //COMPLETAR NÓ 4  7 - Verdade   8 - Falso
    strcpy_s(vl.Sintoma, "UTIAMBULATORIAL");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 4, true, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.Sintoma, "SOROAMBILATORIONORMAL");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 4, false, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    //COMPLETAR NÓ 5  9 - Verdade   10 - Falso
    strcpy_s(vl.Sintoma, "NAUSEA");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 5, true, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.Sintoma, "ECGIRREGULAR");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 5, false, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";


    //COMPLETAR NÓ 6  11 - Verdade   12 - Falso
    strcpy_s(vl.Sintoma, "ANTIIACIDOSOROAMBULATORIO");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 6, true, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.Sintoma, "ANTIIACIDOCASA");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 6, false, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    //COMPLETAR NÓ 10  13 - Verdade   14 - Falso
    strcpy_s(vl.Sintoma, "FALTAAR");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 10, true, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.Sintoma, "ESTABILIZARARRITIMIAUTIAMBULATORIO");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 10, false, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    //COMPLETAR NÓ 13  15 - Verdade   16 - Falso
    strcpy_s(vl.Sintoma, "UTICARDIO");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 13, true, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.Sintoma, "UTIAMBULATORIAL");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 13, false, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    //COMPLETAR NÓ 9  17 - Verdade   18 - Falso
    strcpy_s(vl.Sintoma, "FALTAAR");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 9, true, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.Sintoma, "UTIAMBULATORIAL");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 9, false, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";


    //COMPLETAR NÓ 17  19 - Verdade   20 - Falso
    strcpy_s(vl.Sintoma, "UTICARDIO");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 17, true, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.Sintoma, "UTIAMBULATORIAL");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 17, false, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    //COMPLETAR NÓ 3  21 - Verdade   22 - Falso
    strcpy_s(vl.Sintoma, "FALTAAR");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 3, true, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.Sintoma, "ESTABILIZARPRESSAOAMBULATORIO");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 3, false, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    //COMPLETAR NÓ 21  23 - Verdade   24 - Falso
    strcpy_s(vl.Sintoma, "UTICARDIO");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 21, true, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    strcpy_s(vl.Sintoma, "UTIAMBULATORIO");
    vl.ID = (arvore->tamanho) + 1;
    resultado = inserir(arvore, 21, false, vl);
    if (resultado == 1)
        std::cout << "DADO CADASTRADO COM SUCESSO:  " << vl.Sintoma << "  " << vl.ID << "\n";
    else
        std::cout << "ERRO NO CADASTRO DOS DADOS";

    std::cout << "\n\n******************************************\n";
    std::cout << "LISTAR CONEXOES DA ARVORE\n";
    listarArvore(arvore->inicio);

}