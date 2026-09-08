#pragma once

typedef struct NaryTreeNode {
    void* data;
    int weight;
    struct NaryTreeNode* first_child;
    struct NaryTreeNode* next_sibling;
} NaryTreeNode;

NaryTreeNode* nary_tree_create_node(void* data, int weight);
void nary_tree_free(NaryTreeNode* root);

typedef void (*NaryTreeFn)(NaryTreeNode* node, int depth, void* args);
void nary_tree_traverse_preorder(NaryTreeNode* root, NaryTreeFn fn, void* args);
void nary_tree_traverse_postorder(NaryTreeNode* root, NaryTreeFn fn, void* args);

NaryTreeNode* nary_tree_find(NaryTreeNode* root, const void* target_data, int (*compare)(const void*, const void*));
int nary_tree_add_child(NaryTreeNode* parent_node, void* data, int weight);
int nary_tree_remove_node(NaryTreeNode* root, NaryTreeNode* target);


typedef struct BinaryTreeNode {
    void* data;
    int weight;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

BinaryTreeNode* binary_tree_create_node(void* data, int weight);
void binary_tree_free(BinaryTreeNode* root);

typedef void (*BinaryTreeFn)(BinaryTreeNode* node, int depth, void* args);
void binary_tree_traverse_preorder(BinaryTreeNode* root, BinaryTreeFn fn, void* args);
void binary_tree_traverse_inorder(BinaryTreeNode* root, BinaryTreeFn fn, void* args);
void binary_tree_traverse_postorder(BinaryTreeNode* root, BinaryTreeFn fn, void* args);

BinaryTreeNode* binary_tree_find(BinaryTreeNode* root, const void* target_data, int (*compare)(const void*, const void*));