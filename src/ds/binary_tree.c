#include <stdlib.h>
#include "ds.h"

BinaryTreeNode* binary_tree_create_node(void* data, int weight) {
    BinaryTreeNode* new_node = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
    if (new_node == NULL) return NULL;

    new_node->data = data;
    new_node->weight = weight;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void binary_tree_free(BinaryTreeNode* root) {
    if (root == NULL) return;

    binary_tree_free(root->left);
    binary_tree_free(root->right);
    free(root);
}

static void binary_tree_traverse_preorder_aux(BinaryTreeNode* node, BinaryTreeFn fn, void* args, int current_depth) {
    if (node == NULL) return;

    fn(node, current_depth, args);
    binary_tree_traverse_preorder_aux(node->left, fn, args, current_depth + 1);
    binary_tree_traverse_preorder_aux(node->right, fn, args, current_depth + 1);
}

void binary_tree_traverse_preorder(BinaryTreeNode* root, BinaryTreeFn fn, void* args) {
    binary_tree_traverse_preorder_aux(root, fn, args, 0);
}

static void binary_tree_traverse_inorder_aux(BinaryTreeNode* node, BinaryTreeFn fn, void* args, int current_depth) {
    if (node == NULL) return;

    binary_tree_traverse_inorder_aux(node->left, fn, args, current_depth + 1);
    fn(node, current_depth, args);
    binary_tree_traverse_inorder_aux(node->right, fn, args, current_depth + 1);
}

void binary_tree_traverse_inorder(BinaryTreeNode* root, BinaryTreeFn fn, void* args) {
    binary_tree_traverse_inorder_aux(root, fn, args, 0);
}

static void binary_tree_traverse_postorder_aux(BinaryTreeNode* node, BinaryTreeFn fn, void* args, int current_depth) {
    if (node == NULL) return;

    binary_tree_traverse_postorder_aux(node->left, fn, args, current_depth + 1);
    binary_tree_traverse_postorder_aux(node->right, fn, args, current_depth + 1);
    fn(node, current_depth, args);
}

void binary_tree_traverse_postorder(BinaryTreeNode* root, BinaryTreeFn fn, void* args) {
    binary_tree_traverse_postorder_aux(root, fn, args, 0);
}

BinaryTreeNode* binary_tree_find(BinaryTreeNode* root, const void* target_data, int (*compare)(const void*, const void*)) {
    if (root == NULL) {
        return NULL;
    }

    if (compare(root->data, target_data) == 0) {
        return root;
    }

    BinaryTreeNode* found = binary_tree_find(root->left, target_data, compare);
    if (found != NULL) {
        return found;
    }

    return binary_tree_find(root->right, target_data, compare);
}
