#pragma once

typedef struct NaryTreeNode {
    void* data;
    int weight;
    struct NaryTreeNode* first_child;
    struct NaryTreeNode* next_sibling;
} NaryTreeNode;

NaryTreeNode* nary_tree_create_node(void* data, int weight);
void nary_tree_free(NaryTreeNode* root);

void nary_tree_traverse_preorder(NaryTreeNode* root, void (*visit)(NaryTreeNode* node, int depth));
void nary_tree_traverse_postorder(NaryTreeNode* root, void (*visit)(NaryTreeNode* node, int depth));


typedef struct BinaryTreeNode {
    void* data;
    int weight;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

BinaryTreeNode* binary_tree_create_node(void* data, int weight);
void binary_tree_free(BinaryTreeNode* root);

void binary_tree_traverse_preorder(BinaryTreeNode* root, void (*visit)(BinaryTreeNode* node, int depth));
void binary_tree_traverse_inorder(BinaryTreeNode* root, void (*visit)(BinaryTreeNode* node, int depth));
void binary_tree_traverse_postorder(BinaryTreeNode* root, void (*visit)(BinaryTreeNode* node, int depth));
