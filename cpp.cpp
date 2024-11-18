#include <iostream>
using namespace std;

// Estrutura de um nó na árvore
struct Node {
    int data;        // Dados armazenados no nó
    Node* left;      // Ponteiro para o filho esquerdo
    Node* right;     // Ponteiro para o filho direito
};

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Função para inserir um valor na árvore
Node* insertNode(Node* root, int data) {
    // Se a árvore está vazia, cria um novo nó como raiz
    if (root == nullptr) {
        return createNode(data);
    }
    
    // Caso contrário, insere recursivamente na subárvore correta
    if (data < root->data) {
        root->left = insertNode(root->left, data); // Insere à esquerda
    } else if (data > root->data) {
        root->right = insertNode(root->right, data); // Insere à direita
    }
    
    return root;
}

// Função para realizar um percurso em ordem (in-order traversal)
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);       // Percorre a subárvore esquerda
        cout << root->data << " ";          // Processa o nó atual
        inOrderTraversal(root->right);      // Percorre a subárvore direita
    }
}

// Função principal
int main() {
    Node* root = nullptr; // Inicializa a árvore vazia

    // Insere valores na árvore
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Mostra os valores da árvore em ordem
    cout << "Percurso em ordem (in-order): ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
