#include "ds.h"
#include <stdlib.h>

BinaryTree* create_node(void* data) {
    BinaryTree* new_node = (BinaryTree*) malloc(sizeof(BinaryTree));
    if (new_node == NULL) return NULL;

    new_node->data = data;
    new_node->height = 1;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void tree_free(BinaryTree* root) {
    if (root == NULL) return;

    tree_free(root->left);
    tree_free(root->right);
    free(root);
}

int get_height(BinaryTree* node) {
    if (node == NULL) return 0;
    return node->height;
}

int get_balance_factor(BinaryTree* node){
    return get_height(node->left) - get_height(node->right);
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

void update_height(BinaryTree* node) {
    if (node == NULL) return;

    int left_h = get_height(node->left);
    int right_h = get_height(node->right);

    node->height = 1 + max(left_h, right_h);
}

BinaryTree* rotate_left(BinaryTree* x) {
    BinaryTree* y = x->right;
    BinaryTree* T2 = y->left;

    y->left = x;
    x->right = T2;

    update_height(x);
    update_height(y);

    return y;
}

BinaryTree* rotate_right(BinaryTree* y) {
    BinaryTree* x = y->left;
    BinaryTree* T2 = x->right;

    x->right = y;
    y->left = T2;

    update_height(y);
    update_height(x);

    return x;
}

BinaryTree* tree_insert(BinaryTree* root, void* data, CompareFn compare) {
    if (root == NULL) return create_node(data);

    int cmp = compare(data, root->data);

    if (cmp < 0) {
        root->left = tree_insert(root->left, data, compare);
    } else if (cmp > 0) {
        root->right = tree_insert(root->right, data, compare);
    } else {
        return root;
    }

    update_height(root);

    int balance = get_balance_factor(root);

    if (balance > 1 && root->left != NULL && compare(data, root->left->data) < 0) {
        return rotate_right(root);
    }

    if (balance < -1 && root->right != NULL && compare(data, root->right->data) > 0) {
        return rotate_left(root);
    }

    if (balance > 1 && root->left != NULL && compare(data, root->left->data) > 0) {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    if (balance < -1 && root->right != NULL && compare(data, root->right->data) < 0) {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}
