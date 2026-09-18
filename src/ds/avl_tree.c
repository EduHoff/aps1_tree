#include "ds.h"
#include <stdlib.h>

BinaryTree* create_node(void* data) {
    BinaryTree* new_node = (BinaryTree*) malloc(sizeof(BinaryTree));
    if (new_node == NULL) return NULL;

    new_node->data = data;
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

int get_balance_factor(BinaryTree* node){
    return get_height(node->left) - get_height(node->right);
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

void update_height(BinaryTree* node) {
    if (node == NULL) return;

    int left_h = get_height(node->left);
    int right_h = get_height(node->right);

    node->height = 1 + max(left_h, right_h);
}

//tree_insert
