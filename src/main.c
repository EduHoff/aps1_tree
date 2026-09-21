#include <stdio.h>
#include <stdlib.h>
#include "ds.h"
#include "utils.h"

int main(void) {
    clear_screen();

    BinaryTree* root = NULL;

    int values[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(values) / sizeof(values[0]);

    printf("=== TESTE DE INSERCAO NA ARVORE AVL ===\n\n");

    for (int i = 0; i < n; i++) {
        printf("----------------------------------------\n");
        printf("Inserindo o valor: %d\n", values[i]);

        root = tree_insert(root, &values[i], compare_ints);

        printf("\nEstrutura atual da arvore (deitada):\n");
        print_tree(root, print_int);
        printf("\n----------------------------------------\n\n");
    }


    tree_free(root);
    return 0;
}

/*
    APS 1: Os alunos deverão construir um software que seja capaz de realizar e representar as operações (inserir, remover,
    percorrer{sinalizando qual é o nó atual}) em uma estrutura de dados não linear (à escolha dos alunos). Esta representação deverá ser visual
    para que o usuário do sistema consiga perceber a movimentação que está acontecendo na árvore (passo a passo).
    APS 2: Os alunos deverão utilizar a APS1 para construir uma nova opção em um menu onde será necessário realizar a construção e
    visualização de um grafo a partir de uma matriz de adjacência. Além disto nesta representação deve ser capaz de ser representado o peso
    de cada aresta e calcular o caminho mínimo.

    Desafio 1: Usando a APS1 os alunos deverão gerar árvores de diversos tamanhos e realizar comparativos entre as formas de busca dentro
    da estrutura para levantar uma relação de desempenho de cada forma de busca.
    Desafio 2: Simular a função de um GPS para calcular a melhor rota baseado em tempo ou baseado em distância ou baseado em menos
    pedágios ou um mix personalizado disso.
 */
