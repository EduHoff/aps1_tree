#include <stdlib.h>
#include "ds.h"

NaryTreeNode* nary_tree_create_node(void* data, int weight) {
    NaryTreeNode* new_node = (NaryTreeNode*) malloc(sizeof(NaryTreeNode));

    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->weight = weight;
    new_node->first_child = NULL;
    new_node->next_sibling = NULL;

    return new_node;
}

void nary_tree_free(NaryTreeNode* root) {
    if(root == NULL) {
        return;
    }

    nary_tree_free(root->first_child);
    nary_tree_free(root->next_sibling);
    free(root);
}

// Busca um nó na árvore comparando os dados.
NaryTreeNode* nary_tree_find(NaryTreeNode* root, const void* target_data, int (*compare)(const void*, const void*));

// Conecta um novo nó na lista de filhos de um pai existente.
int nary_tree_add_child(NaryTreeNode* parent_node, void* data, int weight);

// Desconecta o nó da árvore, ajusta os ponteiros dos vizinhos e apaga a subárvore.
int nary_tree_remove_node(NaryTreeNode* root, NaryTreeNode* target);

// Visita todos os nós em ordem e executa uma ação a cada passo.
void nary_tree_traverse(NaryTreeNode* root, void (*visit)(NaryTreeNode* node, int depth));
