#pragma once

typedef struct BinaryTree {
    void* data;
    int height;
    struct BinaryTree* left;
    struct BinaryTree* right;
} BinaryTree;

BinaryTree* create_node(void* data);
void tree_free(BinaryTree* root);
int get_height(BinaryTree* node);
int get_balance_factor(BinaryTree* node);
