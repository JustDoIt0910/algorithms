//
// Created by zr on 23-1-5.
//
#include "sort.h"
#include <stdlib.h>

//来自algorithms 4中的实现

//********************** merge sort ********************************

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

void mergesort_v1(elem_t a[], int lo, int hi)
{
    int len = hi - lo + 1;
    elem_t* aux = (elem_t*)malloc(len * sizeof(elem_t));
    _merge_sort_v1(a, lo, hi, aux);
    free(aux);
}

void mergesort_v2(elem_t a[], int lo, int hi)
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

//********************** quick sort ********************************

void swap(elem_t* a, int i, int j)
{
    int t = a[j];
    a[j] = a[i];
    a[i] = t;
}

int partition(elem_t a[], int lo, int hi)
{
    int i = lo; int j = hi + 1;
    elem_t v = a[lo];
    while(true)
    {
        while (a[++i] < v)
            if (i == hi)
                break;
        while (a[--j] > v)
            if (j == lo)
                break;
        if(i >= j)
            break;
        swap(a, i, j);
    }
    swap(a, lo, j);
    return j;
}

void quicksort(elem_t a[], int lo, int hi)
{
    if(hi <= lo)
        return;
    int p = partition(a, lo, hi);
    quicksort(a, lo, p - 1);
    quicksort(a, p + 1, hi);
}

//********************** heap sort ********************************

void sink(elem_t* a, int k, int N)
{
    while(2 * k + 1 <= N - 1)
    {
        int j = 2 * k + 1;
        if(j < N - 1 && a[j] < a[j + 1])
            j++;
        if(a[k] >= a[j])
            break;
        swap(a, k, j);
        k = j;
    }
}

void heapsort(elem_t a[], int N)
{
    for(int k = N / 2 - 1; k >= 0; k--)
        sink(a, k, N);
    int end = N - 1;
    while(end > 0)
    {
        swap(a, 0, end--);
        sink(a, 0, end);
    }
}