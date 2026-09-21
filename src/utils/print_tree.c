#include "utils.h"
#include <stdio.h>

static void print_tree_aux(BinaryTree* node, PrintFn print_data, int level) {
    if (node == NULL) return;

    for (int i = 0; i < level; i++) {
        printf(" |--");
    }

    printf(" [");
    print_data(node->data);
    printf("] (h:%d)\n", node->height);

    print_tree_aux(node->left, print_data, level + 1);
    print_tree_aux(node->right, print_data, level + 1);
}

void print_tree(BinaryTree* root, PrintFn print_data) {
    if (root == NULL) {
        printf("(árvore vazia)\n");
        return;
    }
    print_tree_aux(root, print_data, 0);
}

void print_int(const void* data) {
    if (data) printf("%d", *(const int*)data);
}