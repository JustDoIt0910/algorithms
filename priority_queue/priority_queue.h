//
// Created by zr on 22-12-30.
//
#include "common.h"

#ifndef ALGORITHMS_PRIORITY_QUEUE_H
#define ALGORITHMS_PRIORITY_QUEUE_H

//max pq
typedef struct PriorityQueue
{
    elem_t* pq;
    int N;

    METHOD(void) (*insert) (struct PriorityQueue*, elem_t);
    METHOD(elem_t) (*delMax) (struct PriorityQueue*);
} PriorityQueue;

GLOBAL(PriorityQueue*) priority_queue_create(int);
GLOBAL(void) priority_queue_destroy(PriorityQueue*);

#endif //ALGORITHMS_PRIORITY_QUEUE_H
