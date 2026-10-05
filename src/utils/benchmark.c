#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "ds.h"

void run_benchmark(void) {
    clear_screen();
    printf("=============================================================\n");
    printf("        DESAFIO 1: RELATORIO DE DESEMPENHO DE BUSCAS         \n");
    printf("=============================================================\n\n");

    int sizes[] = {1000, 10000, 100000, 1000000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("| N. Elementos | Busca AVL (O(log N)) | Busca Linear (O(N)) |\n");
    printf("|--------------|----------------------|---------------------|\n");

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        BinaryTree* bench_root = NULL;

        int* data_array = (int*) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            data_array[j] = j * 2;
            bench_root = tree_insert(bench_root, &data_array[j], compare_ints);
        }

        int target_val = (n - 1) * 2;

        clock_t start_avl = clock();
        tree_search_avl(bench_root, &target_val, compare_ints);
        clock_t end_avl = clock();
        double time_avl_us = ((double)(end_avl - start_avl) / CLOCKS_PER_SEC) * 1000000.0;

        double time_linear_us = 0.0;
        if (n <= 100000) {
            clock_t start_lin = clock();
            tree_search_linear(bench_root, &target_val, compare_ints);
            clock_t end_lin = clock();
            time_linear_us = ((double)(end_lin - start_lin) / CLOCKS_PER_SEC) * 1000000.0;
            printf("| %-12d | %-17.2f us | %-16.2f us |\n", n, time_avl_us, time_linear_us);
        } else {
            printf("| %-12d | %-17.2f us | %-19s |\n", n, time_avl_us, "Muito lento (>1s)");
        }

        tree_free(bench_root);
        free(data_array);
    }

    printf("\nPressione Enter para voltar ao menu...");
    getchar(); getchar();
}
