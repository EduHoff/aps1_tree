#pragma once

typedef struct NaryTreeNode {
    void* data;
    int weight;
    struct NaryTreeNode* first_child;
    struct NaryTreeNode* next_sibling;
} NaryTreeNode;

typedef struct BinaryTreeNode {
    void* data;
    int weight;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

NaryTreeNode* nary_tree_create_node(void* data, int weight);
void nary_tree_free(NaryTreeNode* root);
