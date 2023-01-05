//
// Created by zr on 22-12-30.
//
#include "priority_queue.h"
#include <stdlib.h>

LOCAL(bool)
less(PriorityQueue* this, elem_t a, elem_t b)
{
    return this->pq[a] < this->pq[b];
}

LOCAL(void)
exch(PriorityQueue* this, int i, int j)
{
    elem_t t = this->pq[i];
    this->pq[i] = this->pq[j];
    this->pq[j] = t;
}

LOCAL(void)
swim(PriorityQueue* this, int k)
{
    while(k > 1 && less(this, k / 2, k))
    {
        exch(this, k / 2, k);
        k = k / 2;
    }
}

LOCAL(void)
sink(PriorityQueue* this, int k)
{
    while(2 * k <= this->N)
    {
        int j = 2 * k;
        if(j < this->N && less(this, j, j + 1))
            j += 1;
        if(!less(this, k, j))
            break;
        exch(this, k, j);
        k = j;
    }
}

METHODDEF(void)
insert(PriorityQueue* this, elem_t v)
{
    this->pq[++this->N] = v;
    swim(this, this->N);
}

METHODDEF(elem_t)
delMax(PriorityQueue* this)
{
    elem_t max = this->pq[1];
    exch(this, 1, this->N--);
    sink(this, 1);
    return max;
}

GLOBAL(PriorityQueue*)
priority_queue_create(int maxn)
{
    PriorityQueue* maxPQ = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    maxPQ->pq = (elem_t*) malloc((maxn + 1) * sizeof(elem_t));
    maxPQ->N = 0;
    maxPQ->insert = insert;
    maxPQ->delMax = delMax;
    return maxPQ;
}

GLOBAL(void)
priority_queue_destroy(PriorityQueue* maxPQ)
{
    if(maxPQ && maxPQ->pq)
        free(maxPQ->pq);
    if(maxPQ)
        free(maxPQ);
}