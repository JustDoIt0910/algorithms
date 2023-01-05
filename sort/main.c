//
// Created by zr on 23-1-5.
//
#include "sort.h"
#include <stdio.h>

int main()
{
    int a[] = {3, 6, 8, 7, 9, 1, 10, 2};
    merge_sort_v1(a, 0, 7);
    for (int i = 0; i < 8; ++i)
        printf("%d ", a[i]);

    printf("\n");
    int a2[] = {3, 6, 8, 7, 9, 1, 10, 2};
    merge_sort_v2(a2, 0, 7);
    for (int i = 0; i < 8; ++i)
        printf("%d ", a[i]);
}