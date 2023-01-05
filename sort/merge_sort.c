//
// Created by zr on 23-1-5.
//
#include "sort.h"
#include <stdlib.h>

//来自algorithms 4中的实现

void merge(elem_t a[], int lo, int mid, int hi, elem_t* aux)
{
    int i = lo;
    int j = mid + 1;
    for(int k = lo; k <= hi; k++)
        aux[k] = a[k];
    for(int k = lo; k <= hi; k++)
    {
        //i > mid, 左侧子数组添加完了，从右侧子数组中取元素
        if(i > mid) a[k] = aux[j++];
        //j > hi, 右侧子数组添加完了，从左侧子数组中取元素
        else if(j > hi) a[k] = aux[i++];
        //两侧都没用完，取小的一边
        else if(aux[i] > aux[j]) a[k] = aux[j++];
        else a[k] = aux[i++];
    }
}

void _merge_sort_v1(elem_t a[], int lo, int hi, elem_t* aux)
{
    if(hi <= lo)
        return;
    int mid = (hi + lo) / 2;
    _merge_sort_v1(a, lo, mid, aux);
    _merge_sort_v1(a, mid + 1, hi, aux);
    merge(a, lo, mid, hi, aux);
}

void merge_sort_v1(elem_t a[], int lo, int hi)
{
    int len = hi - lo + 1;
    elem_t* aux = (elem_t*)malloc(len * sizeof(elem_t));
    _merge_sort_v1(a, lo, hi, aux);
    free(aux);
}

void merge_sort_v2(elem_t a[], int lo, int hi)
{
    int len = hi - lo + 1;
    elem_t* aux = (elem_t*)malloc(len * sizeof(elem_t));
    for(int sz = 1; sz < len; sz *= 2)
    {
        for(int _lo = 0; _lo < len - sz; _lo += 2 * sz)
            merge(a, _lo, _lo + sz - 1, min(_lo + 2 * sz - 1, len - 1), aux);
    }
    free(aux);
}