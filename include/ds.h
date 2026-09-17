#pragma once

typedef struct BinaryTree {
    void* data;
    int weight;
    struct BinaryTree* left;
    struct BinaryTree* right;
} BinaryTree;

void tree_free(BinaryTree* root);
