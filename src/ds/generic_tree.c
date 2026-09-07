#include <stdlib.h>
#include "ds.h"

NaryTreeNode* nary_tree_create_node(void* data, int weight) {
    NaryTreeNode* new_node = (NaryTreeNode*) malloc(sizeof(NaryTreeNode));
    if (new_node == NULL) return NULL;

    new_node->data = data;
    new_node->weight = weight;
    new_node->first_child = NULL;
    new_node->next_sibling = NULL;

    return new_node;
}

void nary_tree_free(NaryTreeNode* root) {
    if (root == NULL) return;

    nary_tree_free(root->first_child);
    nary_tree_free(root->next_sibling);
    free(root);
}

static void nary_tree_traverse_preorder_aux(NaryTreeNode* node, NaryTreeFn fn, void* args, int current_depth) {
    if (node == NULL) return;

    fn(node, current_depth, args); // Modificado: repassa current_depth
    nary_tree_traverse_preorder_aux(node->first_child, fn, args, current_depth + 1);
    nary_tree_traverse_preorder_aux(node->next_sibling, fn, args, current_depth);
}

void nary_tree_traverse_preorder(NaryTreeNode* root, NaryTreeFn fn, void* args) {
    nary_tree_traverse_preorder_aux(root, fn, args, 0);
}

static void nary_tree_traverse_postorder_aux(NaryTreeNode* node, NaryTreeFn fn, void* args, int current_depth) {
    if (node == NULL) return;

    nary_tree_traverse_postorder_aux(node->first_child, fn, args, current_depth + 1);
    nary_tree_traverse_postorder_aux(node->next_sibling, fn, args, current_depth);
    fn(node, current_depth, args);
}

void nary_tree_traverse_postorder(NaryTreeNode* root, NaryTreeFn fn, void* args) {
    nary_tree_traverse_postorder_aux(root, fn, args, 0);
}