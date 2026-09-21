#include "utils.h"

int compare_ints(const void* a, const void* b) {
    int int_a = *(const int*)a;
    int int_b = *(const int*)b;

    return int_a - int_b;
    // Se int_a < int_b, retorna negativo (< 0)
    // Se int_a == int_b, retorna 0
    // Se int_a > int_b, retorna positivo (> 0)
}


