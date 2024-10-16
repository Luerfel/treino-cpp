#include <iostream>
#include <cstring>  // Para usar strcpy e strcmp
#include <cstdlib>  // Para malloc e free

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
int inserir(Descritor* descritor, dados d);
void listarInicio(Descritor* l);
void listarFim(Descritor* l);
int remover(Descritor* descritor, const char* nome);

// Variável global
Descritor* lista;

int main() {
    dados vl;

    lista = criar();

    strcpy(vl.nome, "JUVENAL");
    vl.idade = 10;
    inserir(lista, vl);

    strcpy(vl.nome, "ANTENOR");
    vl.idade = 20;
    inserir(lista, vl);

    strcpy(vl.nome, "PANTURRILHA");
    vl.idade = 30;
    inserir(lista, vl);

    std::cout << "\nLISTAGEM DO INÍCIO DA LISTA ATÉ O FIM:\n";
    listarInicio(lista);

    // Remover um item da lista
    std::cout << "\nRemovendo 'ANTENOR' da lista...\n";
    if (remover(lista, "ANTENOR")) {
        std::cout << "'ANTENOR' removido com sucesso.\n";
    } else {
        std::cout << "Elemento 'ANTENOR' não encontrado.\n";
    }

    std::cout << "\nLISTAGEM ATUALIZADA DO INÍCIO DA LISTA ATÉ O FIM:\n";
    listarInicio(lista);

    std::cout << "\nFIM\n";

    return 0;
}

// Função para criar a lista
Descritor* criar() {
    Descritor* descritor = (Descritor*)malloc(sizeof(Descritor));
    descritor->final = nullptr;
    descritor->inicio = nullptr;
    descritor->tamanho = 0;

    return descritor;
}

// Função para inserir um item na lista
int inserir(Descritor* descritor, dados d) {
    Elem* novo = (Elem*)malloc(sizeof(Elem));
    novo->cadastro = d;
    novo->ant = nullptr;
    novo->prox = nullptr;

    // Caso 1 - Lista vazia
    if (descritor->tamanho == 0) {
        descritor->inicio = novo;
        descritor->final = novo;
    } else {
        descritor->final->prox = novo;
        novo->ant = descritor->final;
        descritor->final = novo;
    }

    descritor->tamanho++;
    return 1;
}

// Função para listar do início ao fim
void listarInicio(Descritor* l) {
    Elem* pos = l->inicio;

    while (pos != nullptr) {
        std::cout << "NOME:  " << pos->cadastro.nome << "\n";
        std::cout << "IDADE: " << pos->cadastro.idade << "\n";
        pos = pos->prox;
    }
}

// Função para listar do fim ao início
void listarFim(Descritor* l) {
    Elem* pos = l->final;

    while (pos != nullptr) {
        std::cout << "NOME:  " << pos->cadastro.nome << "\n";
        std::cout << "IDADE: " << pos->cadastro.idade << "\n";
        pos = pos->ant;
    }
}

// Função para remover um item da lista
int remover(Descritor* descritor, const char* nome) {
    if (descritor == nullptr || descritor->inicio == nullptr) {
        // Lista vazia ou descritor inválido
        return 0;
    }

    Elem* atual = descritor->inicio;

    // Percorre a lista para encontrar o nó a ser removido
    while (atual != nullptr) {
        if (strcmp(atual->cadastro.nome, nome) == 0) {
            // Nó encontrado, proceder com a remoção

            // Caso 2: Nó único
            if (atual->ant == nullptr && atual->prox == nullptr) {
                descritor->inicio = nullptr;
                descritor->final = nullptr;
            }
            // Caso 3: Primeiro nó
            else if (atual->ant == nullptr) {
                descritor->inicio = atual->prox;
                atual->prox->ant = nullptr;
            }
            // Caso 4: Último nó
            else if (atual->prox == nullptr) {
                descritor->final = atual->ant;
                atual->ant->prox = nullptr;
            }
            // Caso 5: Nó do meio
            else {
                atual->ant->prox = atual->prox;
                atual->prox->ant = atual->ant;
            }

            free(atual);
            descritor->tamanho--;

            return 1; // Remoção bem-sucedida
        }
        atual = atual->prox;
    }

    return 0; // Nó não encontrado
}

