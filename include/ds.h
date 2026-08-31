#pragma once

typedef struct NaryTreeNode {
    void* data;
    int weight;
    struct NaryTreeNode* first_child;
    struct NaryTreeNode* next_sibling;
} NaryTreeNode;

NaryTreeNode* create_node(void* data, int weight);
void free_tree(NaryTreeNode* root);
