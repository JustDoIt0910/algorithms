//
// Created by zr on 23-1-5.
//

#ifndef ALGORITHM_SORT_H
#define ALGORITHM_SORT_H

#include "common.h"

//自顶向下
void mergesort_v1(elem_t a[], int lo, int hi);

//自底向上
void mergesort_v2(elem_t a[], int lo, int hi);

void quicksort(elem_t a[], int lo, int hi);

#endif //ALGORITHM_SORT_H
