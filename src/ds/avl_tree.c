#include "ds.h"
#include <stdlib.h>

BinaryTree* create_node(void* data, int weight) {
    BinaryTree* new_node = (BinaryTree*) malloc(sizeof(BinaryTree));
    if (new_node == NULL) return NULL;

    new_node->data = data;
    new_node->weight = weight;
    new_node->height = 1;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void tree_free(BinaryTree* root) {
    if (root == NULL) return;

    tree_free(root->left);
    tree_free(root->right);
    free(root);
}

int get_height(BinaryTree* node) {
    if (node == NULL) return 0;
    return node->height;
}

//get_balance_factor(node): Retorna get_height(node->left) - get_height(node->right)
// update_height(node): Atualiza a altura do nó atual comparando os filhos -> 1 + max(get_height(node->left), get_height(node->right))

//tree_insert
