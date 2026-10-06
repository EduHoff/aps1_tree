#include "utils.h"
#include <stdio.h>

static void print_tree_aux(BinaryTree* node, PrintFn print_data, int level, BinaryTree* target) {
    if (node == NULL) return;

    for (int i = 0; i < level; i++) {
        printf(" |--");
    }

    if (target != NULL && node == target) {
        printf(" ==> [");
        print_data(node->data);
        printf("] <== (h:%d)\n", node->height);
    } else {
        printf(" [");
        print_data(node->data);
        printf("] (h:%d)\n", node->height);
    }

    print_tree_aux(node->left, print_data, level + 1, target);
    print_tree_aux(node->right, print_data, level + 1, target);
}

void print_tree(BinaryTree* root, PrintFn print_data) {
    if (root == NULL) {
        printf("(árvore vazia)\n");
        return;
    }
    print_tree_aux(root, print_data, 0, NULL);
}

void print_tree_highlight(BinaryTree* root, PrintFn print_data, BinaryTree* target) {
    if (root == NULL) {
        printf("(árvore vazia)\n");
        return;
    }
    print_tree_aux(root, print_data, 0, target);
}

void print_int(const void* data) {
    if (data) printf("%d", *(const int*)data);
}

void traverse_inorder_step_by_step(BinaryTree* node, BinaryTree* root) {
    if (node == NULL) return;

    traverse_inorder_step_by_step(node->left, root);

    clear_screen();
    printf("=== VISUALIZACAO PASSO A PASSO DO PERCURSO (EM-ORDEM) ===\n\n");
    print_tree_highlight(root, print_int, node);
    printf("\n[Sinalizador '==>'] Visitando o no: %d\n", *(int*)node->data);
    printf("Pressione Enter para ir ao proximo no...");
    getchar();

    traverse_inorder_step_by_step(node->right, root);
}
