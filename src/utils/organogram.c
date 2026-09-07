#include <stdio.h>
#include "ds.h"

static void nary_tree_print_organogram_aux(NaryTreeNode* node, int depth, void* args) {
    (void)args;

    for (int i = 0; i < depth; i++) {
        printf(" |--");
    }
    printf(" [%s]\n", (char*) node->data);
}

void nary_tree_print_organogram(NaryTreeNode* root) {
    if (root == NULL) return;
    nary_tree_traverse_preorder(root, nary_tree_print_organogram_aux, NULL);
}

static void binary_tree_print_organogram_aux(BinaryTreeNode* node, int depth, void* args) {
    (void)args;

    for (int i = 0; i < depth; i++) {
        printf(" |--");
    }
    printf(" [%s]\n", (char*) node->data);
}

void binary_tree_print_organogram(BinaryTreeNode* root) {
    if (root == NULL) return;
    binary_tree_traverse_preorder(root, binary_tree_print_organogram_aux, NULL);
}
