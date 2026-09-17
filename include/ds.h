#pragma once

typedef struct BinaryTree {
    void* data;
    int weight;
    int height;
    struct BinaryTree* left;
    struct BinaryTree* right;
} BinaryTree;

void tree_free(BinaryTree* root);
