#include "ds.h"
#include <stdlib.h>

void tree_free(BinaryTree* root) {
    if (root == NULL) return;

    tree_free(root->left);
    tree_free(root->right);
    free(root);
}
