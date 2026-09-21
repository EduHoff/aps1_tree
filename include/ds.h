#pragma once

typedef struct BinaryTree {
    void* data;
    int height;
    struct BinaryTree* left;
    struct BinaryTree* right;
} BinaryTree;

typedef int (*CompareFn)(const void* a, const void* b);

BinaryTree* create_node(void* data);
void tree_free(BinaryTree* root);
BinaryTree* tree_insert(BinaryTree* root, void* data, CompareFn compare);


