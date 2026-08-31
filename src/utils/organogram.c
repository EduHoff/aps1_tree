#include <stdio.h>
#include "ds.h"

static void print_organogram_aux(NaryTreeNode* root, int nivel){
    if (root == NULL){
        return;
    }

    for (int i=0; i<nivel; i++){
        printf(" |--");
    }

    printf(" [%s]\n", (char*) root->data);
    print_organogram_aux(root->first_child, nivel+1);
    print_organogram_aux(root->next_sibling, nivel);
}

void print_organogram(NaryTreeNode* root){
    print_organogram_aux(root, 0);
}
