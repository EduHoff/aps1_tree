#include <stdio.h>
#include <stdlib.h>
#include "ds.h"
#include "utils.h"

static void traverse_inorder_step_by_step(BinaryTree* node, BinaryTree* root) {
    if (node == NULL) return;

    traverse_inorder_step_by_step(node->left, root);

    clear_screen();
    printf("=== VISUALIZACAO PASSO A PASSO DO PERCURSO (EM-ORDEM) ===\n\n");
    print_tree_highlight(root, print_int, node);
    printf("\n[Sinalizador '==>'] Visitando o no: %d\n", *(int*)node->data);
    printf("Pressione Enter para ir ao proximo no...");
    getchar();

    traverse_inorder_step_by_step(node->right, root);
}

int main(void) {
    BinaryTree* root = NULL;
    int option = 0;
    int value = 0;

    while (1) {
        clear_screen();
        printf("=======================================\n");
        printf("      SISTEMA DE GERENCIAMENTO AVL     \n");
        printf("=======================================\n");
        printf(" 1. Inserir Elemento\n");
        printf(" 2. Remover Elemento\n");
        printf(" 3. Percorrer Passo a Passo (Em-Ordem)\n");
        printf(" 4. Visualizar Arvore Atual\n");
        printf(" 5. Executar Desafio 1 (Benchmark de Buscas)\n");
        printf(" 0. Sair\n");
        printf("=======================================\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &option) != 1) break;

        if (option == 0) break;

        switch (option) {
            case 1: {
                printf("Digite o valor inteiro para INSERIR: ");
                scanf("%d", &value);
                int* new_val = (int*) malloc(sizeof(int));
                *new_val = value;
                root = tree_insert(root, new_val, compare_ints);
                printf("\nValor %d inserido com sucesso!\n", value);
                printf("\nEstrutura Apos Insercao:\n");
                print_tree(root, print_int);
                printf("\nPressione Enter para continuar...");
                getchar(); getchar();
                break;
            }
            case 2: {
                printf("Digite o valor inteiro para REMOVER: ");
                scanf("%d", &value);
                root = tree_delete(root, &value, compare_ints);
                printf("\nProcesso de remocao concluido!\n");
                printf("\nEstrutura Apos Remocao:\n");
                print_tree(root, print_int);
                printf("\nPressione Enter para continuar...");
                getchar(); getchar();
                break;
            }
            case 3: {
                if (root == NULL) {
                    printf("\nA arvore esta vazia!\n");
                    printf("\nPressione Enter para continuar...");
                    getchar(); getchar();
                } else {
                    getchar();
                    traverse_inorder_step_by_step(root, root);
                    printf("\nPercurso finalizado!\n");
                    printf("Pressione Enter para continuar...");
                    getchar();
                }
                break;
            }
            case 4: {
                clear_screen();
                printf("=== ESTRUTURA ATUAL DA ARVORE ===\n\n");
                print_tree(root, print_int);
                printf("\nPressione Enter para continuar...");
                getchar(); getchar();
                break;
            }
            case 5: {
                run_benchmark();
                break;
            }
            default:
                printf("\nOpcao invalida!\n");
                getchar(); getchar();
                break;
        }
    }

    tree_free(root);
    return 0;
}
