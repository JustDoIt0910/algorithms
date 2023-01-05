//
// Created by zr on 22-12-30.
//
#include "priority_queue.h"
#include <stdio.h>

int main()
{
    PriorityQueue* pq = priority_queue_create(10);
    pq->insert(pq, 9);
    pq->insert(pq, 3);
    pq->insert(pq, 0);
    pq->insert(pq, 10);
    pq->insert(pq, 7);
    printf("%d\n", pq->delMax(pq));
    printf("%d\n", pq->delMax(pq));
    printf("%d\n", pq->delMax(pq));
    priority_queue_destroy(pq);
}