#include <stdlib.h>
#include "ds.h"

BinaryTreeNode* binary_tree_create_node(void* data, int weight) {
    BinaryTreeNode* new_node = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));

    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->weight = weight;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void binary_tree_free(BinaryTreeNode* root) {
    if(root == NULL) {
        return;
    }

    binary_tree_free(root->left);
    binary_tree_free(root->right);
    free(root);
}

static void binary_tree_traverse_preorder_aux(BinaryTreeNode* node, void (*visit)(BinaryTreeNode* node, int depth), int current_depth) {
    if (node == NULL) {
        return;
    }

    visit(node, current_depth);
    binary_tree_traverse_preorder_aux(node->left, visit, current_depth+1);
    binary_tree_traverse_preorder_aux(node->right, visit, current_depth+1);
}

void binary_tree_traverse_preorder(BinaryTreeNode* root, void (*visit)(BinaryTreeNode* node, int depth)) {
    binary_tree_traverse_preorder_aux(root, visit, 0);
}

static void binary_tree_traverse_inorder_aux(BinaryTreeNode* node, void (*visit)(BinaryTreeNode* node, int depth), int current_depth) {
    if (node == NULL) {
        return;
    }

    binary_tree_traverse_inorder_aux(node->left, visit, current_depth+1);
    visit(node, current_depth);
    binary_tree_traverse_inorder_aux(node->right, visit, current_depth+1);
}

void binary_tree_traverse_inorder(BinaryTreeNode* root, void (*visit)(BinaryTreeNode* node, int depth)){
    binary_tree_traverse_inorder_aux(root, visit, 0);
}

static void binary_tree_traverse_postorder_aux(BinaryTreeNode* node, void (*visit)(BinaryTreeNode* node, int depth), int current_depth) {
    if (node == NULL) {
        return;
    }

    binary_tree_traverse_postorder_aux(node->left, visit, current_depth+1);
    binary_tree_traverse_postorder_aux(node->right, visit, current_depth+1);
    visit(node, current_depth);
}

void binary_tree_traverse_postorder(BinaryTreeNode* root, void (*visit)(BinaryTreeNode* node, int depth)){
    binary_tree_traverse_postorder_aux(root, visit, 0);
}
