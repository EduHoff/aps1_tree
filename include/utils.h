#pragma once

#include "ds.h"
#ifndef COMPARE_FN_DEFINED
#define COMPARE_FN_DEFINED
typedef int (*CompareFn)(const void* a, const void* b);
#endif

void clear_screen(void);

int compare_ints(const void* a, const void* b);

typedef void (*PrintFn)(const void* data);
void print_tree(BinaryTree* root, PrintFn print_data);
void print_int(const void* data);